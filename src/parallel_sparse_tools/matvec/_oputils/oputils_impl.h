#ifndef __OPUTILS_IMPL_H__
#define __OPUTILS_IMPL_H__

#include "numpy/ndarrayobject.h"
#include "numpy/ndarraytypes.h"

inline bool EquivTypes(PyArray_Descr * dtype1,PyArray_Descr * dtype2){
	return PyArray_EquivTypes(dtype1,dtype2);
}


#include <iostream>

int get_switch_num(PyArray_Descr * dtype1,PyArray_Descr * dtype2,PyArray_Descr * dtype3,PyArray_Descr * dtype4){
	int I = dtype1->type_num;
	int T1 = dtype2->type_num;
	int T2 = dtype3->type_num;
	int T3 = dtype4->type_num;
	
	if(0){}
	else if(PyArray_EquivTypenums(I,NPY_INT32)){
		 if(0){}
		else if(T1 == NPY_COMPLEX128 && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 0;}
		else if(T1 == NPY_COMPLEX128 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 1;}
		else if(T1 == NPY_COMPLEX128 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 2;}
		else if(T1 == NPY_COMPLEX128 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 3;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 4;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 5;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 6;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 7;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 8;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT64){return 9;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 10;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 11;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 12;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX64){return 13;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 14;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX64){return 15;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 16;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 17;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 18;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 19;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX64){return 20;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 21;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT64){return 22;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX64){return 23;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT32){return 24;}
		else {return -1;}
	}
	else if(PyArray_EquivTypenums(I,NPY_INT64)){
		 if(0){}
		else if(T1 == NPY_COMPLEX128 && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 25;}
		else if(T1 == NPY_COMPLEX128 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 26;}
		else if(T1 == NPY_COMPLEX128 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 27;}
		else if(T1 == NPY_COMPLEX128 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 28;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 29;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 30;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 31;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 32;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 33;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT64){return 34;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 35;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 36;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 37;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX64){return 38;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 39;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX64){return 40;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 41;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 42;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 43;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 44;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX64){return 45;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 46;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT64){return 47;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX64){return 48;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT32){return 49;}
		else {return -1;}
	}
	else {return -1;}

	return -1;
}

#include "csr.h"

void csr_matvec_gil(const int switch_num,
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
{
	switch(switch_num){
		case 0 :
			csr_matvec_noomp<npy_int32,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 1 :
			csr_matvec_noomp<npy_int32,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 2 :
			csr_matvec_noomp<npy_int32,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 3 :
			csr_matvec_noomp<npy_int32,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 4 :
			csr_matvec_noomp<npy_int32,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 5 :
			csr_matvec_noomp<npy_int32,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 6 :
			csr_matvec_noomp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 7 :
			csr_matvec_noomp<npy_int32,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 8 :
			csr_matvec_noomp<npy_int32,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 9 :
			csr_matvec_noomp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 10 :
			csr_matvec_noomp<npy_int32,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 11 :
			csr_matvec_noomp<npy_int32,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 12 :
			csr_matvec_noomp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 13 :
			csr_matvec_noomp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 14 :
			csr_matvec_noomp<npy_int32,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 15 :
			csr_matvec_noomp<npy_int32,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 16 :
			csr_matvec_noomp<npy_int32,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 17 :
			csr_matvec_noomp<npy_int32,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 18 :
			csr_matvec_noomp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 19 :
			csr_matvec_noomp<npy_int32,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 20 :
			csr_matvec_noomp<npy_int32,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 21 :
			csr_matvec_noomp<npy_int32,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 22 :
			csr_matvec_noomp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 23 :
			csr_matvec_noomp<npy_int32,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 24 :
			csr_matvec_noomp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 25 :
			csr_matvec_noomp<npy_int64,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 26 :
			csr_matvec_noomp<npy_int64,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 27 :
			csr_matvec_noomp<npy_int64,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 28 :
			csr_matvec_noomp<npy_int64,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 29 :
			csr_matvec_noomp<npy_int64,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 30 :
			csr_matvec_noomp<npy_int64,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 31 :
			csr_matvec_noomp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 32 :
			csr_matvec_noomp<npy_int64,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 33 :
			csr_matvec_noomp<npy_int64,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 34 :
			csr_matvec_noomp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 35 :
			csr_matvec_noomp<npy_int64,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 36 :
			csr_matvec_noomp<npy_int64,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 37 :
			csr_matvec_noomp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 38 :
			csr_matvec_noomp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 39 :
			csr_matvec_noomp<npy_int64,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 40 :
			csr_matvec_noomp<npy_int64,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 41 :
			csr_matvec_noomp<npy_int64,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 42 :
			csr_matvec_noomp<npy_int64,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 43 :
			csr_matvec_noomp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 44 :
			csr_matvec_noomp<npy_int64,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 45 :
			csr_matvec_noomp<npy_int64,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 46 :
			csr_matvec_noomp<npy_int64,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 47 :
			csr_matvec_noomp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 48 :
			csr_matvec_noomp<npy_int64,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 49 :
			csr_matvec_noomp<npy_int64,float,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}
}

void csr_matvec_nogil(const int switch_num,
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
{
	switch(switch_num){
		case 0 :
			csr_matvec_omp<npy_int32,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 1 :
			csr_matvec_omp<npy_int32,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 2 :
			csr_matvec_omp<npy_int32,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 3 :
			csr_matvec_omp<npy_int32,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 4 :
			csr_matvec_omp<npy_int32,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 5 :
			csr_matvec_omp<npy_int32,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 6 :
			csr_matvec_omp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 7 :
			csr_matvec_omp<npy_int32,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 8 :
			csr_matvec_omp<npy_int32,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 9 :
			csr_matvec_omp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 10 :
			csr_matvec_omp<npy_int32,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 11 :
			csr_matvec_omp<npy_int32,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 12 :
			csr_matvec_omp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 13 :
			csr_matvec_omp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 14 :
			csr_matvec_omp<npy_int32,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 15 :
			csr_matvec_omp<npy_int32,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 16 :
			csr_matvec_omp<npy_int32,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 17 :
			csr_matvec_omp<npy_int32,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 18 :
			csr_matvec_omp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 19 :
			csr_matvec_omp<npy_int32,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 20 :
			csr_matvec_omp<npy_int32,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 21 :
			csr_matvec_omp<npy_int32,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 22 :
			csr_matvec_omp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 23 :
			csr_matvec_omp<npy_int32,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 24 :
			csr_matvec_omp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 25 :
			csr_matvec_omp<npy_int64,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 26 :
			csr_matvec_omp<npy_int64,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 27 :
			csr_matvec_omp<npy_int64,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 28 :
			csr_matvec_omp<npy_int64,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 29 :
			csr_matvec_omp<npy_int64,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 30 :
			csr_matvec_omp<npy_int64,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 31 :
			csr_matvec_omp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 32 :
			csr_matvec_omp<npy_int64,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 33 :
			csr_matvec_omp<npy_int64,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 34 :
			csr_matvec_omp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 35 :
			csr_matvec_omp<npy_int64,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 36 :
			csr_matvec_omp<npy_int64,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 37 :
			csr_matvec_omp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 38 :
			csr_matvec_omp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 39 :
			csr_matvec_omp<npy_int64,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 40 :
			csr_matvec_omp<npy_int64,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 41 :
			csr_matvec_omp<npy_int64,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 42 :
			csr_matvec_omp<npy_int64,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 43 :
			csr_matvec_omp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 44 :
			csr_matvec_omp<npy_int64,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 45 :
			csr_matvec_omp<npy_int64,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 46 :
			csr_matvec_omp<npy_int64,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 47 :
			csr_matvec_omp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 48 :
			csr_matvec_omp<npy_int64,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 49 :
			csr_matvec_omp<npy_int64,float,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}
}

void csr_matvecs_gil(const int switch_num,
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
{
	switch(switch_num){
		case 0 :
			csr_matvecs_noomp<npy_int32,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 1 :
			csr_matvecs_noomp<npy_int32,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 2 :
			csr_matvecs_noomp<npy_int32,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 3 :
			csr_matvecs_noomp<npy_int32,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 4 :
			csr_matvecs_noomp<npy_int32,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 5 :
			csr_matvecs_noomp<npy_int32,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 6 :
			csr_matvecs_noomp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 7 :
			csr_matvecs_noomp<npy_int32,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 8 :
			csr_matvecs_noomp<npy_int32,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 9 :
			csr_matvecs_noomp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 10 :
			csr_matvecs_noomp<npy_int32,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 11 :
			csr_matvecs_noomp<npy_int32,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 12 :
			csr_matvecs_noomp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 13 :
			csr_matvecs_noomp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 14 :
			csr_matvecs_noomp<npy_int32,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 15 :
			csr_matvecs_noomp<npy_int32,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 16 :
			csr_matvecs_noomp<npy_int32,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 17 :
			csr_matvecs_noomp<npy_int32,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 18 :
			csr_matvecs_noomp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 19 :
			csr_matvecs_noomp<npy_int32,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 20 :
			csr_matvecs_noomp<npy_int32,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 21 :
			csr_matvecs_noomp<npy_int32,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 22 :
			csr_matvecs_noomp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 23 :
			csr_matvecs_noomp<npy_int32,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 24 :
			csr_matvecs_noomp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 25 :
			csr_matvecs_noomp<npy_int64,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 26 :
			csr_matvecs_noomp<npy_int64,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 27 :
			csr_matvecs_noomp<npy_int64,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 28 :
			csr_matvecs_noomp<npy_int64,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 29 :
			csr_matvecs_noomp<npy_int64,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 30 :
			csr_matvecs_noomp<npy_int64,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 31 :
			csr_matvecs_noomp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 32 :
			csr_matvecs_noomp<npy_int64,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 33 :
			csr_matvecs_noomp<npy_int64,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 34 :
			csr_matvecs_noomp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 35 :
			csr_matvecs_noomp<npy_int64,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 36 :
			csr_matvecs_noomp<npy_int64,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 37 :
			csr_matvecs_noomp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 38 :
			csr_matvecs_noomp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 39 :
			csr_matvecs_noomp<npy_int64,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 40 :
			csr_matvecs_noomp<npy_int64,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 41 :
			csr_matvecs_noomp<npy_int64,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 42 :
			csr_matvecs_noomp<npy_int64,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 43 :
			csr_matvecs_noomp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 44 :
			csr_matvecs_noomp<npy_int64,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 45 :
			csr_matvecs_noomp<npy_int64,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 46 :
			csr_matvecs_noomp<npy_int64,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 47 :
			csr_matvecs_noomp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 48 :
			csr_matvecs_noomp<npy_int64,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 49 :
			csr_matvecs_noomp<npy_int64,float,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}
}

void csr_matvecs_nogil(const int switch_num,
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
{
	switch(switch_num){
		case 0 :
			csr_matvecs_omp<npy_int32,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 1 :
			csr_matvecs_omp<npy_int32,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 2 :
			csr_matvecs_omp<npy_int32,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 3 :
			csr_matvecs_omp<npy_int32,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 4 :
			csr_matvecs_omp<npy_int32,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 5 :
			csr_matvecs_omp<npy_int32,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 6 :
			csr_matvecs_omp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 7 :
			csr_matvecs_omp<npy_int32,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 8 :
			csr_matvecs_omp<npy_int32,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 9 :
			csr_matvecs_omp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 10 :
			csr_matvecs_omp<npy_int32,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 11 :
			csr_matvecs_omp<npy_int32,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 12 :
			csr_matvecs_omp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 13 :
			csr_matvecs_omp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 14 :
			csr_matvecs_omp<npy_int32,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 15 :
			csr_matvecs_omp<npy_int32,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 16 :
			csr_matvecs_omp<npy_int32,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 17 :
			csr_matvecs_omp<npy_int32,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 18 :
			csr_matvecs_omp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 19 :
			csr_matvecs_omp<npy_int32,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 20 :
			csr_matvecs_omp<npy_int32,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 21 :
			csr_matvecs_omp<npy_int32,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 22 :
			csr_matvecs_omp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 23 :
			csr_matvecs_omp<npy_int32,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 24 :
			csr_matvecs_omp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 25 :
			csr_matvecs_omp<npy_int64,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 26 :
			csr_matvecs_omp<npy_int64,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 27 :
			csr_matvecs_omp<npy_int64,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 28 :
			csr_matvecs_omp<npy_int64,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 29 :
			csr_matvecs_omp<npy_int64,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 30 :
			csr_matvecs_omp<npy_int64,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 31 :
			csr_matvecs_omp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 32 :
			csr_matvecs_omp<npy_int64,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 33 :
			csr_matvecs_omp<npy_int64,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 34 :
			csr_matvecs_omp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 35 :
			csr_matvecs_omp<npy_int64,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 36 :
			csr_matvecs_omp<npy_int64,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 37 :
			csr_matvecs_omp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 38 :
			csr_matvecs_omp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 39 :
			csr_matvecs_omp<npy_int64,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 40 :
			csr_matvecs_omp<npy_int64,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 41 :
			csr_matvecs_omp<npy_int64,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 42 :
			csr_matvecs_omp<npy_int64,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 43 :
			csr_matvecs_omp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 44 :
			csr_matvecs_omp<npy_int64,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 45 :
			csr_matvecs_omp<npy_int64,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 46 :
			csr_matvecs_omp<npy_int64,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 47 :
			csr_matvecs_omp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 48 :
			csr_matvecs_omp<npy_int64,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 49 :
			csr_matvecs_omp<npy_int64,float,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}
}

#include "csc.h"

void csc_matvec_gil(const int switch_num,
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
{
	switch(switch_num){
		case 0 :
			csc_matvec_noomp<npy_int32,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 1 :
			csc_matvec_noomp<npy_int32,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 2 :
			csc_matvec_noomp<npy_int32,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 3 :
			csc_matvec_noomp<npy_int32,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 4 :
			csc_matvec_noomp<npy_int32,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 5 :
			csc_matvec_noomp<npy_int32,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 6 :
			csc_matvec_noomp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 7 :
			csc_matvec_noomp<npy_int32,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 8 :
			csc_matvec_noomp<npy_int32,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 9 :
			csc_matvec_noomp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 10 :
			csc_matvec_noomp<npy_int32,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 11 :
			csc_matvec_noomp<npy_int32,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 12 :
			csc_matvec_noomp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 13 :
			csc_matvec_noomp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 14 :
			csc_matvec_noomp<npy_int32,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 15 :
			csc_matvec_noomp<npy_int32,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 16 :
			csc_matvec_noomp<npy_int32,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 17 :
			csc_matvec_noomp<npy_int32,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 18 :
			csc_matvec_noomp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 19 :
			csc_matvec_noomp<npy_int32,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 20 :
			csc_matvec_noomp<npy_int32,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 21 :
			csc_matvec_noomp<npy_int32,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 22 :
			csc_matvec_noomp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 23 :
			csc_matvec_noomp<npy_int32,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 24 :
			csc_matvec_noomp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 25 :
			csc_matvec_noomp<npy_int64,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 26 :
			csc_matvec_noomp<npy_int64,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 27 :
			csc_matvec_noomp<npy_int64,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 28 :
			csc_matvec_noomp<npy_int64,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 29 :
			csc_matvec_noomp<npy_int64,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 30 :
			csc_matvec_noomp<npy_int64,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 31 :
			csc_matvec_noomp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 32 :
			csc_matvec_noomp<npy_int64,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 33 :
			csc_matvec_noomp<npy_int64,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 34 :
			csc_matvec_noomp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 35 :
			csc_matvec_noomp<npy_int64,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 36 :
			csc_matvec_noomp<npy_int64,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 37 :
			csc_matvec_noomp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 38 :
			csc_matvec_noomp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 39 :
			csc_matvec_noomp<npy_int64,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 40 :
			csc_matvec_noomp<npy_int64,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 41 :
			csc_matvec_noomp<npy_int64,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 42 :
			csc_matvec_noomp<npy_int64,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 43 :
			csc_matvec_noomp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 44 :
			csc_matvec_noomp<npy_int64,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 45 :
			csc_matvec_noomp<npy_int64,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 46 :
			csc_matvec_noomp<npy_int64,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 47 :
			csc_matvec_noomp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 48 :
			csc_matvec_noomp<npy_int64,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 49 :
			csc_matvec_noomp<npy_int64,float,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}
}

void csc_matvec_nogil(const int switch_num,
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
{
	switch(switch_num){
		case 0 :
			csc_matvec_omp<npy_int32,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 1 :
			csc_matvec_omp<npy_int32,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 2 :
			csc_matvec_omp<npy_int32,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 3 :
			csc_matvec_omp<npy_int32,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 4 :
			csc_matvec_omp<npy_int32,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 5 :
			csc_matvec_omp<npy_int32,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 6 :
			csc_matvec_omp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 7 :
			csc_matvec_omp<npy_int32,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 8 :
			csc_matvec_omp<npy_int32,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 9 :
			csc_matvec_omp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 10 :
			csc_matvec_omp<npy_int32,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 11 :
			csc_matvec_omp<npy_int32,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 12 :
			csc_matvec_omp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 13 :
			csc_matvec_omp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 14 :
			csc_matvec_omp<npy_int32,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 15 :
			csc_matvec_omp<npy_int32,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 16 :
			csc_matvec_omp<npy_int32,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 17 :
			csc_matvec_omp<npy_int32,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 18 :
			csc_matvec_omp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 19 :
			csc_matvec_omp<npy_int32,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 20 :
			csc_matvec_omp<npy_int32,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 21 :
			csc_matvec_omp<npy_int32,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 22 :
			csc_matvec_omp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 23 :
			csc_matvec_omp<npy_int32,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 24 :
			csc_matvec_omp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 25 :
			csc_matvec_omp<npy_int64,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 26 :
			csc_matvec_omp<npy_int64,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 27 :
			csc_matvec_omp<npy_int64,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 28 :
			csc_matvec_omp<npy_int64,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 29 :
			csc_matvec_omp<npy_int64,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 30 :
			csc_matvec_omp<npy_int64,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 31 :
			csc_matvec_omp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 32 :
			csc_matvec_omp<npy_int64,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 33 :
			csc_matvec_omp<npy_int64,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 34 :
			csc_matvec_omp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 35 :
			csc_matvec_omp<npy_int64,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 36 :
			csc_matvec_omp<npy_int64,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 37 :
			csc_matvec_omp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 38 :
			csc_matvec_omp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 39 :
			csc_matvec_omp<npy_int64,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 40 :
			csc_matvec_omp<npy_int64,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 41 :
			csc_matvec_omp<npy_int64,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 42 :
			csc_matvec_omp<npy_int64,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 43 :
			csc_matvec_omp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 44 :
			csc_matvec_omp<npy_int64,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 45 :
			csc_matvec_omp<npy_int64,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 46 :
			csc_matvec_omp<npy_int64,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 47 :
			csc_matvec_omp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 48 :
			csc_matvec_omp<npy_int64,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 49 :
			csc_matvec_omp<npy_int64,float,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}
}

void csc_matvecs_gil(const int switch_num,
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
{
	switch(switch_num){
		case 0 :
			csc_matvecs_noomp<npy_int32,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 1 :
			csc_matvecs_noomp<npy_int32,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 2 :
			csc_matvecs_noomp<npy_int32,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 3 :
			csc_matvecs_noomp<npy_int32,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 4 :
			csc_matvecs_noomp<npy_int32,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 5 :
			csc_matvecs_noomp<npy_int32,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 6 :
			csc_matvecs_noomp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 7 :
			csc_matvecs_noomp<npy_int32,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 8 :
			csc_matvecs_noomp<npy_int32,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 9 :
			csc_matvecs_noomp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 10 :
			csc_matvecs_noomp<npy_int32,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 11 :
			csc_matvecs_noomp<npy_int32,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 12 :
			csc_matvecs_noomp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 13 :
			csc_matvecs_noomp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 14 :
			csc_matvecs_noomp<npy_int32,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 15 :
			csc_matvecs_noomp<npy_int32,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 16 :
			csc_matvecs_noomp<npy_int32,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 17 :
			csc_matvecs_noomp<npy_int32,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 18 :
			csc_matvecs_noomp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 19 :
			csc_matvecs_noomp<npy_int32,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 20 :
			csc_matvecs_noomp<npy_int32,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 21 :
			csc_matvecs_noomp<npy_int32,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 22 :
			csc_matvecs_noomp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 23 :
			csc_matvecs_noomp<npy_int32,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 24 :
			csc_matvecs_noomp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 25 :
			csc_matvecs_noomp<npy_int64,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 26 :
			csc_matvecs_noomp<npy_int64,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 27 :
			csc_matvecs_noomp<npy_int64,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 28 :
			csc_matvecs_noomp<npy_int64,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 29 :
			csc_matvecs_noomp<npy_int64,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 30 :
			csc_matvecs_noomp<npy_int64,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 31 :
			csc_matvecs_noomp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 32 :
			csc_matvecs_noomp<npy_int64,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 33 :
			csc_matvecs_noomp<npy_int64,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 34 :
			csc_matvecs_noomp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 35 :
			csc_matvecs_noomp<npy_int64,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 36 :
			csc_matvecs_noomp<npy_int64,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 37 :
			csc_matvecs_noomp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 38 :
			csc_matvecs_noomp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 39 :
			csc_matvecs_noomp<npy_int64,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 40 :
			csc_matvecs_noomp<npy_int64,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 41 :
			csc_matvecs_noomp<npy_int64,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 42 :
			csc_matvecs_noomp<npy_int64,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 43 :
			csc_matvecs_noomp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 44 :
			csc_matvecs_noomp<npy_int64,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 45 :
			csc_matvecs_noomp<npy_int64,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 46 :
			csc_matvecs_noomp<npy_int64,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 47 :
			csc_matvecs_noomp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 48 :
			csc_matvecs_noomp<npy_int64,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 49 :
			csc_matvecs_noomp<npy_int64,float,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}
}

void csc_matvecs_nogil(const int switch_num,
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
{
	switch(switch_num){
		case 0 :
			csc_matvecs_omp<npy_int32,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 1 :
			csc_matvecs_omp<npy_int32,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 2 :
			csc_matvecs_omp<npy_int32,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 3 :
			csc_matvecs_omp<npy_int32,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cdouble_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 4 :
			csc_matvecs_omp<npy_int32,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 5 :
			csc_matvecs_omp<npy_int32,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 6 :
			csc_matvecs_omp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 7 :
			csc_matvecs_omp<npy_int32,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 8 :
			csc_matvecs_omp<npy_int32,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 9 :
			csc_matvecs_omp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 10 :
			csc_matvecs_omp<npy_int32,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 11 :
			csc_matvecs_omp<npy_int32,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 12 :
			csc_matvecs_omp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 13 :
			csc_matvecs_omp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 14 :
			csc_matvecs_omp<npy_int32,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 15 :
			csc_matvecs_omp<npy_int32,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 16 :
			csc_matvecs_omp<npy_int32,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 17 :
			csc_matvecs_omp<npy_int32,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 18 :
			csc_matvecs_omp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 19 :
			csc_matvecs_omp<npy_int32,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 20 :
			csc_matvecs_omp<npy_int32,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 21 :
			csc_matvecs_omp<npy_int32,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 22 :
			csc_matvecs_omp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 23 :
			csc_matvecs_omp<npy_int32,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 24 :
			csc_matvecs_omp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 25 :
			csc_matvecs_omp<npy_int64,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 26 :
			csc_matvecs_omp<npy_int64,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 27 :
			csc_matvecs_omp<npy_int64,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 28 :
			csc_matvecs_omp<npy_int64,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cdouble_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 29 :
			csc_matvecs_omp<npy_int64,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 30 :
			csc_matvecs_omp<npy_int64,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 31 :
			csc_matvecs_omp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 32 :
			csc_matvecs_omp<npy_int64,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 33 :
			csc_matvecs_omp<npy_int64,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 34 :
			csc_matvecs_omp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 35 :
			csc_matvecs_omp<npy_int64,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 36 :
			csc_matvecs_omp<npy_int64,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 37 :
			csc_matvecs_omp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 38 :
			csc_matvecs_omp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 39 :
			csc_matvecs_omp<npy_int64,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 40 :
			csc_matvecs_omp<npy_int64,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_cfloat_wrapper*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 41 :
			csc_matvecs_omp<npy_int64,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 42 :
			csc_matvecs_omp<npy_int64,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 43 :
			csc_matvecs_omp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 44 :
			csc_matvecs_omp<npy_int64,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 45 :
			csc_matvecs_omp<npy_int64,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 46 :
			csc_matvecs_omp<npy_int64,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 47 :
			csc_matvecs_omp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 48 :
			csc_matvecs_omp<npy_int64,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 49 :
			csc_matvecs_omp<npy_int64,float,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}
}

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
{
	switch(switch_num){
		case 0 :
			dia_matvec_noomp<npy_int32,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cdouble_wrapper*)diags,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 1 :
			dia_matvec_noomp<npy_int32,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cdouble_wrapper*)diags,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 2 :
			dia_matvec_noomp<npy_int32,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cdouble_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 3 :
			dia_matvec_noomp<npy_int32,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cdouble_wrapper*)diags,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 4 :
			dia_matvec_noomp<npy_int32,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 5 :
			dia_matvec_noomp<npy_int32,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 6 :
			dia_matvec_noomp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 7 :
			dia_matvec_noomp<npy_int32,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 8 :
			dia_matvec_noomp<npy_int32,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 9 :
			dia_matvec_noomp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 10 :
			dia_matvec_noomp<npy_int32,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 11 :
			dia_matvec_noomp<npy_int32,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 12 :
			dia_matvec_noomp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 13 :
			dia_matvec_noomp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 14 :
			dia_matvec_noomp<npy_int32,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 15 :
			dia_matvec_noomp<npy_int32,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 16 :
			dia_matvec_noomp<npy_int32,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 17 :
			dia_matvec_noomp<npy_int32,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 18 :
			dia_matvec_noomp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 19 :
			dia_matvec_noomp<npy_int32,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 20 :
			dia_matvec_noomp<npy_int32,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 21 :
			dia_matvec_noomp<npy_int32,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 22 :
			dia_matvec_noomp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 23 :
			dia_matvec_noomp<npy_int32,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 24 :
			dia_matvec_noomp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 25 :
			dia_matvec_noomp<npy_int64,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cdouble_wrapper*)diags,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 26 :
			dia_matvec_noomp<npy_int64,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cdouble_wrapper*)diags,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 27 :
			dia_matvec_noomp<npy_int64,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cdouble_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 28 :
			dia_matvec_noomp<npy_int64,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cdouble_wrapper*)diags,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 29 :
			dia_matvec_noomp<npy_int64,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 30 :
			dia_matvec_noomp<npy_int64,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 31 :
			dia_matvec_noomp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 32 :
			dia_matvec_noomp<npy_int64,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 33 :
			dia_matvec_noomp<npy_int64,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 34 :
			dia_matvec_noomp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 35 :
			dia_matvec_noomp<npy_int64,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 36 :
			dia_matvec_noomp<npy_int64,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 37 :
			dia_matvec_noomp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 38 :
			dia_matvec_noomp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 39 :
			dia_matvec_noomp<npy_int64,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 40 :
			dia_matvec_noomp<npy_int64,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 41 :
			dia_matvec_noomp<npy_int64,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 42 :
			dia_matvec_noomp<npy_int64,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 43 :
			dia_matvec_noomp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 44 :
			dia_matvec_noomp<npy_int64,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 45 :
			dia_matvec_noomp<npy_int64,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 46 :
			dia_matvec_noomp<npy_int64,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 47 :
			dia_matvec_noomp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 48 :
			dia_matvec_noomp<npy_int64,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 49 :
			dia_matvec_noomp<npy_int64,float,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}
}

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
{
	switch(switch_num){
		case 0 :
			dia_matvec_omp<npy_int32,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cdouble_wrapper*)diags,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 1 :
			dia_matvec_omp<npy_int32,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cdouble_wrapper*)diags,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 2 :
			dia_matvec_omp<npy_int32,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cdouble_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 3 :
			dia_matvec_omp<npy_int32,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cdouble_wrapper*)diags,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 4 :
			dia_matvec_omp<npy_int32,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 5 :
			dia_matvec_omp<npy_int32,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 6 :
			dia_matvec_omp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 7 :
			dia_matvec_omp<npy_int32,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 8 :
			dia_matvec_omp<npy_int32,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 9 :
			dia_matvec_omp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 10 :
			dia_matvec_omp<npy_int32,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 11 :
			dia_matvec_omp<npy_int32,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 12 :
			dia_matvec_omp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 13 :
			dia_matvec_omp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 14 :
			dia_matvec_omp<npy_int32,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 15 :
			dia_matvec_omp<npy_int32,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 16 :
			dia_matvec_omp<npy_int32,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 17 :
			dia_matvec_omp<npy_int32,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 18 :
			dia_matvec_omp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 19 :
			dia_matvec_omp<npy_int32,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 20 :
			dia_matvec_omp<npy_int32,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 21 :
			dia_matvec_omp<npy_int32,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 22 :
			dia_matvec_omp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 23 :
			dia_matvec_omp<npy_int32,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 24 :
			dia_matvec_omp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 25 :
			dia_matvec_omp<npy_int64,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cdouble_wrapper*)diags,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 26 :
			dia_matvec_omp<npy_int64,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cdouble_wrapper*)diags,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 27 :
			dia_matvec_omp<npy_int64,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cdouble_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 28 :
			dia_matvec_omp<npy_int64,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cdouble_wrapper*)diags,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 29 :
			dia_matvec_omp<npy_int64,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 30 :
			dia_matvec_omp<npy_int64,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 31 :
			dia_matvec_omp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 32 :
			dia_matvec_omp<npy_int64,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 33 :
			dia_matvec_omp<npy_int64,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 34 :
			dia_matvec_omp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 35 :
			dia_matvec_omp<npy_int64,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 36 :
			dia_matvec_omp<npy_int64,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 37 :
			dia_matvec_omp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 38 :
			dia_matvec_omp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 39 :
			dia_matvec_omp<npy_int64,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 40 :
			dia_matvec_omp<npy_int64,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 41 :
			dia_matvec_omp<npy_int64,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const npy_cdouble_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 42 :
			dia_matvec_omp<npy_int64,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const double*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 43 :
			dia_matvec_omp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 44 :
			dia_matvec_omp<npy_int64,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 45 :
			dia_matvec_omp<npy_int64,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const npy_cfloat_wrapper*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 46 :
			dia_matvec_omp<npy_int64,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const npy_cdouble_wrapper*)x,y_stride_byte,(npy_cdouble_wrapper*)y);
			break;
		case 47 :
			dia_matvec_omp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 48 :
			dia_matvec_omp<npy_int64,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const npy_cfloat_wrapper*)x,y_stride_byte,(npy_cfloat_wrapper*)y);
			break;
		case 49 :
			dia_matvec_omp<npy_int64,float,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}
}

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
{
	switch(switch_num){
		case 0 :
			dia_matvecs_noomp<npy_int32,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cdouble_wrapper*)diags,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 1 :
			dia_matvecs_noomp<npy_int32,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cdouble_wrapper*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 2 :
			dia_matvecs_noomp<npy_int32,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cdouble_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 3 :
			dia_matvecs_noomp<npy_int32,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cdouble_wrapper*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 4 :
			dia_matvecs_noomp<npy_int32,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 5 :
			dia_matvecs_noomp<npy_int32,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 6 :
			dia_matvecs_noomp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 7 :
			dia_matvecs_noomp<npy_int32,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 8 :
			dia_matvecs_noomp<npy_int32,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 9 :
			dia_matvecs_noomp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 10 :
			dia_matvecs_noomp<npy_int32,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 11 :
			dia_matvecs_noomp<npy_int32,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 12 :
			dia_matvecs_noomp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 13 :
			dia_matvecs_noomp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 14 :
			dia_matvecs_noomp<npy_int32,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 15 :
			dia_matvecs_noomp<npy_int32,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 16 :
			dia_matvecs_noomp<npy_int32,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 17 :
			dia_matvecs_noomp<npy_int32,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 18 :
			dia_matvecs_noomp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 19 :
			dia_matvecs_noomp<npy_int32,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 20 :
			dia_matvecs_noomp<npy_int32,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 21 :
			dia_matvecs_noomp<npy_int32,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 22 :
			dia_matvecs_noomp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 23 :
			dia_matvecs_noomp<npy_int32,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 24 :
			dia_matvecs_noomp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 25 :
			dia_matvecs_noomp<npy_int64,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cdouble_wrapper*)diags,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 26 :
			dia_matvecs_noomp<npy_int64,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cdouble_wrapper*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 27 :
			dia_matvecs_noomp<npy_int64,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cdouble_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 28 :
			dia_matvecs_noomp<npy_int64,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cdouble_wrapper*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 29 :
			dia_matvecs_noomp<npy_int64,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 30 :
			dia_matvecs_noomp<npy_int64,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 31 :
			dia_matvecs_noomp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 32 :
			dia_matvecs_noomp<npy_int64,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 33 :
			dia_matvecs_noomp<npy_int64,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 34 :
			dia_matvecs_noomp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 35 :
			dia_matvecs_noomp<npy_int64,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 36 :
			dia_matvecs_noomp<npy_int64,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 37 :
			dia_matvecs_noomp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 38 :
			dia_matvecs_noomp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 39 :
			dia_matvecs_noomp<npy_int64,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 40 :
			dia_matvecs_noomp<npy_int64,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 41 :
			dia_matvecs_noomp<npy_int64,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 42 :
			dia_matvecs_noomp<npy_int64,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 43 :
			dia_matvecs_noomp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 44 :
			dia_matvecs_noomp<npy_int64,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 45 :
			dia_matvecs_noomp<npy_int64,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 46 :
			dia_matvecs_noomp<npy_int64,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 47 :
			dia_matvecs_noomp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 48 :
			dia_matvecs_noomp<npy_int64,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 49 :
			dia_matvecs_noomp<npy_int64,float,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}
}

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
{
	switch(switch_num){
		case 0 :
			dia_matvecs_omp<npy_int32,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cdouble_wrapper*)diags,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 1 :
			dia_matvecs_omp<npy_int32,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cdouble_wrapper*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 2 :
			dia_matvecs_omp<npy_int32,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cdouble_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 3 :
			dia_matvecs_omp<npy_int32,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cdouble_wrapper*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 4 :
			dia_matvecs_omp<npy_int32,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 5 :
			dia_matvecs_omp<npy_int32,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 6 :
			dia_matvecs_omp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 7 :
			dia_matvecs_omp<npy_int32,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 8 :
			dia_matvecs_omp<npy_int32,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 9 :
			dia_matvecs_omp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 10 :
			dia_matvecs_omp<npy_int32,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 11 :
			dia_matvecs_omp<npy_int32,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 12 :
			dia_matvecs_omp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 13 :
			dia_matvecs_omp<npy_int32,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 14 :
			dia_matvecs_omp<npy_int32,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 15 :
			dia_matvecs_omp<npy_int32,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_cfloat_wrapper*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 16 :
			dia_matvecs_omp<npy_int32,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 17 :
			dia_matvecs_omp<npy_int32,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 18 :
			dia_matvecs_omp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 19 :
			dia_matvecs_omp<npy_int32,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 20 :
			dia_matvecs_omp<npy_int32,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 21 :
			dia_matvecs_omp<npy_int32,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 22 :
			dia_matvecs_omp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 23 :
			dia_matvecs_omp<npy_int32,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 24 :
			dia_matvecs_omp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 25 :
			dia_matvecs_omp<npy_int64,npy_cdouble_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cdouble_wrapper*)diags,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 26 :
			dia_matvecs_omp<npy_int64,npy_cdouble_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cdouble_wrapper*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 27 :
			dia_matvecs_omp<npy_int64,npy_cdouble_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cdouble_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 28 :
			dia_matvecs_omp<npy_int64,npy_cdouble_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cdouble_wrapper*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 29 :
			dia_matvecs_omp<npy_int64,double,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 30 :
			dia_matvecs_omp<npy_int64,double,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 31 :
			dia_matvecs_omp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 32 :
			dia_matvecs_omp<npy_int64,double,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 33 :
			dia_matvecs_omp<npy_int64,double,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 34 :
			dia_matvecs_omp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 35 :
			dia_matvecs_omp<npy_int64,npy_cfloat_wrapper,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 36 :
			dia_matvecs_omp<npy_int64,npy_cfloat_wrapper,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 37 :
			dia_matvecs_omp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 38 :
			dia_matvecs_omp<npy_int64,npy_cfloat_wrapper,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 39 :
			dia_matvecs_omp<npy_int64,npy_cfloat_wrapper,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 40 :
			dia_matvecs_omp<npy_int64,npy_cfloat_wrapper,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_cfloat_wrapper*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 41 :
			dia_matvecs_omp<npy_int64,float,npy_cdouble_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const npy_cdouble_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 42 :
			dia_matvecs_omp<npy_int64,float,double,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 43 :
			dia_matvecs_omp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 44 :
			dia_matvecs_omp<npy_int64,float,npy_cfloat_wrapper,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 45 :
			dia_matvecs_omp<npy_int64,float,npy_cfloat_wrapper,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const npy_cfloat_wrapper*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 46 :
			dia_matvecs_omp<npy_int64,float,float,npy_cdouble_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cdouble_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cdouble_wrapper*)y);
			break;
		case 47 :
			dia_matvecs_omp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 48 :
			dia_matvecs_omp<npy_int64,float,float,npy_cfloat_wrapper>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const npy_cfloat_wrapper*)x,y_stride_row_byte,y_stride_col_byte,(npy_cfloat_wrapper*)y);
			break;
		case 49 :
			dia_matvecs_omp<npy_int64,float,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}
}
#endif