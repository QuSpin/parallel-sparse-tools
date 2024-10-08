# cython: language_level=2
# cython: linetrace=True
# distutils: define_macros=CYTHON_TRACE_NOGIL=1
# distutils: language=c++
cimport numpy as np
import cython
from cython.parallel cimport parallel
from libcpp cimport bool
from libcpp.vector cimport vector
import scipy.sparse as _sp
import numpy as _np
from numpy cimport npy_intp,PyArray_Descr,ndarray,import_array


import_array()


cdef extern from "oputils_impl.h": # generated by script generate_oputils.py
  int get_switch_num(PyArray_Descr*,PyArray_Descr*,PyArray_Descr*,PyArray_Descr*) 

  #csr 

  void csr_matvec_gil(const int,const bool,const npy_intp,const npy_intp,void*,void*,void*,void*,
    const npy_intp,void*,const npy_intp,void*) nogil

  void csr_matvec_nogil(const int,const bool,const npy_intp,const npy_intp,void*,void*,void*,void*,
    const npy_intp,void*,const npy_intp,void*) nogil

  void csr_matvecs_gil(const int,const bool,const npy_intp,const npy_intp,const npy_intp,void*,void*,void*,void*,
    const npy_intp,const npy_intp,void*,const npy_intp,const npy_intp,void*) nogil

  void csr_matvecs_nogil(const int,const bool,const npy_intp,const npy_intp,const npy_intp,void*,void*,void*,void*,
    const npy_intp,const npy_intp,void*,const npy_intp,const npy_intp,void*) nogil

  # csc
  void csc_matvec_gil(const int,const bool,const npy_intp,const npy_intp,void*,void*,void*,void*,
    const npy_intp,void*,const npy_intp,void*) nogil

  void csc_matvec_nogil(const int,const bool,const npy_intp,const npy_intp,void*,void*,void*,void*,
    const npy_intp,void*,const npy_intp,void*) nogil

  void csc_matvecs_gil(const int,const bool,const npy_intp,const npy_intp,const npy_intp,void*,void*,void*,void*,
    const npy_intp,const npy_intp,void*,const npy_intp,const npy_intp,void*) nogil

  void csc_matvecs_nogil(const int,const bool,const npy_intp,const npy_intp,const npy_intp,void*,void*,void*,void*,
    const npy_intp,const npy_intp,void*,const npy_intp,const npy_intp,void*) nogil

  # dia
  void dia_matvec_gil(const int, const bool,const npy_intp,const npy_intp,const npy_intp,const npy_intp,
                   void *,void *,void *,const npy_intp,void *,const npy_intp,void *) nogil

  void dia_matvec_nogil(const int, const bool,const npy_intp,const npy_intp,const npy_intp,const npy_intp,
                   void *,void *,void *,const npy_intp,void *,const npy_intp,void *) nogil

  void dia_matvecs_gil(const int, const bool,const npy_intp,const npy_intp,const npy_intp,const npy_intp,const npy_intp,
                   void *,void *,void *,const npy_intp,const npy_intp,void *,const npy_intp,const npy_intp,void *) nogil

  void dia_matvecs_nogil(const int, const bool,const npy_intp,const npy_intp,const npy_intp,const npy_intp,const npy_intp,
                   void *,void *,void *,const npy_intp,const npy_intp,void *,const npy_intp,const npy_intp,void *) nogil



DEF MAX_NOGIL=100

cdef void _csr_matvec(bool overwrite_y, ndarray Ap,ndarray Aj, ndarray Ax,ndarray a,ndarray Xx,ndarray Yx) except *:
  cdef PyArray_Descr * dtype1 = np.PyArray_DESCR(Ap)
  cdef PyArray_Descr * dtype2 = np.PyArray_DESCR(Ax)
  cdef PyArray_Descr * dtype3 = np.PyArray_DESCR(a)
  cdef PyArray_Descr * dtype4 = np.PyArray_DESCR(Yx)
  cdef npy_intp ys = np.PyArray_STRIDE(Yx,0)
  cdef npy_intp xs = np.PyArray_STRIDE(Xx,0)
  cdef int switch_num = get_switch_num(dtype1,dtype2,dtype3,dtype4)
  cdef void * Ap_ptr = np.PyArray_DATA(Ap)
  cdef void * Aj_ptr = np.PyArray_DATA(Aj)
  cdef void * Ax_ptr = np.PyArray_DATA(Ax)
  cdef void * Xx_ptr = np.PyArray_DATA(Xx)
  cdef void * Yx_ptr = np.PyArray_DATA(Yx)
  cdef void * a_ptr  = np.PyArray_DATA(a)
  cdef npy_intp nr = np.PyArray_DIM(Yx,0)
  cdef npy_intp nc = np.PyArray_DIM(Xx,0)

  if switch_num < 0:
    raise TypeError("invalid types")

  if nr < MAX_NOGIL:
    csr_matvec_gil(switch_num,overwrite_y,nr,nc,Ap_ptr,Aj_ptr,Ax_ptr,a_ptr,xs,Xx_ptr,ys,Yx_ptr)
  else:
    with nogil: # uses openmp if QuSpin build against openmp.
      csr_matvec_nogil(switch_num,overwrite_y,nr,nc,Ap_ptr,Aj_ptr,Ax_ptr,a_ptr,xs,Xx_ptr,ys,Yx_ptr)

cdef void _csr_matvecs(bool overwrite_y, ndarray Ap,ndarray Aj, ndarray Ax,ndarray a,ndarray Xx,ndarray Yx) except *:
  cdef PyArray_Descr * dtype1 = np.PyArray_DESCR(Ap)
  cdef PyArray_Descr * dtype2 = np.PyArray_DESCR(Ax)
  cdef PyArray_Descr * dtype3 = np.PyArray_DESCR(a)
  cdef PyArray_Descr * dtype4 = np.PyArray_DESCR(Yx)
  cdef npy_intp ysr = np.PyArray_STRIDE(Yx,0)
  cdef npy_intp xsr = np.PyArray_STRIDE(Xx,0)
  cdef npy_intp ysc = np.PyArray_STRIDE(Yx,1)
  cdef npy_intp xsc = np.PyArray_STRIDE(Xx,1)
  cdef int switch_num = get_switch_num(dtype1,dtype2,dtype3,dtype4)
  cdef void * Ap_ptr = np.PyArray_DATA(Ap)
  cdef void * Aj_ptr = np.PyArray_DATA(Aj)
  cdef void * Ax_ptr = np.PyArray_DATA(Ax)
  cdef void * Xx_ptr = np.PyArray_DATA(Xx)
  cdef void * Yx_ptr = np.PyArray_DATA(Yx)
  cdef void * a_ptr  = np.PyArray_DATA(a)
  cdef npy_intp nr = np.PyArray_DIM(Yx,0)
  cdef npy_intp nc = np.PyArray_DIM(Xx,0)
  cdef npy_intp nv = np.PyArray_DIM(Yx,1)

  if switch_num < 0:
    raise TypeError("invalid types")

  if nr < MAX_NOGIL:
    csr_matvecs_gil(switch_num,overwrite_y,nr,nc,nv,Ap_ptr,Aj_ptr,Ax_ptr,a_ptr,xsr,xsc,Xx_ptr,ysr,ysc,Yx_ptr)
  else:
    with nogil: # uses openmp if QuSpin build against openmp.
      csr_matvecs_nogil(switch_num,overwrite_y,nr,nc,nv,Ap_ptr,Aj_ptr,Ax_ptr,a_ptr,xsr,xsc,Xx_ptr,ysr,ysc,Yx_ptr)


cdef void _csc_matvec(bool overwrite_y, ndarray Ap,ndarray Aj, ndarray Ax,ndarray a,ndarray Xx,ndarray Yx) except *:
  cdef PyArray_Descr * dtype1 = np.PyArray_DESCR(Ap)
  cdef PyArray_Descr * dtype2 = np.PyArray_DESCR(Ax)
  cdef PyArray_Descr * dtype3 = np.PyArray_DESCR(a)
  cdef PyArray_Descr * dtype4 = np.PyArray_DESCR(Yx)
  cdef npy_intp ys = np.PyArray_STRIDE(Yx,0)
  cdef npy_intp xs = np.PyArray_STRIDE(Xx,0)
  cdef int switch_num = get_switch_num(dtype1,dtype2,dtype3,dtype4)
  cdef void * Ap_ptr = np.PyArray_DATA(Ap)
  cdef void * Aj_ptr = np.PyArray_DATA(Aj)
  cdef void * Ax_ptr = np.PyArray_DATA(Ax)
  cdef void * Xx_ptr = np.PyArray_DATA(Xx)
  cdef void * Yx_ptr = np.PyArray_DATA(Yx)
  cdef void * a_ptr  = np.PyArray_DATA(a)
  cdef npy_intp nr = np.PyArray_DIM(Yx,0)
  cdef npy_intp nc = np.PyArray_DIM(Xx,0)

  if switch_num < 0:
    raise TypeError("invalid types")

  if nr < MAX_NOGIL:
    csc_matvec_gil(switch_num,overwrite_y,nr,nc,Ap_ptr,Aj_ptr,Ax_ptr,a_ptr,xs,Xx_ptr,ys,Yx_ptr)
  else:
    with nogil: # uses openmp if QuSpin build against openmp.
      csc_matvec_nogil(switch_num,overwrite_y,nr,nc,Ap_ptr,Aj_ptr,Ax_ptr,a_ptr,xs,Xx_ptr,ys,Yx_ptr)

cdef void _csc_matvecs(bool overwrite_y, ndarray Ap,ndarray Aj, ndarray Ax,ndarray a,ndarray Xx,ndarray Yx) except *:
  cdef PyArray_Descr * dtype1 = np.PyArray_DESCR(Ap)
  cdef PyArray_Descr * dtype2 = np.PyArray_DESCR(Ax)
  cdef PyArray_Descr * dtype3 = np.PyArray_DESCR(a)
  cdef PyArray_Descr * dtype4 = np.PyArray_DESCR(Yx)
  cdef npy_intp ysr = np.PyArray_STRIDE(Yx,0)
  cdef npy_intp xsr = np.PyArray_STRIDE(Xx,0)
  cdef npy_intp ysc = np.PyArray_STRIDE(Yx,1)
  cdef npy_intp xsc = np.PyArray_STRIDE(Xx,1)
  cdef int switch_num = get_switch_num(dtype1,dtype2,dtype3,dtype4)
  cdef void * Ap_ptr = np.PyArray_DATA(Ap)
  cdef void * Aj_ptr = np.PyArray_DATA(Aj)
  cdef void * Ax_ptr = np.PyArray_DATA(Ax)
  cdef void * Xx_ptr = np.PyArray_DATA(Xx)
  cdef void * Yx_ptr = np.PyArray_DATA(Yx)
  cdef void * a_ptr  = np.PyArray_DATA(a)
  cdef npy_intp nr = np.PyArray_DIM(Yx,0)
  cdef npy_intp nc = np.PyArray_DIM(Xx,0)
  cdef npy_intp nv = np.PyArray_DIM(Yx,1)

  # print(ysr,ysc,xsr,xsc)
  if switch_num < 0:
    raise TypeError("invalid types")

  if nr < MAX_NOGIL:
    csc_matvecs_gil(switch_num,overwrite_y,nr,nc,nv,Ap_ptr,Aj_ptr,Ax_ptr,a_ptr,xsr,xsc,Xx_ptr,ysr,ysc,Yx_ptr)
  else:
    with nogil: # uses openmp if QuSpin build against openmp.
      csc_matvecs_nogil(switch_num,overwrite_y,nr,nc,nv,Ap_ptr,Aj_ptr,Ax_ptr,a_ptr,xsr,xsc,Xx_ptr,ysr,ysc,Yx_ptr)


cdef void _dia_matvec(bool overwrite_y, ndarray offsets ,ndarray diags, ndarray a, ndarray Xx, ndarray Yx) except *:
  cdef PyArray_Descr * dtype1 = np.PyArray_DESCR(offsets)
  cdef PyArray_Descr * dtype2 = np.PyArray_DESCR(diags)
  cdef PyArray_Descr * dtype3 = np.PyArray_DESCR(a)
  cdef PyArray_Descr * dtype4 = np.PyArray_DESCR(Yx)
  cdef npy_intp ys = np.PyArray_STRIDE(Yx,0)
  cdef npy_intp xs = np.PyArray_STRIDE(Xx,0)
  cdef int switch_num = get_switch_num(dtype1,dtype2,dtype3,dtype4)
  cdef void * diags_ptr = np.PyArray_DATA(diags)
  cdef void * offsets_ptr = np.PyArray_DATA(offsets)
  cdef void * Xx_ptr = np.PyArray_DATA(Xx)
  cdef void * Yx_ptr = np.PyArray_DATA(Yx)
  cdef void * a_ptr  = np.PyArray_DATA(a)
  cdef npy_intp nr = np.PyArray_DIM(Yx,0)
  cdef npy_intp nc = np.PyArray_DIM(Xx,0)
  cdef npy_intp nd = np.PyArray_DIM(diags,0)
  cdef npy_intp L  = np.PyArray_DIM(diags,1)

  if switch_num < 0:
    raise TypeError("invalid types")

  if nr < MAX_NOGIL:
    dia_matvec_gil(switch_num,overwrite_y,nr,nc,nd,L,offsets_ptr,diags_ptr,a_ptr,xs,Xx_ptr,ys,Yx_ptr)
  else:
    with nogil: # uses openmp if QuSpin build against openmp.
      dia_matvec_nogil(switch_num,overwrite_y,nr,nc,nd,L,offsets_ptr,diags_ptr,a_ptr,xs,Xx_ptr,ys,Yx_ptr)

cdef void _dia_matvecs(bool overwrite_y, ndarray offsets ,ndarray diags, ndarray a, ndarray Xx, ndarray Yx) except *:
  cdef PyArray_Descr * dtype1 = np.PyArray_DESCR(offsets)
  cdef PyArray_Descr * dtype2 = np.PyArray_DESCR(diags)
  cdef PyArray_Descr * dtype3 = np.PyArray_DESCR(a)
  cdef PyArray_Descr * dtype4 = np.PyArray_DESCR(Yx)
  cdef npy_intp ysr = np.PyArray_STRIDE(Yx,0)
  cdef npy_intp xsr = np.PyArray_STRIDE(Xx,0)
  cdef npy_intp ysc = np.PyArray_STRIDE(Yx,1)
  cdef npy_intp xsc = np.PyArray_STRIDE(Xx,1)
  cdef int switch_num = get_switch_num(dtype1,dtype2,dtype3,dtype4)
  cdef void * diags_ptr = np.PyArray_DATA(diags)
  cdef void * offsets_ptr = np.PyArray_DATA(offsets)
  cdef void * Xx_ptr = np.PyArray_DATA(Xx)
  cdef void * Yx_ptr = np.PyArray_DATA(Yx)
  cdef void * a_ptr  = np.PyArray_DATA(a)
  cdef npy_intp nr = np.PyArray_DIM(Yx,0)
  cdef npy_intp nc = np.PyArray_DIM(Xx,0)
  cdef npy_intp nd = np.PyArray_DIM(diags,0)
  cdef npy_intp L  = np.PyArray_DIM(diags,1)
  cdef npy_intp nv = np.PyArray_DIM(Yx,1)

  if switch_num < 0:
    raise TypeError("invalid types")

  if nr < MAX_NOGIL:
    dia_matvecs_gil(switch_num,overwrite_y,nr,nc,nv,nd,L,offsets_ptr,diags_ptr,a_ptr,xsr,xsc,Xx_ptr,ysr,ysc,Yx_ptr)
  else:
    with nogil: # uses openmp if QuSpin build against openmp.
      dia_matvecs_nogil(switch_num,overwrite_y,nr,nc,nv,nd,L,offsets_ptr,diags_ptr,a_ptr,xsr,xsc,Xx_ptr,ysr,ysc,Yx_ptr)


def _prep_objects(mat_obj, other, overwrite_out, out, a):
  a_dtype = _np.result_type(_np.float32, _np.min_scalar_type(a))
  result_dtype = _np.result_type(mat_obj.dtype, a_dtype, other.dtype)
  a = _np.array(a, dtype=result_dtype)
  if out is None:
    overwrite_out = True
    out = _np.zeros(mat_obj.shape[:1]+other.shape[1:], dtype=result_dtype, order="C")

  return mat_obj, other.astype(out.dtype), overwrite_out, out, a, result_dtype

def _process_args(mat_obj, other, overwrite_out, out, a):
  mat_obj, other, overwrite_out, out, a, result_dtype = _prep_objects(mat_obj, other, overwrite_out, out, a)

  expected_shape = mat_obj.shape[:1]+other.shape[1:]
  if out.dtype != other.dtype:
      raise ValueError(
          "Incorrect dtype for out array. found: "
          f"{out.dtype}, expected: {result_dtype}"
      )

  if out.shape != out.shape:
      raise ValueError(
          "Dimension mismatch between out array and result of matrix-vector product. "
          f"matrix.shape: {mat_obj.shape}, "
          f"vector.shape: {other.shape}, "
          f"out.shape: {out.shape}"
          )

  return mat_obj, other, overwrite_out, out, a

def _csr_dot(mat_obj,other,overwrite_out=False,out=None,a=1.0):
  mat_obj, other, overwrite_out, out, a, _ = _prep_objects(mat_obj, other, overwrite_out, out, a)
  if other.ndim == 1:
    _csr_matvec(overwrite_out,mat_obj.indptr,mat_obj.indices,mat_obj.data,a,other,out)
  else:
    _csr_matvecs(overwrite_out,mat_obj.indptr,mat_obj.indices,mat_obj.data,a,other,out)

  return out


def _csc_dot(mat_obj,other,overwrite_out=False,out=None,a=1.0):
  mat_obj, other, overwrite_out, out, a, _ = _prep_objects(mat_obj, other, overwrite_out, out, a)

  if other.ndim == 1:
    _csc_matvec(overwrite_out,mat_obj.indptr,mat_obj.indices,mat_obj.data,a,other,out)
  else:
    _csc_matvecs(overwrite_out,mat_obj.indptr,mat_obj.indices,mat_obj.data,a,other,out)

  return out


def _dia_dot(mat_obj,other,overwrite_out=False,out=None,a=1.0):
  mat_obj, other, overwrite_out, out, a, _ = _prep_objects(mat_obj, other, overwrite_out, out, a)

  if other.ndim == 1:
    _dia_matvec(overwrite_out,mat_obj.offsets,mat_obj.data,a,other,out)
  else:
    _dia_matvecs(overwrite_out,mat_obj.offsets,mat_obj.data,a,other,out)

  return out


def _other_dot(mat_obj,other,overwrite_out=False,out=None,a=1.0):
  mat_obj, other, overwrite_out, out, a, _ = _prep_objects(mat_obj, other, overwrite_out, out, a)

  inter_res = mat_obj.dot(other)

  if overwrite_out:
    _np.multiply(a,inter_res,out=out)
  else:
    try:
      inter_res *= a
      out += inter_res
    except TypeError:
      out += a * inter_res

  return out


def _matvec(mat_obj,*args,**kwargs):
  if _sp.isspmatrix_csr(mat_obj):
    return _csr_dot(mat_obj,*args,**kwargs)
  elif _sp.isspmatrix_csc(mat_obj):
    return _csc_dot(mat_obj,*args,**kwargs)
  elif _sp.isspmatrix_dia(mat_obj):
    return _dia_dot(mat_obj,*args,**kwargs)
  else:
    return _other_dot(mat_obj,*args,**kwargs)


def _get_matvec_function(mat_obj):
  if _sp.isspmatrix_csr(mat_obj):
    return _csr_dot
  elif _sp.isspmatrix_csc(mat_obj):
    return _csc_dot
  elif _sp.isspmatrix_dia(mat_obj):
    return _dia_dot
  else:
    return _other_dot
