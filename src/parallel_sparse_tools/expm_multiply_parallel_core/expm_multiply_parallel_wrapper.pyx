# cython: language_level=2
# cython: linetrace=True
# distutils: define_macros=CYTHON_TRACE_NOGIL=1
# distutils: language=c++
cimport cython
cimport numpy as _np
from numpy cimport ndarray,PyArray_Descr,PyArrayObject,npy_intp
from libcpp cimport bool
import numpy as _np
import scipy.sparse as _sp

_np.import_array()

ctypedef float complex floatcomplex
ctypedef double complex doublecomplex

ctypedef fused indtype:
	_np.int32_t
	_np.int64_t

ctypedef fused indtype_B:
	_np.int32_t
	_np.int64_t

ctypedef fused T1:
	_np.int8_t
	_np.int16_t
	float
	float complex
	double
	double complex

ctypedef fused T2:
	float
	float complex
	double
	double complex



cdef extern from "csr_utils.h":
	T csr_trace[I,T](const I,const I,const I[],const I[],const T[]) nogil
	double csr_1_norm[I,T](const I,const I,const I[],const I[],const double complex,const T[]) nogil
	# npy_intp csr_shift_diag_pass1[I,T](const T,const I,const I,const I[],const I[],T[]) nogil
	# void csr_shift_diag_pass2[I,J,T](const T,const I,const I,const I[],const I[],
	# 	const T[],J[],J[],T[]) nogil





@cython.boundscheck(False)
def _wrapper_csr_trace(indtype[:] indptr, indtype[:] indices, T1[:] data):
	cdef indtype n_row = indptr.shape[0] - 1
	return csr_trace(n_row,n_row,&indptr[0],&indices[0],&data[0])

@cython.boundscheck(False)
def _wrapper_csr_1_norm(indtype[:] indptr, indtype[:] indices, T1[:] data,mu):
	cdef indtype n_row = indptr.shape[0] - 1
	cdef double complex mu_in = mu
	return csr_1_norm(n_row,n_row,&indptr[0],&indices[0],mu_in,&data[0])


cdef extern from "expm_multiply_parallel_impl.h":
	int get_switch_expm_multiply(PyArray_Descr*,PyArray_Descr*,PyArray_Descr*,PyArray_Descr*)
	bool EquivTypes(PyArray_Descr*,PyArray_Descr*)

	void expm_multiply_impl(const int,const npy_intp,void*,void*,void*,
		const int,const int,void*,void*,void*,void*,void*) nogil

	void expm_multiply_batch_impl(const int,const npy_intp,const npy_intp,
		void*,void*,void*,const int,const int,void*,void*,void*,void*,void*) nogil

cdef inline bool not_well_defined_input(ndarray arr,npy_intp ndim):
	return (not _np.PyArray_ISALIGNED(arr)) or (_np.PyArray_NDIM(arr)!=ndim);


cdef inline bool not_well_defined_output(ndarray arr,npy_intp ndim):
	return (not _np.PyArray_ISCARRAY(arr)) or (_np.PyArray_NDIM(arr)!=ndim)


def _wrapper_expm_multiply(ndarray indptr,ndarray indices,ndarray data,int s,int m_star,
							ndarray tol,ndarray mu,ndarray a,ndarray v,ndarray work):
	cdef PyArray_Descr * indptr_dtype = _np.PyArray_DESCR(indptr)
	cdef PyArray_Descr * indices_dtype = _np.PyArray_DESCR(indices)
	cdef PyArray_Descr * data_dtype = _np.PyArray_DESCR(data)
	cdef PyArray_Descr * a_dtype = _np.PyArray_DESCR(a)
	cdef PyArray_Descr * tol_dtype = _np.PyArray_DESCR(tol)
	cdef PyArray_Descr * mu_dtype = _np.PyArray_DESCR(mu)
	cdef PyArray_Descr * v_dtype = _np.PyArray_DESCR(v)
	cdef PyArray_Descr * work_dtype = _np.PyArray_DESCR(work)
	cdef void * Ap_ptr = _np.PyArray_DATA(indptr)
	cdef void * Aj_ptr = _np.PyArray_DATA(indices)
	cdef void * Ax_ptr = _np.PyArray_DATA(data)
	cdef void * a_ptr = _np.PyArray_DATA(a)
	cdef void * tol_ptr = _np.PyArray_DATA(tol)
	cdef void * mu_ptr = _np.PyArray_DATA(mu)
	cdef void * v_ptr = _np.PyArray_DATA(v)
	cdef void * work_ptr = _np.PyArray_DATA(work)
	cdef npy_intp n_row = _np.PyArray_DIM(indptr,0) - 1
	cdef int switch_num = get_switch_expm_multiply(indptr_dtype,data_dtype,tol_dtype,v_dtype) # I, T1, T2, T3
	cdef bool arg_fail = False

	arg_fail = arg_fail or (switch_num < 0)
	arg_fail = arg_fail or (not EquivTypes(indptr_dtype,indices_dtype))
	arg_fail = arg_fail or (not EquivTypes(a_dtype,mu_dtype))
	arg_fail = arg_fail or (not EquivTypes(a_dtype,v_dtype))
	arg_fail = arg_fail or (not EquivTypes(v_dtype,work_dtype))

	arg_fail = arg_fail or not_well_defined_input(indptr,1)
	arg_fail = arg_fail or not_well_defined_input(indices,1)
	arg_fail = arg_fail or not_well_defined_input(data,1)
	arg_fail = arg_fail or not_well_defined_input(a,0)
	arg_fail = arg_fail or not_well_defined_input(mu,0)
	arg_fail = arg_fail or not_well_defined_output(v,1)
	arg_fail = arg_fail or not_well_defined_output(work,1)

	if not arg_fail:
		with nogil:
			expm_multiply_impl(switch_num,n_row,Ap_ptr,Aj_ptr,Ax_ptr,s,m_star,tol_ptr,mu_ptr,a_ptr,v_ptr,work_ptr)

	else:
		raise TypeError("invalid arguments to _wrapper_expm_multiply.")




def _wrapper_expm_multiply_batch(ndarray indptr,ndarray indices,ndarray data,int s,int m_star,
								ndarray tol,ndarray mu,ndarray a,ndarray v,ndarray work):
	cdef PyArray_Descr * indptr_dtype = _np.PyArray_DESCR(indptr)
	cdef PyArray_Descr * indices_dtype = _np.PyArray_DESCR(indices)
	cdef PyArray_Descr * data_dtype = _np.PyArray_DESCR(data)
	cdef PyArray_Descr * a_dtype = _np.PyArray_DESCR(a)
	cdef PyArray_Descr * tol_dtype = _np.PyArray_DESCR(tol)
	cdef PyArray_Descr * mu_dtype = _np.PyArray_DESCR(mu)
	cdef PyArray_Descr * v_dtype = _np.PyArray_DESCR(v)
	cdef PyArray_Descr * work_dtype = _np.PyArray_DESCR(work)
	cdef void * Ap_ptr = _np.PyArray_DATA(indptr)
	cdef void * Aj_ptr = _np.PyArray_DATA(indices)
	cdef void * Ax_ptr = _np.PyArray_DATA(data)
	cdef void * a_ptr = _np.PyArray_DATA(a)
	cdef void * tol_ptr = _np.PyArray_DATA(tol)
	cdef void * mu_ptr = _np.PyArray_DATA(mu)
	cdef void * v_ptr = _np.PyArray_DATA(v)
	cdef void * work_ptr = _np.PyArray_DATA(work)
	cdef npy_intp n_row = _np.PyArray_DIM(indptr,0) - 1
	cdef npy_intp n_vecs = _np.PyArray_DIM(v,1)
	cdef int switch_num = get_switch_expm_multiply(indptr_dtype,data_dtype,tol_dtype,v_dtype) # I, T1, T2, T3
	cdef bool arg_fail = False

	arg_fail = arg_fail or (switch_num < 0)
	arg_fail = arg_fail or (not EquivTypes(indptr_dtype,indices_dtype))
	arg_fail = arg_fail or (not EquivTypes(a_dtype,mu_dtype))
	arg_fail = arg_fail or (not EquivTypes(a_dtype,v_dtype))
	arg_fail = arg_fail or (not EquivTypes(v_dtype,work_dtype))

	arg_fail = arg_fail or not_well_defined_input(indptr,1)
	arg_fail = arg_fail or not_well_defined_input(indices,1)
	arg_fail = arg_fail or not_well_defined_input(data,1)
	arg_fail = arg_fail or not_well_defined_input(a,0)
	arg_fail = arg_fail or not_well_defined_input(mu,0)
	arg_fail = arg_fail or not_well_defined_output(v,2)
	arg_fail = arg_fail or not_well_defined_output(work,2)

	if not arg_fail:
		with nogil:
			expm_multiply_batch_impl(switch_num,n_row,n_vecs,Ap_ptr,Aj_ptr,Ax_ptr,s,m_star,tol_ptr,mu_ptr,a_ptr,v_ptr,work_ptr)

	else:
		raise TypeError("invalid arguments to _wrapper_expm_multiply.")

