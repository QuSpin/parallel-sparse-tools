import itertools
import numpy as np
from numpy import int8, int16, int32, int64, float32, float64, complex64, complex128
import os


numpy_ctypes = {
    float32: "float",
    float64: "double",
    complex64: "cfloat",
    complex128: "cdouble",
    int32: "npy_int32",
    int64: "npy_int64",
    int8: "npy_int8",
    int16: "npy_int16",
}

numpy_numtypes = {
    float32: "NPY_FLOAT32",
    float64: "NPY_FLOAT64",
    complex64: "NPY_COMPLEX64",
    complex128: "NPY_COMPLEX128",
    int32: "NPY_INT32",
    int64: "NPY_INT64",
    int16: "NPY_INT16",
    int8: "NPY_INT8",
}


I_types = [int32, int64]
T_types = [int8, int16, int32, int64, complex128, float64, complex64, float32]
F_types = [complex128, float64, complex64, float32]

# dtype1: indices dtype
# dtype2: matrix dtype
# dtype3: scalar dtype
# dtype4: vector dtype

get_switch_body = """
#include <iostream>

int get_switch_num(PyArray_Descr * dtype1,PyArray_Descr * dtype2,PyArray_Descr * dtype3,PyArray_Descr * dtype4){{
	int I = dtype1->type_num;
	int T1 = dtype2->type_num;
	int T2 = dtype3->type_num;
	int T3 = dtype4->type_num;
	
	{}
	return -1;
}}"""

# Vectors are the same type for input and output
# This is to reduce the number of combinations
# We can always cast the input to the appropriate
# type for the output with no loss of precision
# and with little overhead.

def get_eq(name, T):
    if T in [int8, int16, int32, int64]:
        return f"PyArray_EquivTypenums({name},{numpy_numtypes[T]})"
    else:
        return f"{name} == {numpy_numtypes[T]}"

def generate_get_switch():
    # T1: matrix dtype
    # T2: 'a' dtype
    # T3: output/input vector dtype
    switches = []
    switch_num = 0
    body = "if(0){}\n"
    for I in I_types:
        body = (
            body
            + "\telse if(PyArray_EquivTypenums(I,{})){{\n\t\t if(0){{}}\n".format(
                numpy_numtypes[I]
            )
        )
        for T1, T2, T3 in itertools.product(T_types, F_types, F_types):
            R = np.result_type(T1, T2, T3)
            if R.char == np.dtype(T3).char:
                switches.append((switch_num, I, T1, T2, T3))
                checks = [get_eq("T1", T1), get_eq("T2", T2), get_eq("T3", T3)]
                get_eqs = " && ".join([x for x in checks if x is not None])
                body = (
                    body
                    + "\t\telse if({}){{return {};}}\n".format(
                        get_eqs,
                        switch_num,
                    )
                )
                switch_num += 1

        body = body + "\t\telse {return -1;}\n\t}\n"
    body = body + "\telse {return -1;}\n"

    return switches, get_switch_body.format(body)


comp_body = """

#include "{fmt}.h"

void {fmt}_matvec_gil(const int switch_num,
					const bool overwrite_y,
					const npy_intp n_row,
					const npy_intp n_col,
						  void * Ap,
						  void * Aj,
						  void * Ax,
						  void * a,
					const npy_intp x_stride_byte,
						  void * x,
					const npy_intp y_stride_byte,
						  void * y)
{{
	switch(switch_num){{{matvec_gil_body:}
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}}
}}

void {fmt}_matvec_nogil(const int switch_num,
					  const bool overwrite_y,
					  const npy_intp n_row,
					  const npy_intp n_col,
						    void * Ap,
						    void * Aj,
						    void * Ax,
						    void * a,
					  const npy_intp x_stride_byte,
						    void * x,
					  const npy_intp y_stride_byte,
						    void * y)
{{
	switch(switch_num){{{matvec_nogil_body:}
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}}
}}

void {fmt}_matvecs_gil(const int switch_num,
					  const bool overwrite_y,
					  const npy_intp n_row,
					  const npy_intp n_col,
					  const npy_intp n_vecs,
						    void * Ap,
						    void * Aj,
						    void * Ax,
						    void * a,
					  const npy_intp x_stride_row_byte,
					  const npy_intp x_stride_col_byte,
						    void * x,
					  const npy_intp y_stride_row_byte,
					  const npy_intp y_stride_col_byte,
						    void * y)
{{
	switch(switch_num){{{matvecs_gil_body:}
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}}
}}

void {fmt}_matvecs_nogil(const int switch_num,
					  const bool overwrite_y,
					  const npy_intp n_row,
					  const npy_intp n_col,
					  const npy_intp n_vecs,
						    void * Ap,
						    void * Aj,
						    void * Ax,
						    void * a,
					  const npy_intp x_stride_row_byte,
					  const npy_intp x_stride_col_byte,
						    void * x,
					  const npy_intp y_stride_row_byte,
					  const npy_intp y_stride_col_byte,
						    void * y)
{{
	switch(switch_num){{{matvecs_nogil_body:}
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}}
}}"""


def generate_csr(switches):
    switch_num = 0
    matvec_gil_body = ""
    matvec_nogil_body = ""
    matvecs_gil_body = ""
    matvecs_nogil_body = ""
    case_tmp = "\n\t\tcase {} :\n\t\t\t{}\n\t\t\tbreak;"
    matvec_tmp = "{fmt}_matvec_{omp}<{I},{T1},{T2},{T3}>(overwrite_y,(const {I})n_row,(const {I})n_col,(const {I}*)Ap,(const {I}*)Aj,(const {T1}*)Ax,*(const {T2}*)a,x_stride_byte,(const {T3}*)x,y_stride_byte,({T3}*)y);"
    matvecs_tmp = "{fmt}_matvecs_{omp}<{I},{T1},{T2},{T3}>(overwrite_y,(const {I})n_row,(const {I})n_col,n_vecs,(const {I}*)Ap,(const {I}*)Aj,(const {T1}*)Ax,*(const {T2}*)a,x_stride_row_byte,x_stride_col_byte,(const {T3}*)x,y_stride_row_byte,y_stride_col_byte,({T3}*)y);"
    for switch_num, I, T1, T2, T3 in switches:
        call = matvec_tmp.format(
            fmt="csr",
            omp="omp",
            I=numpy_ctypes[I],
            T1=numpy_ctypes[T1],
            T2=numpy_ctypes[T2],
            T3=numpy_ctypes[T3],
        )
        matvec_nogil_body = matvec_nogil_body + case_tmp.format(
            switch_num, call
        )

        call = matvec_tmp.format(
            fmt="csr",
            omp="noomp",
            I=numpy_ctypes[I],
            T1=numpy_ctypes[T1],
            T2=numpy_ctypes[T2],
            T3=numpy_ctypes[T3],
        )
        matvec_gil_body = matvec_gil_body + case_tmp.format(
            switch_num, call
        )

        call = matvecs_tmp.format(
            fmt="csr",
            omp="omp",
            I=numpy_ctypes[I],
            T1=numpy_ctypes[T1],
            T2=numpy_ctypes[T2],
            T3=numpy_ctypes[T3],
        )
        matvecs_nogil_body = matvecs_nogil_body + case_tmp.format(
            switch_num, call
        )

        call = matvecs_tmp.format(
            fmt="csr",
            omp="noomp",
            I=numpy_ctypes[I],
            T1=numpy_ctypes[T1],
            T2=numpy_ctypes[T2],
            T3=numpy_ctypes[T3],
        )
        matvecs_gil_body = matvecs_gil_body + case_tmp.format(
            switch_num, call
        )


    return comp_body.format(
        fmt="csr",
        matvec_nogil_body=matvec_nogil_body,
        matvec_gil_body=matvec_gil_body,
        matvecs_nogil_body=matvecs_nogil_body,
        matvecs_gil_body=matvecs_gil_body,
    )


def generate_csc(switches):
    switch_num = 0
    matvec_gil_body = ""
    matvec_nogil_body = ""
    matvecs_gil_body = ""
    matvecs_nogil_body = ""
    case_tmp = "\n\t\tcase {} :\n\t\t\t{}\n\t\t\tbreak;"
    matvec_tmp = "{fmt}_matvec_{omp}<{I},{T1},{T2},{T3}>(overwrite_y,(const {I})n_row,(const {I})n_col,(const {I}*)Ap,(const {I}*)Aj,(const {T1}*)Ax,*(const {T2}*)a,x_stride_byte,(const {T3}*)x,y_stride_byte,({T3}*)y);"
    matvecs_tmp = "{fmt}_matvecs_{omp}<{I},{T1},{T2},{T3}>(overwrite_y,(const {I})n_row,(const {I})n_col,n_vecs,(const {I}*)Ap,(const {I}*)Aj,(const {T1}*)Ax,*(const {T2}*)a,x_stride_row_byte,x_stride_col_byte,(const {T3}*)x,y_stride_row_byte,y_stride_col_byte,({T3}*)y);"
    for switch_num, I, T1, T2, T3 in switches:
        call = matvec_tmp.format(
            fmt="csc",
            omp="omp",
            I=numpy_ctypes[I],
            T1=numpy_ctypes[T1],
            T2=numpy_ctypes[T2],
            T3=numpy_ctypes[T3],
        )
        matvec_nogil_body = matvec_nogil_body + case_tmp.format(
            switch_num, call
        )

        call = matvec_tmp.format(
            fmt="csc",
            omp="noomp",
            I=numpy_ctypes[I],
            T1=numpy_ctypes[T1],
            T2=numpy_ctypes[T2],
            T3=numpy_ctypes[T3],
        )
        matvec_gil_body = matvec_gil_body + case_tmp.format(
            switch_num, call
        )

        call = matvecs_tmp.format(
            fmt="csc",
            omp="omp",
            I=numpy_ctypes[I],
            T1=numpy_ctypes[T1],
            T2=numpy_ctypes[T2],
            T3=numpy_ctypes[T3],
        )
        matvecs_nogil_body = matvecs_nogil_body + case_tmp.format(
            switch_num, call
        )

        call = matvecs_tmp.format(
            fmt="csc",
            omp="noomp",
            I=numpy_ctypes[I],
            T1=numpy_ctypes[T1],
            T2=numpy_ctypes[T2],
            T3=numpy_ctypes[T3],
        )
        matvecs_gil_body = matvecs_gil_body + case_tmp.format(
            switch_num, call
        )


    return comp_body.format(
        fmt="csc",
        matvec_nogil_body=matvec_nogil_body,
        matvec_gil_body=matvec_gil_body,
        matvecs_nogil_body=matvecs_nogil_body,
        matvecs_gil_body=matvecs_gil_body,
    )


dia_body = """

#include "dia.h"

void dia_matvec_gil(const int switch_num,
					const bool overwrite_y,
					const npy_intp n_row,
					const npy_intp n_col,
                    const npy_intp n_diags,
                    const npy_intp L,
						  void * offsets,
						  void * diags,
						  void * a,
					const npy_intp x_stride_byte,
						  void * x,
					const npy_intp y_stride_byte,
						  void * y)
{{
	switch(switch_num){{{matvec_gil_body:}
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}}
}}

void dia_matvec_nogil(const int switch_num,
					  const bool overwrite_y,
					  const npy_intp n_row,
					  const npy_intp n_col,
                      const npy_intp n_diags,
                      const npy_intp L,
						    void * offsets,
						    void * diags,
						    void * a,
					  const npy_intp x_stride_byte,
						    void * x,
					  const npy_intp y_stride_byte,
						    void * y)
{{
	switch(switch_num){{{matvec_nogil_body:}
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}}
}}

void dia_matvecs_gil(const int switch_num,
					 const bool overwrite_y,
					 const npy_intp n_row,
					 const npy_intp n_col,
					 const npy_intp n_vecs,
                     const npy_intp n_diags,
                     const npy_intp L,
						   void * offsets,
						   void * diags,
						   void * a,
					 const npy_intp x_stride_row_byte,
					 const npy_intp x_stride_col_byte,
						   void * x,
					 const npy_intp y_stride_row_byte,
					 const npy_intp y_stride_col_byte,
						   void * y)
{{
	switch(switch_num){{{matvecs_gil_body:}
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}}
}}

void dia_matvecs_nogil(const int switch_num,
					   const bool overwrite_y,
					   const npy_intp n_row,
					   const npy_intp n_col,
					   const npy_intp n_vecs,
                       const npy_intp n_diags,
                       const npy_intp L,
						     void * offsets,
						     void * diags,
						     void * a,
					   const npy_intp x_stride_row_byte,
					   const npy_intp x_stride_col_byte,
						     void * x,
					   const npy_intp y_stride_row_byte,
					   const npy_intp y_stride_col_byte,
						     void * y)
{{
	switch(switch_num){{{matvecs_nogil_body:}
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}}
}}"""


def generate_dia(switches):
    switch_num = 0
    matvec_gil_body = ""
    matvec_nogil_body = ""
    matvecs_gil_body = ""
    matvecs_nogil_body = ""
    case_tmp = "\n\t\tcase {} :\n\t\t\t{}\n\t\t\tbreak;"
    matvec_tmp = "dia_matvec_{omp}<{I},{T1},{T2},{T3}>(overwrite_y,(const {I})n_row,(const {I})n_col,(const {I})n_diags,(const {I})L,(const {I}*)offsets,(const {T1}*)diags,*(const {T2}*)a,x_stride_byte,(const {T3}*)x,y_stride_byte,({T3}*)y);"
    matvecs_tmp = "dia_matvecs_{omp}<{I},{T1},{T2},{T3}>(overwrite_y,(const {I})n_row,(const {I})n_col,n_vecs,(const {I})n_diags,(const {I})L,(const {I}*)offsets,(const {T1}*)diags,*(const {T2}*)a,x_stride_row_byte,x_stride_col_byte,(const {T3}*)x,y_stride_row_byte,y_stride_col_byte,({T3}*)y);"
    for switch_num, I, T1, T2, T3 in switches:
        call = matvec_tmp.format(
            omp="omp",
            I=numpy_ctypes[I],
            T1=numpy_ctypes[T1],
            T2=numpy_ctypes[T2],
            T3=numpy_ctypes[T3],
        )
        matvec_nogil_body = matvec_nogil_body + case_tmp.format(
            switch_num, call
        )

        call = matvec_tmp.format(
            omp="noomp",
            I=numpy_ctypes[I],
            T1=numpy_ctypes[T1],
            T2=numpy_ctypes[T2],
            T3=numpy_ctypes[T3],
        )
        matvec_gil_body = matvec_gil_body + case_tmp.format(
            switch_num, call
        )

        call = matvecs_tmp.format(
            omp="omp",
            I=numpy_ctypes[I],
            T1=numpy_ctypes[T1],
            T2=numpy_ctypes[T2],
            T3=numpy_ctypes[T3],
        )
        matvecs_nogil_body = matvecs_nogil_body + case_tmp.format(
            switch_num, call
        )

        call = matvecs_tmp.format(
            omp="noomp",
            I=numpy_ctypes[I],
            T1=numpy_ctypes[T1],
            T2=numpy_ctypes[T2],
            T3=numpy_ctypes[T3],
        )
        matvecs_gil_body = matvecs_gil_body + case_tmp.format(
            switch_num, call
        )

    return dia_body.format(
        matvec_nogil_body=matvec_nogil_body,
        matvec_gil_body=matvec_gil_body,
        matvecs_nogil_body=matvecs_nogil_body,
        matvecs_gil_body=matvecs_gil_body,
    )


oputils_impl_header = """#ifndef __OPUTILS_IMPL_H__
#define __OPUTILS_IMPL_H__

#include "numpy/ndarrayobject.h"
#include "numpy/ndarraytypes.h"

inline bool EquivTypes(PyArray_Descr * dtype1,PyArray_Descr * dtype2){{
	return PyArray_EquivTypes(dtype1,dtype2);
}}

{header_body}
#endif"""


def generate_oputils():
    switches, header_body = generate_get_switch()
    header_body = header_body + generate_csr(switches)
    header_body = header_body + generate_csc(switches)
    header_body = header_body + generate_dia(switches)
    oputils_impl_header.format(header_body=header_body)
    path = os.path.join(os.path.dirname(__file__), "_oputils", "oputils_impl.h")
    IO = open(path, "w")
    IO.write(oputils_impl_header.format(header_body=header_body))
    IO.close()


if __name__ == "__main__":
    generate_oputils()
