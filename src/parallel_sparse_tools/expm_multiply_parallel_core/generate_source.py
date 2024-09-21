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

real_dtypes = {
    float32: float32,
    float64: float64,
    complex64: float32,
    complex128: float64,
}


I_types = [int32, int64]
T_types = [complex128, float64, complex64, float32, int16, int8]
F_types = [complex128, float64, complex64, float32]


get_switch_body = """

#include <iostream>

int get_switch_expm_multiply(PyArray_Descr * dtype1,PyArray_Descr * dtype2,PyArray_Descr * dtype3,PyArray_Descr * dtype4){{
    int I = dtype1->type_num;
    int T1 = dtype2->type_num;
    int T2 = dtype3->type_num;
    int T3 = dtype4->type_num;
    
    {expm_multiply_body}
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

def generate_get_switch_num():
    switches = []
    switch_num = 0    
    body = "if(0){}\n"
    for I in I_types:
        body = (
            body
            + "\telse if(PyArray_EquivTypenums(I,{})){{\n\t\tif(0){{}}\n".format(
                numpy_numtypes[I]
            )
        )
        for T1, T3 in itertools.product(T_types, F_types):
            if np.can_cast(T1, T3):
                switches.append((switch_num, I, T1, real_dtypes[T3], T3))
                checks = [get_eq("T1", T1), get_eq("T2", real_dtypes[T3]), get_eq("T3", T3)]
                get_eqs = " && ".join(checks)
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

    return switches, get_switch_body.format(expm_multiply_body=body)


expm_multiply_parallel_temp = """

void expm_multiply_impl(const int switch_num,
                        const npy_intp n,
                              void * Ap,
                              void * Aj,
                              void * Ax,
                        const int s,
                        const int m_star,
                              void * tol,
                              void * mu,
                              void * a,
                              void * F,
                              void * work)

{{
    switch(switch_num){{{switch_body:}
        default:
            throw std::runtime_error("internal error: invalid argument typenums");
    }}    
}}"""


def generate_expm_multiply(switches):
    switch_num = 0
    switch_body = ""
    case_tmp = "\n\t\tcase {} :\n\t\t\t{}\n\t\t\tbreak;"
    call_tmp = ("expm_multiply<{I},{T1},{T2},{T3}>("
                "static_cast<const {I}>(n),"
                "reinterpret_cast<const {I}*>(Ap),"
                "reinterpret_cast<const {I}*>(Aj),"
                "reinterpret_cast<const {T1}*>(Ax),"
                "s,"
                "m_star,"
                "*reinterpret_cast<const {T2}*>(tol),"
                "*reinterpret_cast<const {T3}*>(mu),"
                "*reinterpret_cast<const {T3}*>(a),"
                "reinterpret_cast<{T3}*>(F),"
                "reinterpret_cast<{T3}*>(work));")
    for switch_num, I, T1, T2, T3 in switches:
        call = call_tmp.format(
            I=numpy_ctypes[I],
            T1=numpy_ctypes[T1],
            T2=numpy_ctypes[T2],
            T3=numpy_ctypes[T3],
        )
        switch_body = switch_body + case_tmp.format(switch_num, call)

    return expm_multiply_parallel_temp.format(switch_body=switch_body)


expm_multiply_parallel_batch_temp = """

void expm_multiply_batch_impl(const int switch_num,
                        const npy_intp n,
                        const npy_intp n_vecs,
                              void * Ap,
                              void * Aj,
                              void * Ax,
                        const int s,
                        const int m_star,
                              void * tol,
                              void * mu,
                              void * a,
                              void * F,
                              void * work)

{{
    switch(switch_num){{{switch_body:}
        default:
            throw std::runtime_error("internal error: invalid argument typenums");
    }}    
}}"""


def generate_expm_multiply_batch(switches):
    switch_num = 0
    switch_body = ""
    case_tmp = "\n\t\tcase {} :\n\t\t\t{}\n\t\t\tbreak;"
    call_tmp = "expm_multiply_batch<{I},{T1},{T2},{T3}>(static_cast<const {I}>(n),n_vecs,reinterpret_cast<const {I}*>(Ap),reinterpret_cast<const {I}*>(Aj),reinterpret_cast<const {T1}*>(Ax),s,m_star,*reinterpret_cast<const {T2}*>(tol),*reinterpret_cast<const {T3}*>(mu),*reinterpret_cast<const {T3}*>(a),reinterpret_cast<{T3}*>(F),reinterpret_cast<{T3}*>(work));"
    for switch_num, I, T1, T2, T3 in switches:
        call = call_tmp.format(
            I=numpy_ctypes[I],
            T1=numpy_ctypes[T1],
            T2=numpy_ctypes[T2],
            T3=numpy_ctypes[T3],
        )
        switch_body = switch_body + case_tmp.format(switch_num, call)


    return expm_multiply_parallel_batch_temp.format(switch_body=switch_body)


source_impl_header = """#ifndef __EXPM_MULTIPLY_PARALLEL_IMPL_H__
#define __EXPM_MULTIPLY_PARALLEL_IMPL_H__

#include "numpy/ndarrayobject.h"
#include "numpy/ndarraytypes.h"
#include "expm_multiply_parallel.h"

inline bool EquivTypes(PyArray_Descr * dtype1,PyArray_Descr * dtype2){{
	return PyArray_EquivTypes(dtype1,dtype2);
}}

{header_body}
#endif"""


def generate_source():
    switches, header_body = generate_get_switch_num()
    header_body = header_body + generate_expm_multiply(switches)
    header_body = header_body + generate_expm_multiply_batch(switches)
    source_impl_header.format(header_body=header_body)
    path = os.path.join(
        os.path.dirname(__file__), "source", "expm_multiply_parallel_impl.h"
    )
    IO = open(path, "w")
    IO.write(source_impl_header.format(header_body=header_body))
    IO.close()


if __name__ == "__main__":
    generate_source()
