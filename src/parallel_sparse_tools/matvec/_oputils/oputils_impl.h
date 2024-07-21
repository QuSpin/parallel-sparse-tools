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
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 0;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 1;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 2;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 3;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX64){return 4;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 5;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT64){return 6;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX64){return 7;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT32){return 8;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 9;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 10;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 11;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 12;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX64){return 13;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 14;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT64){return 15;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX64){return 16;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT32){return 17;}
		else if(PyArray_EquivTypenums(T1,NPY_INT32) && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 18;}
		else if(PyArray_EquivTypenums(T1,NPY_INT32) && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 19;}
		else if(PyArray_EquivTypenums(T1,NPY_INT32) && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 20;}
		else if(PyArray_EquivTypenums(T1,NPY_INT32) && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 21;}
		else if(PyArray_EquivTypenums(T1,NPY_INT32) && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 22;}
		else if(PyArray_EquivTypenums(T1,NPY_INT32) && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT64){return 23;}
		else if(PyArray_EquivTypenums(T1,NPY_INT64) && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 24;}
		else if(PyArray_EquivTypenums(T1,NPY_INT64) && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 25;}
		else if(PyArray_EquivTypenums(T1,NPY_INT64) && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 26;}
		else if(PyArray_EquivTypenums(T1,NPY_INT64) && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 27;}
		else if(PyArray_EquivTypenums(T1,NPY_INT64) && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 28;}
		else if(PyArray_EquivTypenums(T1,NPY_INT64) && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT64){return 29;}
		else if(T1 == NPY_COMPLEX128 && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 30;}
		else if(T1 == NPY_COMPLEX128 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 31;}
		else if(T1 == NPY_COMPLEX128 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 32;}
		else if(T1 == NPY_COMPLEX128 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 33;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 34;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 35;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 36;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 37;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 38;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT64){return 39;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 40;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 41;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 42;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX64){return 43;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 44;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX64){return 45;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 46;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 47;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 48;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 49;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX64){return 50;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 51;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT64){return 52;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX64){return 53;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT32){return 54;}
		else {return -1;}
	}
	else if(PyArray_EquivTypenums(I,NPY_INT64)){
		 if(0){}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 55;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 56;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 57;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 58;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX64){return 59;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 60;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT64){return 61;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX64){return 62;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT32){return 63;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 64;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 65;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 66;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 67;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX64){return 68;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 69;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT64){return 70;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX64){return 71;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT32){return 72;}
		else if(PyArray_EquivTypenums(T1,NPY_INT32) && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 73;}
		else if(PyArray_EquivTypenums(T1,NPY_INT32) && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 74;}
		else if(PyArray_EquivTypenums(T1,NPY_INT32) && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 75;}
		else if(PyArray_EquivTypenums(T1,NPY_INT32) && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 76;}
		else if(PyArray_EquivTypenums(T1,NPY_INT32) && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 77;}
		else if(PyArray_EquivTypenums(T1,NPY_INT32) && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT64){return 78;}
		else if(PyArray_EquivTypenums(T1,NPY_INT64) && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 79;}
		else if(PyArray_EquivTypenums(T1,NPY_INT64) && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 80;}
		else if(PyArray_EquivTypenums(T1,NPY_INT64) && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 81;}
		else if(PyArray_EquivTypenums(T1,NPY_INT64) && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 82;}
		else if(PyArray_EquivTypenums(T1,NPY_INT64) && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 83;}
		else if(PyArray_EquivTypenums(T1,NPY_INT64) && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT64){return 84;}
		else if(T1 == NPY_COMPLEX128 && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 85;}
		else if(T1 == NPY_COMPLEX128 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 86;}
		else if(T1 == NPY_COMPLEX128 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 87;}
		else if(T1 == NPY_COMPLEX128 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 88;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 89;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 90;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 91;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 92;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 93;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT64){return 94;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 95;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 96;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 97;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX64){return 98;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 99;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX64){return 100;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_COMPLEX128 && T3 == NPY_COMPLEX128){return 101;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 102;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 103;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX128){return 104;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_COMPLEX64 && T3 == NPY_COMPLEX64){return 105;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX128){return 106;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT64){return 107;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX64){return 108;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT32){return 109;}
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
			csr_matvec_noomp<npy_int32,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 1 :
			csr_matvec_noomp<npy_int32,npy_int8,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 2 :
			csr_matvec_noomp<npy_int32,npy_int8,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 3 :
			csr_matvec_noomp<npy_int32,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 4 :
			csr_matvec_noomp<npy_int32,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 5 :
			csr_matvec_noomp<npy_int32,npy_int8,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 6 :
			csr_matvec_noomp<npy_int32,npy_int8,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 7 :
			csr_matvec_noomp<npy_int32,npy_int8,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 8 :
			csr_matvec_noomp<npy_int32,npy_int8,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 9 :
			csr_matvec_noomp<npy_int32,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 10 :
			csr_matvec_noomp<npy_int32,npy_int16,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 11 :
			csr_matvec_noomp<npy_int32,npy_int16,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 12 :
			csr_matvec_noomp<npy_int32,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 13 :
			csr_matvec_noomp<npy_int32,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 14 :
			csr_matvec_noomp<npy_int32,npy_int16,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 15 :
			csr_matvec_noomp<npy_int32,npy_int16,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 16 :
			csr_matvec_noomp<npy_int32,npy_int16,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 17 :
			csr_matvec_noomp<npy_int32,npy_int16,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 18 :
			csr_matvec_noomp<npy_int32,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 19 :
			csr_matvec_noomp<npy_int32,npy_int32,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 20 :
			csr_matvec_noomp<npy_int32,npy_int32,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 21 :
			csr_matvec_noomp<npy_int32,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 22 :
			csr_matvec_noomp<npy_int32,npy_int32,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 23 :
			csr_matvec_noomp<npy_int32,npy_int32,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 24 :
			csr_matvec_noomp<npy_int32,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 25 :
			csr_matvec_noomp<npy_int32,npy_int64,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 26 :
			csr_matvec_noomp<npy_int32,npy_int64,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 27 :
			csr_matvec_noomp<npy_int32,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 28 :
			csr_matvec_noomp<npy_int32,npy_int64,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 29 :
			csr_matvec_noomp<npy_int32,npy_int64,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 30 :
			csr_matvec_noomp<npy_int32,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 31 :
			csr_matvec_noomp<npy_int32,cdouble,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 32 :
			csr_matvec_noomp<npy_int32,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 33 :
			csr_matvec_noomp<npy_int32,cdouble,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 34 :
			csr_matvec_noomp<npy_int32,double,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 35 :
			csr_matvec_noomp<npy_int32,double,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 36 :
			csr_matvec_noomp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 37 :
			csr_matvec_noomp<npy_int32,double,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 38 :
			csr_matvec_noomp<npy_int32,double,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 39 :
			csr_matvec_noomp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 40 :
			csr_matvec_noomp<npy_int32,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 41 :
			csr_matvec_noomp<npy_int32,cfloat,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 42 :
			csr_matvec_noomp<npy_int32,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 43 :
			csr_matvec_noomp<npy_int32,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 44 :
			csr_matvec_noomp<npy_int32,cfloat,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 45 :
			csr_matvec_noomp<npy_int32,cfloat,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 46 :
			csr_matvec_noomp<npy_int32,float,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 47 :
			csr_matvec_noomp<npy_int32,float,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 48 :
			csr_matvec_noomp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 49 :
			csr_matvec_noomp<npy_int32,float,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 50 :
			csr_matvec_noomp<npy_int32,float,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 51 :
			csr_matvec_noomp<npy_int32,float,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 52 :
			csr_matvec_noomp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 53 :
			csr_matvec_noomp<npy_int32,float,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 54 :
			csr_matvec_noomp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 55 :
			csr_matvec_noomp<npy_int64,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 56 :
			csr_matvec_noomp<npy_int64,npy_int8,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 57 :
			csr_matvec_noomp<npy_int64,npy_int8,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 58 :
			csr_matvec_noomp<npy_int64,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 59 :
			csr_matvec_noomp<npy_int64,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 60 :
			csr_matvec_noomp<npy_int64,npy_int8,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 61 :
			csr_matvec_noomp<npy_int64,npy_int8,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 62 :
			csr_matvec_noomp<npy_int64,npy_int8,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 63 :
			csr_matvec_noomp<npy_int64,npy_int8,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 64 :
			csr_matvec_noomp<npy_int64,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 65 :
			csr_matvec_noomp<npy_int64,npy_int16,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 66 :
			csr_matvec_noomp<npy_int64,npy_int16,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 67 :
			csr_matvec_noomp<npy_int64,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 68 :
			csr_matvec_noomp<npy_int64,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 69 :
			csr_matvec_noomp<npy_int64,npy_int16,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 70 :
			csr_matvec_noomp<npy_int64,npy_int16,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 71 :
			csr_matvec_noomp<npy_int64,npy_int16,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 72 :
			csr_matvec_noomp<npy_int64,npy_int16,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 73 :
			csr_matvec_noomp<npy_int64,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 74 :
			csr_matvec_noomp<npy_int64,npy_int32,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 75 :
			csr_matvec_noomp<npy_int64,npy_int32,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 76 :
			csr_matvec_noomp<npy_int64,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 77 :
			csr_matvec_noomp<npy_int64,npy_int32,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 78 :
			csr_matvec_noomp<npy_int64,npy_int32,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 79 :
			csr_matvec_noomp<npy_int64,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 80 :
			csr_matvec_noomp<npy_int64,npy_int64,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 81 :
			csr_matvec_noomp<npy_int64,npy_int64,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 82 :
			csr_matvec_noomp<npy_int64,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 83 :
			csr_matvec_noomp<npy_int64,npy_int64,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 84 :
			csr_matvec_noomp<npy_int64,npy_int64,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 85 :
			csr_matvec_noomp<npy_int64,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 86 :
			csr_matvec_noomp<npy_int64,cdouble,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 87 :
			csr_matvec_noomp<npy_int64,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 88 :
			csr_matvec_noomp<npy_int64,cdouble,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 89 :
			csr_matvec_noomp<npy_int64,double,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 90 :
			csr_matvec_noomp<npy_int64,double,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 91 :
			csr_matvec_noomp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 92 :
			csr_matvec_noomp<npy_int64,double,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 93 :
			csr_matvec_noomp<npy_int64,double,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 94 :
			csr_matvec_noomp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 95 :
			csr_matvec_noomp<npy_int64,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 96 :
			csr_matvec_noomp<npy_int64,cfloat,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 97 :
			csr_matvec_noomp<npy_int64,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 98 :
			csr_matvec_noomp<npy_int64,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 99 :
			csr_matvec_noomp<npy_int64,cfloat,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 100 :
			csr_matvec_noomp<npy_int64,cfloat,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 101 :
			csr_matvec_noomp<npy_int64,float,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 102 :
			csr_matvec_noomp<npy_int64,float,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 103 :
			csr_matvec_noomp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 104 :
			csr_matvec_noomp<npy_int64,float,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 105 :
			csr_matvec_noomp<npy_int64,float,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 106 :
			csr_matvec_noomp<npy_int64,float,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 107 :
			csr_matvec_noomp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 108 :
			csr_matvec_noomp<npy_int64,float,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 109 :
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
			csr_matvec_omp<npy_int32,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 1 :
			csr_matvec_omp<npy_int32,npy_int8,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 2 :
			csr_matvec_omp<npy_int32,npy_int8,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 3 :
			csr_matvec_omp<npy_int32,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 4 :
			csr_matvec_omp<npy_int32,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 5 :
			csr_matvec_omp<npy_int32,npy_int8,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 6 :
			csr_matvec_omp<npy_int32,npy_int8,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 7 :
			csr_matvec_omp<npy_int32,npy_int8,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 8 :
			csr_matvec_omp<npy_int32,npy_int8,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 9 :
			csr_matvec_omp<npy_int32,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 10 :
			csr_matvec_omp<npy_int32,npy_int16,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 11 :
			csr_matvec_omp<npy_int32,npy_int16,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 12 :
			csr_matvec_omp<npy_int32,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 13 :
			csr_matvec_omp<npy_int32,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 14 :
			csr_matvec_omp<npy_int32,npy_int16,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 15 :
			csr_matvec_omp<npy_int32,npy_int16,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 16 :
			csr_matvec_omp<npy_int32,npy_int16,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 17 :
			csr_matvec_omp<npy_int32,npy_int16,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 18 :
			csr_matvec_omp<npy_int32,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 19 :
			csr_matvec_omp<npy_int32,npy_int32,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 20 :
			csr_matvec_omp<npy_int32,npy_int32,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 21 :
			csr_matvec_omp<npy_int32,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 22 :
			csr_matvec_omp<npy_int32,npy_int32,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 23 :
			csr_matvec_omp<npy_int32,npy_int32,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 24 :
			csr_matvec_omp<npy_int32,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 25 :
			csr_matvec_omp<npy_int32,npy_int64,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 26 :
			csr_matvec_omp<npy_int32,npy_int64,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 27 :
			csr_matvec_omp<npy_int32,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 28 :
			csr_matvec_omp<npy_int32,npy_int64,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 29 :
			csr_matvec_omp<npy_int32,npy_int64,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 30 :
			csr_matvec_omp<npy_int32,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 31 :
			csr_matvec_omp<npy_int32,cdouble,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 32 :
			csr_matvec_omp<npy_int32,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 33 :
			csr_matvec_omp<npy_int32,cdouble,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 34 :
			csr_matvec_omp<npy_int32,double,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 35 :
			csr_matvec_omp<npy_int32,double,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 36 :
			csr_matvec_omp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 37 :
			csr_matvec_omp<npy_int32,double,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 38 :
			csr_matvec_omp<npy_int32,double,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 39 :
			csr_matvec_omp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 40 :
			csr_matvec_omp<npy_int32,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 41 :
			csr_matvec_omp<npy_int32,cfloat,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 42 :
			csr_matvec_omp<npy_int32,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 43 :
			csr_matvec_omp<npy_int32,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 44 :
			csr_matvec_omp<npy_int32,cfloat,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 45 :
			csr_matvec_omp<npy_int32,cfloat,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 46 :
			csr_matvec_omp<npy_int32,float,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 47 :
			csr_matvec_omp<npy_int32,float,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 48 :
			csr_matvec_omp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 49 :
			csr_matvec_omp<npy_int32,float,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 50 :
			csr_matvec_omp<npy_int32,float,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 51 :
			csr_matvec_omp<npy_int32,float,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 52 :
			csr_matvec_omp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 53 :
			csr_matvec_omp<npy_int32,float,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 54 :
			csr_matvec_omp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 55 :
			csr_matvec_omp<npy_int64,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 56 :
			csr_matvec_omp<npy_int64,npy_int8,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 57 :
			csr_matvec_omp<npy_int64,npy_int8,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 58 :
			csr_matvec_omp<npy_int64,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 59 :
			csr_matvec_omp<npy_int64,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 60 :
			csr_matvec_omp<npy_int64,npy_int8,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 61 :
			csr_matvec_omp<npy_int64,npy_int8,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 62 :
			csr_matvec_omp<npy_int64,npy_int8,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 63 :
			csr_matvec_omp<npy_int64,npy_int8,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 64 :
			csr_matvec_omp<npy_int64,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 65 :
			csr_matvec_omp<npy_int64,npy_int16,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 66 :
			csr_matvec_omp<npy_int64,npy_int16,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 67 :
			csr_matvec_omp<npy_int64,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 68 :
			csr_matvec_omp<npy_int64,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 69 :
			csr_matvec_omp<npy_int64,npy_int16,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 70 :
			csr_matvec_omp<npy_int64,npy_int16,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 71 :
			csr_matvec_omp<npy_int64,npy_int16,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 72 :
			csr_matvec_omp<npy_int64,npy_int16,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 73 :
			csr_matvec_omp<npy_int64,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 74 :
			csr_matvec_omp<npy_int64,npy_int32,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 75 :
			csr_matvec_omp<npy_int64,npy_int32,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 76 :
			csr_matvec_omp<npy_int64,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 77 :
			csr_matvec_omp<npy_int64,npy_int32,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 78 :
			csr_matvec_omp<npy_int64,npy_int32,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 79 :
			csr_matvec_omp<npy_int64,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 80 :
			csr_matvec_omp<npy_int64,npy_int64,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 81 :
			csr_matvec_omp<npy_int64,npy_int64,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 82 :
			csr_matvec_omp<npy_int64,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 83 :
			csr_matvec_omp<npy_int64,npy_int64,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 84 :
			csr_matvec_omp<npy_int64,npy_int64,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 85 :
			csr_matvec_omp<npy_int64,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 86 :
			csr_matvec_omp<npy_int64,cdouble,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 87 :
			csr_matvec_omp<npy_int64,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 88 :
			csr_matvec_omp<npy_int64,cdouble,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 89 :
			csr_matvec_omp<npy_int64,double,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 90 :
			csr_matvec_omp<npy_int64,double,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 91 :
			csr_matvec_omp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 92 :
			csr_matvec_omp<npy_int64,double,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 93 :
			csr_matvec_omp<npy_int64,double,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 94 :
			csr_matvec_omp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 95 :
			csr_matvec_omp<npy_int64,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 96 :
			csr_matvec_omp<npy_int64,cfloat,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 97 :
			csr_matvec_omp<npy_int64,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 98 :
			csr_matvec_omp<npy_int64,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 99 :
			csr_matvec_omp<npy_int64,cfloat,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 100 :
			csr_matvec_omp<npy_int64,cfloat,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 101 :
			csr_matvec_omp<npy_int64,float,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 102 :
			csr_matvec_omp<npy_int64,float,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 103 :
			csr_matvec_omp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 104 :
			csr_matvec_omp<npy_int64,float,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 105 :
			csr_matvec_omp<npy_int64,float,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 106 :
			csr_matvec_omp<npy_int64,float,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 107 :
			csr_matvec_omp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 108 :
			csr_matvec_omp<npy_int64,float,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 109 :
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
			csr_matvecs_noomp<npy_int32,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 1 :
			csr_matvecs_noomp<npy_int32,npy_int8,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 2 :
			csr_matvecs_noomp<npy_int32,npy_int8,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 3 :
			csr_matvecs_noomp<npy_int32,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 4 :
			csr_matvecs_noomp<npy_int32,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 5 :
			csr_matvecs_noomp<npy_int32,npy_int8,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 6 :
			csr_matvecs_noomp<npy_int32,npy_int8,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 7 :
			csr_matvecs_noomp<npy_int32,npy_int8,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 8 :
			csr_matvecs_noomp<npy_int32,npy_int8,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 9 :
			csr_matvecs_noomp<npy_int32,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 10 :
			csr_matvecs_noomp<npy_int32,npy_int16,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 11 :
			csr_matvecs_noomp<npy_int32,npy_int16,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 12 :
			csr_matvecs_noomp<npy_int32,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 13 :
			csr_matvecs_noomp<npy_int32,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 14 :
			csr_matvecs_noomp<npy_int32,npy_int16,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 15 :
			csr_matvecs_noomp<npy_int32,npy_int16,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 16 :
			csr_matvecs_noomp<npy_int32,npy_int16,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 17 :
			csr_matvecs_noomp<npy_int32,npy_int16,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 18 :
			csr_matvecs_noomp<npy_int32,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 19 :
			csr_matvecs_noomp<npy_int32,npy_int32,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 20 :
			csr_matvecs_noomp<npy_int32,npy_int32,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 21 :
			csr_matvecs_noomp<npy_int32,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 22 :
			csr_matvecs_noomp<npy_int32,npy_int32,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 23 :
			csr_matvecs_noomp<npy_int32,npy_int32,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 24 :
			csr_matvecs_noomp<npy_int32,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 25 :
			csr_matvecs_noomp<npy_int32,npy_int64,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 26 :
			csr_matvecs_noomp<npy_int32,npy_int64,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 27 :
			csr_matvecs_noomp<npy_int32,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 28 :
			csr_matvecs_noomp<npy_int32,npy_int64,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 29 :
			csr_matvecs_noomp<npy_int32,npy_int64,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 30 :
			csr_matvecs_noomp<npy_int32,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 31 :
			csr_matvecs_noomp<npy_int32,cdouble,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 32 :
			csr_matvecs_noomp<npy_int32,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 33 :
			csr_matvecs_noomp<npy_int32,cdouble,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 34 :
			csr_matvecs_noomp<npy_int32,double,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 35 :
			csr_matvecs_noomp<npy_int32,double,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 36 :
			csr_matvecs_noomp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 37 :
			csr_matvecs_noomp<npy_int32,double,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 38 :
			csr_matvecs_noomp<npy_int32,double,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 39 :
			csr_matvecs_noomp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 40 :
			csr_matvecs_noomp<npy_int32,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 41 :
			csr_matvecs_noomp<npy_int32,cfloat,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 42 :
			csr_matvecs_noomp<npy_int32,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 43 :
			csr_matvecs_noomp<npy_int32,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 44 :
			csr_matvecs_noomp<npy_int32,cfloat,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 45 :
			csr_matvecs_noomp<npy_int32,cfloat,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 46 :
			csr_matvecs_noomp<npy_int32,float,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 47 :
			csr_matvecs_noomp<npy_int32,float,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 48 :
			csr_matvecs_noomp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 49 :
			csr_matvecs_noomp<npy_int32,float,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 50 :
			csr_matvecs_noomp<npy_int32,float,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 51 :
			csr_matvecs_noomp<npy_int32,float,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 52 :
			csr_matvecs_noomp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 53 :
			csr_matvecs_noomp<npy_int32,float,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 54 :
			csr_matvecs_noomp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 55 :
			csr_matvecs_noomp<npy_int64,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 56 :
			csr_matvecs_noomp<npy_int64,npy_int8,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 57 :
			csr_matvecs_noomp<npy_int64,npy_int8,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 58 :
			csr_matvecs_noomp<npy_int64,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 59 :
			csr_matvecs_noomp<npy_int64,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 60 :
			csr_matvecs_noomp<npy_int64,npy_int8,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 61 :
			csr_matvecs_noomp<npy_int64,npy_int8,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 62 :
			csr_matvecs_noomp<npy_int64,npy_int8,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 63 :
			csr_matvecs_noomp<npy_int64,npy_int8,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 64 :
			csr_matvecs_noomp<npy_int64,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 65 :
			csr_matvecs_noomp<npy_int64,npy_int16,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 66 :
			csr_matvecs_noomp<npy_int64,npy_int16,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 67 :
			csr_matvecs_noomp<npy_int64,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 68 :
			csr_matvecs_noomp<npy_int64,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 69 :
			csr_matvecs_noomp<npy_int64,npy_int16,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 70 :
			csr_matvecs_noomp<npy_int64,npy_int16,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 71 :
			csr_matvecs_noomp<npy_int64,npy_int16,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 72 :
			csr_matvecs_noomp<npy_int64,npy_int16,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 73 :
			csr_matvecs_noomp<npy_int64,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 74 :
			csr_matvecs_noomp<npy_int64,npy_int32,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 75 :
			csr_matvecs_noomp<npy_int64,npy_int32,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 76 :
			csr_matvecs_noomp<npy_int64,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 77 :
			csr_matvecs_noomp<npy_int64,npy_int32,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 78 :
			csr_matvecs_noomp<npy_int64,npy_int32,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 79 :
			csr_matvecs_noomp<npy_int64,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 80 :
			csr_matvecs_noomp<npy_int64,npy_int64,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 81 :
			csr_matvecs_noomp<npy_int64,npy_int64,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 82 :
			csr_matvecs_noomp<npy_int64,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 83 :
			csr_matvecs_noomp<npy_int64,npy_int64,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 84 :
			csr_matvecs_noomp<npy_int64,npy_int64,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 85 :
			csr_matvecs_noomp<npy_int64,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 86 :
			csr_matvecs_noomp<npy_int64,cdouble,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 87 :
			csr_matvecs_noomp<npy_int64,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 88 :
			csr_matvecs_noomp<npy_int64,cdouble,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 89 :
			csr_matvecs_noomp<npy_int64,double,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 90 :
			csr_matvecs_noomp<npy_int64,double,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 91 :
			csr_matvecs_noomp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 92 :
			csr_matvecs_noomp<npy_int64,double,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 93 :
			csr_matvecs_noomp<npy_int64,double,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 94 :
			csr_matvecs_noomp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 95 :
			csr_matvecs_noomp<npy_int64,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 96 :
			csr_matvecs_noomp<npy_int64,cfloat,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 97 :
			csr_matvecs_noomp<npy_int64,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 98 :
			csr_matvecs_noomp<npy_int64,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 99 :
			csr_matvecs_noomp<npy_int64,cfloat,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 100 :
			csr_matvecs_noomp<npy_int64,cfloat,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 101 :
			csr_matvecs_noomp<npy_int64,float,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 102 :
			csr_matvecs_noomp<npy_int64,float,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 103 :
			csr_matvecs_noomp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 104 :
			csr_matvecs_noomp<npy_int64,float,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 105 :
			csr_matvecs_noomp<npy_int64,float,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 106 :
			csr_matvecs_noomp<npy_int64,float,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 107 :
			csr_matvecs_noomp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 108 :
			csr_matvecs_noomp<npy_int64,float,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 109 :
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
			csr_matvecs_omp<npy_int32,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 1 :
			csr_matvecs_omp<npy_int32,npy_int8,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 2 :
			csr_matvecs_omp<npy_int32,npy_int8,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 3 :
			csr_matvecs_omp<npy_int32,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 4 :
			csr_matvecs_omp<npy_int32,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 5 :
			csr_matvecs_omp<npy_int32,npy_int8,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 6 :
			csr_matvecs_omp<npy_int32,npy_int8,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 7 :
			csr_matvecs_omp<npy_int32,npy_int8,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 8 :
			csr_matvecs_omp<npy_int32,npy_int8,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 9 :
			csr_matvecs_omp<npy_int32,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 10 :
			csr_matvecs_omp<npy_int32,npy_int16,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 11 :
			csr_matvecs_omp<npy_int32,npy_int16,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 12 :
			csr_matvecs_omp<npy_int32,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 13 :
			csr_matvecs_omp<npy_int32,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 14 :
			csr_matvecs_omp<npy_int32,npy_int16,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 15 :
			csr_matvecs_omp<npy_int32,npy_int16,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 16 :
			csr_matvecs_omp<npy_int32,npy_int16,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 17 :
			csr_matvecs_omp<npy_int32,npy_int16,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 18 :
			csr_matvecs_omp<npy_int32,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 19 :
			csr_matvecs_omp<npy_int32,npy_int32,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 20 :
			csr_matvecs_omp<npy_int32,npy_int32,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 21 :
			csr_matvecs_omp<npy_int32,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 22 :
			csr_matvecs_omp<npy_int32,npy_int32,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 23 :
			csr_matvecs_omp<npy_int32,npy_int32,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 24 :
			csr_matvecs_omp<npy_int32,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 25 :
			csr_matvecs_omp<npy_int32,npy_int64,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 26 :
			csr_matvecs_omp<npy_int32,npy_int64,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 27 :
			csr_matvecs_omp<npy_int32,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 28 :
			csr_matvecs_omp<npy_int32,npy_int64,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 29 :
			csr_matvecs_omp<npy_int32,npy_int64,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 30 :
			csr_matvecs_omp<npy_int32,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 31 :
			csr_matvecs_omp<npy_int32,cdouble,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 32 :
			csr_matvecs_omp<npy_int32,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 33 :
			csr_matvecs_omp<npy_int32,cdouble,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 34 :
			csr_matvecs_omp<npy_int32,double,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 35 :
			csr_matvecs_omp<npy_int32,double,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 36 :
			csr_matvecs_omp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 37 :
			csr_matvecs_omp<npy_int32,double,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 38 :
			csr_matvecs_omp<npy_int32,double,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 39 :
			csr_matvecs_omp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 40 :
			csr_matvecs_omp<npy_int32,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 41 :
			csr_matvecs_omp<npy_int32,cfloat,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 42 :
			csr_matvecs_omp<npy_int32,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 43 :
			csr_matvecs_omp<npy_int32,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 44 :
			csr_matvecs_omp<npy_int32,cfloat,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 45 :
			csr_matvecs_omp<npy_int32,cfloat,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 46 :
			csr_matvecs_omp<npy_int32,float,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 47 :
			csr_matvecs_omp<npy_int32,float,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 48 :
			csr_matvecs_omp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 49 :
			csr_matvecs_omp<npy_int32,float,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 50 :
			csr_matvecs_omp<npy_int32,float,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 51 :
			csr_matvecs_omp<npy_int32,float,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 52 :
			csr_matvecs_omp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 53 :
			csr_matvecs_omp<npy_int32,float,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 54 :
			csr_matvecs_omp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 55 :
			csr_matvecs_omp<npy_int64,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 56 :
			csr_matvecs_omp<npy_int64,npy_int8,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 57 :
			csr_matvecs_omp<npy_int64,npy_int8,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 58 :
			csr_matvecs_omp<npy_int64,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 59 :
			csr_matvecs_omp<npy_int64,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 60 :
			csr_matvecs_omp<npy_int64,npy_int8,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 61 :
			csr_matvecs_omp<npy_int64,npy_int8,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 62 :
			csr_matvecs_omp<npy_int64,npy_int8,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 63 :
			csr_matvecs_omp<npy_int64,npy_int8,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 64 :
			csr_matvecs_omp<npy_int64,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 65 :
			csr_matvecs_omp<npy_int64,npy_int16,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 66 :
			csr_matvecs_omp<npy_int64,npy_int16,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 67 :
			csr_matvecs_omp<npy_int64,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 68 :
			csr_matvecs_omp<npy_int64,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 69 :
			csr_matvecs_omp<npy_int64,npy_int16,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 70 :
			csr_matvecs_omp<npy_int64,npy_int16,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 71 :
			csr_matvecs_omp<npy_int64,npy_int16,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 72 :
			csr_matvecs_omp<npy_int64,npy_int16,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 73 :
			csr_matvecs_omp<npy_int64,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 74 :
			csr_matvecs_omp<npy_int64,npy_int32,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 75 :
			csr_matvecs_omp<npy_int64,npy_int32,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 76 :
			csr_matvecs_omp<npy_int64,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 77 :
			csr_matvecs_omp<npy_int64,npy_int32,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 78 :
			csr_matvecs_omp<npy_int64,npy_int32,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 79 :
			csr_matvecs_omp<npy_int64,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 80 :
			csr_matvecs_omp<npy_int64,npy_int64,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 81 :
			csr_matvecs_omp<npy_int64,npy_int64,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 82 :
			csr_matvecs_omp<npy_int64,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 83 :
			csr_matvecs_omp<npy_int64,npy_int64,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 84 :
			csr_matvecs_omp<npy_int64,npy_int64,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 85 :
			csr_matvecs_omp<npy_int64,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 86 :
			csr_matvecs_omp<npy_int64,cdouble,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 87 :
			csr_matvecs_omp<npy_int64,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 88 :
			csr_matvecs_omp<npy_int64,cdouble,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 89 :
			csr_matvecs_omp<npy_int64,double,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 90 :
			csr_matvecs_omp<npy_int64,double,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 91 :
			csr_matvecs_omp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 92 :
			csr_matvecs_omp<npy_int64,double,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 93 :
			csr_matvecs_omp<npy_int64,double,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 94 :
			csr_matvecs_omp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 95 :
			csr_matvecs_omp<npy_int64,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 96 :
			csr_matvecs_omp<npy_int64,cfloat,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 97 :
			csr_matvecs_omp<npy_int64,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 98 :
			csr_matvecs_omp<npy_int64,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 99 :
			csr_matvecs_omp<npy_int64,cfloat,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 100 :
			csr_matvecs_omp<npy_int64,cfloat,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 101 :
			csr_matvecs_omp<npy_int64,float,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 102 :
			csr_matvecs_omp<npy_int64,float,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 103 :
			csr_matvecs_omp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 104 :
			csr_matvecs_omp<npy_int64,float,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 105 :
			csr_matvecs_omp<npy_int64,float,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 106 :
			csr_matvecs_omp<npy_int64,float,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 107 :
			csr_matvecs_omp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 108 :
			csr_matvecs_omp<npy_int64,float,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 109 :
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
			csc_matvec_noomp<npy_int32,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 1 :
			csc_matvec_noomp<npy_int32,npy_int8,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 2 :
			csc_matvec_noomp<npy_int32,npy_int8,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 3 :
			csc_matvec_noomp<npy_int32,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 4 :
			csc_matvec_noomp<npy_int32,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 5 :
			csc_matvec_noomp<npy_int32,npy_int8,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 6 :
			csc_matvec_noomp<npy_int32,npy_int8,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 7 :
			csc_matvec_noomp<npy_int32,npy_int8,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 8 :
			csc_matvec_noomp<npy_int32,npy_int8,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 9 :
			csc_matvec_noomp<npy_int32,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 10 :
			csc_matvec_noomp<npy_int32,npy_int16,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 11 :
			csc_matvec_noomp<npy_int32,npy_int16,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 12 :
			csc_matvec_noomp<npy_int32,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 13 :
			csc_matvec_noomp<npy_int32,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 14 :
			csc_matvec_noomp<npy_int32,npy_int16,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 15 :
			csc_matvec_noomp<npy_int32,npy_int16,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 16 :
			csc_matvec_noomp<npy_int32,npy_int16,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 17 :
			csc_matvec_noomp<npy_int32,npy_int16,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 18 :
			csc_matvec_noomp<npy_int32,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 19 :
			csc_matvec_noomp<npy_int32,npy_int32,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 20 :
			csc_matvec_noomp<npy_int32,npy_int32,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 21 :
			csc_matvec_noomp<npy_int32,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 22 :
			csc_matvec_noomp<npy_int32,npy_int32,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 23 :
			csc_matvec_noomp<npy_int32,npy_int32,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 24 :
			csc_matvec_noomp<npy_int32,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 25 :
			csc_matvec_noomp<npy_int32,npy_int64,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 26 :
			csc_matvec_noomp<npy_int32,npy_int64,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 27 :
			csc_matvec_noomp<npy_int32,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 28 :
			csc_matvec_noomp<npy_int32,npy_int64,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 29 :
			csc_matvec_noomp<npy_int32,npy_int64,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 30 :
			csc_matvec_noomp<npy_int32,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 31 :
			csc_matvec_noomp<npy_int32,cdouble,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 32 :
			csc_matvec_noomp<npy_int32,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 33 :
			csc_matvec_noomp<npy_int32,cdouble,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 34 :
			csc_matvec_noomp<npy_int32,double,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 35 :
			csc_matvec_noomp<npy_int32,double,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 36 :
			csc_matvec_noomp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 37 :
			csc_matvec_noomp<npy_int32,double,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 38 :
			csc_matvec_noomp<npy_int32,double,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 39 :
			csc_matvec_noomp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 40 :
			csc_matvec_noomp<npy_int32,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 41 :
			csc_matvec_noomp<npy_int32,cfloat,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 42 :
			csc_matvec_noomp<npy_int32,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 43 :
			csc_matvec_noomp<npy_int32,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 44 :
			csc_matvec_noomp<npy_int32,cfloat,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 45 :
			csc_matvec_noomp<npy_int32,cfloat,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 46 :
			csc_matvec_noomp<npy_int32,float,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 47 :
			csc_matvec_noomp<npy_int32,float,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 48 :
			csc_matvec_noomp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 49 :
			csc_matvec_noomp<npy_int32,float,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 50 :
			csc_matvec_noomp<npy_int32,float,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 51 :
			csc_matvec_noomp<npy_int32,float,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 52 :
			csc_matvec_noomp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 53 :
			csc_matvec_noomp<npy_int32,float,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 54 :
			csc_matvec_noomp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 55 :
			csc_matvec_noomp<npy_int64,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 56 :
			csc_matvec_noomp<npy_int64,npy_int8,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 57 :
			csc_matvec_noomp<npy_int64,npy_int8,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 58 :
			csc_matvec_noomp<npy_int64,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 59 :
			csc_matvec_noomp<npy_int64,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 60 :
			csc_matvec_noomp<npy_int64,npy_int8,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 61 :
			csc_matvec_noomp<npy_int64,npy_int8,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 62 :
			csc_matvec_noomp<npy_int64,npy_int8,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 63 :
			csc_matvec_noomp<npy_int64,npy_int8,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 64 :
			csc_matvec_noomp<npy_int64,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 65 :
			csc_matvec_noomp<npy_int64,npy_int16,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 66 :
			csc_matvec_noomp<npy_int64,npy_int16,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 67 :
			csc_matvec_noomp<npy_int64,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 68 :
			csc_matvec_noomp<npy_int64,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 69 :
			csc_matvec_noomp<npy_int64,npy_int16,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 70 :
			csc_matvec_noomp<npy_int64,npy_int16,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 71 :
			csc_matvec_noomp<npy_int64,npy_int16,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 72 :
			csc_matvec_noomp<npy_int64,npy_int16,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 73 :
			csc_matvec_noomp<npy_int64,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 74 :
			csc_matvec_noomp<npy_int64,npy_int32,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 75 :
			csc_matvec_noomp<npy_int64,npy_int32,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 76 :
			csc_matvec_noomp<npy_int64,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 77 :
			csc_matvec_noomp<npy_int64,npy_int32,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 78 :
			csc_matvec_noomp<npy_int64,npy_int32,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 79 :
			csc_matvec_noomp<npy_int64,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 80 :
			csc_matvec_noomp<npy_int64,npy_int64,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 81 :
			csc_matvec_noomp<npy_int64,npy_int64,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 82 :
			csc_matvec_noomp<npy_int64,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 83 :
			csc_matvec_noomp<npy_int64,npy_int64,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 84 :
			csc_matvec_noomp<npy_int64,npy_int64,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 85 :
			csc_matvec_noomp<npy_int64,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 86 :
			csc_matvec_noomp<npy_int64,cdouble,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 87 :
			csc_matvec_noomp<npy_int64,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 88 :
			csc_matvec_noomp<npy_int64,cdouble,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 89 :
			csc_matvec_noomp<npy_int64,double,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 90 :
			csc_matvec_noomp<npy_int64,double,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 91 :
			csc_matvec_noomp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 92 :
			csc_matvec_noomp<npy_int64,double,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 93 :
			csc_matvec_noomp<npy_int64,double,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 94 :
			csc_matvec_noomp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 95 :
			csc_matvec_noomp<npy_int64,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 96 :
			csc_matvec_noomp<npy_int64,cfloat,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 97 :
			csc_matvec_noomp<npy_int64,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 98 :
			csc_matvec_noomp<npy_int64,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 99 :
			csc_matvec_noomp<npy_int64,cfloat,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 100 :
			csc_matvec_noomp<npy_int64,cfloat,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 101 :
			csc_matvec_noomp<npy_int64,float,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 102 :
			csc_matvec_noomp<npy_int64,float,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 103 :
			csc_matvec_noomp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 104 :
			csc_matvec_noomp<npy_int64,float,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 105 :
			csc_matvec_noomp<npy_int64,float,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 106 :
			csc_matvec_noomp<npy_int64,float,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 107 :
			csc_matvec_noomp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 108 :
			csc_matvec_noomp<npy_int64,float,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 109 :
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
			csc_matvec_omp<npy_int32,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 1 :
			csc_matvec_omp<npy_int32,npy_int8,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 2 :
			csc_matvec_omp<npy_int32,npy_int8,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 3 :
			csc_matvec_omp<npy_int32,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 4 :
			csc_matvec_omp<npy_int32,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 5 :
			csc_matvec_omp<npy_int32,npy_int8,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 6 :
			csc_matvec_omp<npy_int32,npy_int8,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 7 :
			csc_matvec_omp<npy_int32,npy_int8,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 8 :
			csc_matvec_omp<npy_int32,npy_int8,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 9 :
			csc_matvec_omp<npy_int32,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 10 :
			csc_matvec_omp<npy_int32,npy_int16,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 11 :
			csc_matvec_omp<npy_int32,npy_int16,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 12 :
			csc_matvec_omp<npy_int32,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 13 :
			csc_matvec_omp<npy_int32,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 14 :
			csc_matvec_omp<npy_int32,npy_int16,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 15 :
			csc_matvec_omp<npy_int32,npy_int16,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 16 :
			csc_matvec_omp<npy_int32,npy_int16,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 17 :
			csc_matvec_omp<npy_int32,npy_int16,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 18 :
			csc_matvec_omp<npy_int32,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 19 :
			csc_matvec_omp<npy_int32,npy_int32,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 20 :
			csc_matvec_omp<npy_int32,npy_int32,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 21 :
			csc_matvec_omp<npy_int32,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 22 :
			csc_matvec_omp<npy_int32,npy_int32,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 23 :
			csc_matvec_omp<npy_int32,npy_int32,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 24 :
			csc_matvec_omp<npy_int32,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 25 :
			csc_matvec_omp<npy_int32,npy_int64,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 26 :
			csc_matvec_omp<npy_int32,npy_int64,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 27 :
			csc_matvec_omp<npy_int32,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 28 :
			csc_matvec_omp<npy_int32,npy_int64,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 29 :
			csc_matvec_omp<npy_int32,npy_int64,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 30 :
			csc_matvec_omp<npy_int32,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 31 :
			csc_matvec_omp<npy_int32,cdouble,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 32 :
			csc_matvec_omp<npy_int32,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 33 :
			csc_matvec_omp<npy_int32,cdouble,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 34 :
			csc_matvec_omp<npy_int32,double,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 35 :
			csc_matvec_omp<npy_int32,double,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 36 :
			csc_matvec_omp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 37 :
			csc_matvec_omp<npy_int32,double,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 38 :
			csc_matvec_omp<npy_int32,double,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 39 :
			csc_matvec_omp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 40 :
			csc_matvec_omp<npy_int32,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 41 :
			csc_matvec_omp<npy_int32,cfloat,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 42 :
			csc_matvec_omp<npy_int32,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 43 :
			csc_matvec_omp<npy_int32,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 44 :
			csc_matvec_omp<npy_int32,cfloat,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 45 :
			csc_matvec_omp<npy_int32,cfloat,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 46 :
			csc_matvec_omp<npy_int32,float,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 47 :
			csc_matvec_omp<npy_int32,float,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 48 :
			csc_matvec_omp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 49 :
			csc_matvec_omp<npy_int32,float,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 50 :
			csc_matvec_omp<npy_int32,float,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 51 :
			csc_matvec_omp<npy_int32,float,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 52 :
			csc_matvec_omp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 53 :
			csc_matvec_omp<npy_int32,float,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 54 :
			csc_matvec_omp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 55 :
			csc_matvec_omp<npy_int64,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 56 :
			csc_matvec_omp<npy_int64,npy_int8,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 57 :
			csc_matvec_omp<npy_int64,npy_int8,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 58 :
			csc_matvec_omp<npy_int64,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 59 :
			csc_matvec_omp<npy_int64,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 60 :
			csc_matvec_omp<npy_int64,npy_int8,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 61 :
			csc_matvec_omp<npy_int64,npy_int8,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 62 :
			csc_matvec_omp<npy_int64,npy_int8,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 63 :
			csc_matvec_omp<npy_int64,npy_int8,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 64 :
			csc_matvec_omp<npy_int64,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 65 :
			csc_matvec_omp<npy_int64,npy_int16,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 66 :
			csc_matvec_omp<npy_int64,npy_int16,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 67 :
			csc_matvec_omp<npy_int64,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 68 :
			csc_matvec_omp<npy_int64,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 69 :
			csc_matvec_omp<npy_int64,npy_int16,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 70 :
			csc_matvec_omp<npy_int64,npy_int16,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 71 :
			csc_matvec_omp<npy_int64,npy_int16,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 72 :
			csc_matvec_omp<npy_int64,npy_int16,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 73 :
			csc_matvec_omp<npy_int64,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 74 :
			csc_matvec_omp<npy_int64,npy_int32,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 75 :
			csc_matvec_omp<npy_int64,npy_int32,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 76 :
			csc_matvec_omp<npy_int64,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 77 :
			csc_matvec_omp<npy_int64,npy_int32,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 78 :
			csc_matvec_omp<npy_int64,npy_int32,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 79 :
			csc_matvec_omp<npy_int64,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 80 :
			csc_matvec_omp<npy_int64,npy_int64,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 81 :
			csc_matvec_omp<npy_int64,npy_int64,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 82 :
			csc_matvec_omp<npy_int64,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 83 :
			csc_matvec_omp<npy_int64,npy_int64,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 84 :
			csc_matvec_omp<npy_int64,npy_int64,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 85 :
			csc_matvec_omp<npy_int64,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 86 :
			csc_matvec_omp<npy_int64,cdouble,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 87 :
			csc_matvec_omp<npy_int64,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 88 :
			csc_matvec_omp<npy_int64,cdouble,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 89 :
			csc_matvec_omp<npy_int64,double,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 90 :
			csc_matvec_omp<npy_int64,double,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 91 :
			csc_matvec_omp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 92 :
			csc_matvec_omp<npy_int64,double,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 93 :
			csc_matvec_omp<npy_int64,double,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 94 :
			csc_matvec_omp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 95 :
			csc_matvec_omp<npy_int64,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 96 :
			csc_matvec_omp<npy_int64,cfloat,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 97 :
			csc_matvec_omp<npy_int64,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 98 :
			csc_matvec_omp<npy_int64,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 99 :
			csc_matvec_omp<npy_int64,cfloat,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 100 :
			csc_matvec_omp<npy_int64,cfloat,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 101 :
			csc_matvec_omp<npy_int64,float,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 102 :
			csc_matvec_omp<npy_int64,float,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 103 :
			csc_matvec_omp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 104 :
			csc_matvec_omp<npy_int64,float,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 105 :
			csc_matvec_omp<npy_int64,float,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 106 :
			csc_matvec_omp<npy_int64,float,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 107 :
			csc_matvec_omp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 108 :
			csc_matvec_omp<npy_int64,float,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 109 :
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
			csc_matvecs_noomp<npy_int32,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 1 :
			csc_matvecs_noomp<npy_int32,npy_int8,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 2 :
			csc_matvecs_noomp<npy_int32,npy_int8,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 3 :
			csc_matvecs_noomp<npy_int32,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 4 :
			csc_matvecs_noomp<npy_int32,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 5 :
			csc_matvecs_noomp<npy_int32,npy_int8,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 6 :
			csc_matvecs_noomp<npy_int32,npy_int8,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 7 :
			csc_matvecs_noomp<npy_int32,npy_int8,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 8 :
			csc_matvecs_noomp<npy_int32,npy_int8,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 9 :
			csc_matvecs_noomp<npy_int32,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 10 :
			csc_matvecs_noomp<npy_int32,npy_int16,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 11 :
			csc_matvecs_noomp<npy_int32,npy_int16,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 12 :
			csc_matvecs_noomp<npy_int32,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 13 :
			csc_matvecs_noomp<npy_int32,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 14 :
			csc_matvecs_noomp<npy_int32,npy_int16,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 15 :
			csc_matvecs_noomp<npy_int32,npy_int16,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 16 :
			csc_matvecs_noomp<npy_int32,npy_int16,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 17 :
			csc_matvecs_noomp<npy_int32,npy_int16,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 18 :
			csc_matvecs_noomp<npy_int32,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 19 :
			csc_matvecs_noomp<npy_int32,npy_int32,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 20 :
			csc_matvecs_noomp<npy_int32,npy_int32,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 21 :
			csc_matvecs_noomp<npy_int32,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 22 :
			csc_matvecs_noomp<npy_int32,npy_int32,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 23 :
			csc_matvecs_noomp<npy_int32,npy_int32,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 24 :
			csc_matvecs_noomp<npy_int32,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 25 :
			csc_matvecs_noomp<npy_int32,npy_int64,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 26 :
			csc_matvecs_noomp<npy_int32,npy_int64,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 27 :
			csc_matvecs_noomp<npy_int32,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 28 :
			csc_matvecs_noomp<npy_int32,npy_int64,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 29 :
			csc_matvecs_noomp<npy_int32,npy_int64,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 30 :
			csc_matvecs_noomp<npy_int32,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 31 :
			csc_matvecs_noomp<npy_int32,cdouble,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 32 :
			csc_matvecs_noomp<npy_int32,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 33 :
			csc_matvecs_noomp<npy_int32,cdouble,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 34 :
			csc_matvecs_noomp<npy_int32,double,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 35 :
			csc_matvecs_noomp<npy_int32,double,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 36 :
			csc_matvecs_noomp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 37 :
			csc_matvecs_noomp<npy_int32,double,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 38 :
			csc_matvecs_noomp<npy_int32,double,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 39 :
			csc_matvecs_noomp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 40 :
			csc_matvecs_noomp<npy_int32,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 41 :
			csc_matvecs_noomp<npy_int32,cfloat,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 42 :
			csc_matvecs_noomp<npy_int32,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 43 :
			csc_matvecs_noomp<npy_int32,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 44 :
			csc_matvecs_noomp<npy_int32,cfloat,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 45 :
			csc_matvecs_noomp<npy_int32,cfloat,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 46 :
			csc_matvecs_noomp<npy_int32,float,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 47 :
			csc_matvecs_noomp<npy_int32,float,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 48 :
			csc_matvecs_noomp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 49 :
			csc_matvecs_noomp<npy_int32,float,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 50 :
			csc_matvecs_noomp<npy_int32,float,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 51 :
			csc_matvecs_noomp<npy_int32,float,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 52 :
			csc_matvecs_noomp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 53 :
			csc_matvecs_noomp<npy_int32,float,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 54 :
			csc_matvecs_noomp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 55 :
			csc_matvecs_noomp<npy_int64,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 56 :
			csc_matvecs_noomp<npy_int64,npy_int8,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 57 :
			csc_matvecs_noomp<npy_int64,npy_int8,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 58 :
			csc_matvecs_noomp<npy_int64,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 59 :
			csc_matvecs_noomp<npy_int64,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 60 :
			csc_matvecs_noomp<npy_int64,npy_int8,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 61 :
			csc_matvecs_noomp<npy_int64,npy_int8,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 62 :
			csc_matvecs_noomp<npy_int64,npy_int8,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 63 :
			csc_matvecs_noomp<npy_int64,npy_int8,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 64 :
			csc_matvecs_noomp<npy_int64,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 65 :
			csc_matvecs_noomp<npy_int64,npy_int16,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 66 :
			csc_matvecs_noomp<npy_int64,npy_int16,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 67 :
			csc_matvecs_noomp<npy_int64,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 68 :
			csc_matvecs_noomp<npy_int64,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 69 :
			csc_matvecs_noomp<npy_int64,npy_int16,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 70 :
			csc_matvecs_noomp<npy_int64,npy_int16,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 71 :
			csc_matvecs_noomp<npy_int64,npy_int16,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 72 :
			csc_matvecs_noomp<npy_int64,npy_int16,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 73 :
			csc_matvecs_noomp<npy_int64,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 74 :
			csc_matvecs_noomp<npy_int64,npy_int32,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 75 :
			csc_matvecs_noomp<npy_int64,npy_int32,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 76 :
			csc_matvecs_noomp<npy_int64,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 77 :
			csc_matvecs_noomp<npy_int64,npy_int32,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 78 :
			csc_matvecs_noomp<npy_int64,npy_int32,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 79 :
			csc_matvecs_noomp<npy_int64,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 80 :
			csc_matvecs_noomp<npy_int64,npy_int64,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 81 :
			csc_matvecs_noomp<npy_int64,npy_int64,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 82 :
			csc_matvecs_noomp<npy_int64,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 83 :
			csc_matvecs_noomp<npy_int64,npy_int64,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 84 :
			csc_matvecs_noomp<npy_int64,npy_int64,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 85 :
			csc_matvecs_noomp<npy_int64,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 86 :
			csc_matvecs_noomp<npy_int64,cdouble,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 87 :
			csc_matvecs_noomp<npy_int64,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 88 :
			csc_matvecs_noomp<npy_int64,cdouble,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 89 :
			csc_matvecs_noomp<npy_int64,double,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 90 :
			csc_matvecs_noomp<npy_int64,double,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 91 :
			csc_matvecs_noomp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 92 :
			csc_matvecs_noomp<npy_int64,double,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 93 :
			csc_matvecs_noomp<npy_int64,double,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 94 :
			csc_matvecs_noomp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 95 :
			csc_matvecs_noomp<npy_int64,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 96 :
			csc_matvecs_noomp<npy_int64,cfloat,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 97 :
			csc_matvecs_noomp<npy_int64,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 98 :
			csc_matvecs_noomp<npy_int64,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 99 :
			csc_matvecs_noomp<npy_int64,cfloat,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 100 :
			csc_matvecs_noomp<npy_int64,cfloat,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 101 :
			csc_matvecs_noomp<npy_int64,float,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 102 :
			csc_matvecs_noomp<npy_int64,float,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 103 :
			csc_matvecs_noomp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 104 :
			csc_matvecs_noomp<npy_int64,float,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 105 :
			csc_matvecs_noomp<npy_int64,float,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 106 :
			csc_matvecs_noomp<npy_int64,float,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 107 :
			csc_matvecs_noomp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 108 :
			csc_matvecs_noomp<npy_int64,float,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 109 :
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
			csc_matvecs_omp<npy_int32,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 1 :
			csc_matvecs_omp<npy_int32,npy_int8,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 2 :
			csc_matvecs_omp<npy_int32,npy_int8,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 3 :
			csc_matvecs_omp<npy_int32,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 4 :
			csc_matvecs_omp<npy_int32,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 5 :
			csc_matvecs_omp<npy_int32,npy_int8,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 6 :
			csc_matvecs_omp<npy_int32,npy_int8,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 7 :
			csc_matvecs_omp<npy_int32,npy_int8,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 8 :
			csc_matvecs_omp<npy_int32,npy_int8,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 9 :
			csc_matvecs_omp<npy_int32,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 10 :
			csc_matvecs_omp<npy_int32,npy_int16,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 11 :
			csc_matvecs_omp<npy_int32,npy_int16,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 12 :
			csc_matvecs_omp<npy_int32,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 13 :
			csc_matvecs_omp<npy_int32,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 14 :
			csc_matvecs_omp<npy_int32,npy_int16,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 15 :
			csc_matvecs_omp<npy_int32,npy_int16,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 16 :
			csc_matvecs_omp<npy_int32,npy_int16,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 17 :
			csc_matvecs_omp<npy_int32,npy_int16,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 18 :
			csc_matvecs_omp<npy_int32,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 19 :
			csc_matvecs_omp<npy_int32,npy_int32,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 20 :
			csc_matvecs_omp<npy_int32,npy_int32,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 21 :
			csc_matvecs_omp<npy_int32,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 22 :
			csc_matvecs_omp<npy_int32,npy_int32,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 23 :
			csc_matvecs_omp<npy_int32,npy_int32,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 24 :
			csc_matvecs_omp<npy_int32,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 25 :
			csc_matvecs_omp<npy_int32,npy_int64,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 26 :
			csc_matvecs_omp<npy_int32,npy_int64,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 27 :
			csc_matvecs_omp<npy_int32,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 28 :
			csc_matvecs_omp<npy_int32,npy_int64,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 29 :
			csc_matvecs_omp<npy_int32,npy_int64,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 30 :
			csc_matvecs_omp<npy_int32,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 31 :
			csc_matvecs_omp<npy_int32,cdouble,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 32 :
			csc_matvecs_omp<npy_int32,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 33 :
			csc_matvecs_omp<npy_int32,cdouble,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cdouble*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 34 :
			csc_matvecs_omp<npy_int32,double,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 35 :
			csc_matvecs_omp<npy_int32,double,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 36 :
			csc_matvecs_omp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 37 :
			csc_matvecs_omp<npy_int32,double,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 38 :
			csc_matvecs_omp<npy_int32,double,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 39 :
			csc_matvecs_omp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 40 :
			csc_matvecs_omp<npy_int32,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 41 :
			csc_matvecs_omp<npy_int32,cfloat,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 42 :
			csc_matvecs_omp<npy_int32,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 43 :
			csc_matvecs_omp<npy_int32,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 44 :
			csc_matvecs_omp<npy_int32,cfloat,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 45 :
			csc_matvecs_omp<npy_int32,cfloat,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 46 :
			csc_matvecs_omp<npy_int32,float,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 47 :
			csc_matvecs_omp<npy_int32,float,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 48 :
			csc_matvecs_omp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 49 :
			csc_matvecs_omp<npy_int32,float,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 50 :
			csc_matvecs_omp<npy_int32,float,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 51 :
			csc_matvecs_omp<npy_int32,float,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 52 :
			csc_matvecs_omp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 53 :
			csc_matvecs_omp<npy_int32,float,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 54 :
			csc_matvecs_omp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32*)Ap,(const npy_int32*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 55 :
			csc_matvecs_omp<npy_int64,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 56 :
			csc_matvecs_omp<npy_int64,npy_int8,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 57 :
			csc_matvecs_omp<npy_int64,npy_int8,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 58 :
			csc_matvecs_omp<npy_int64,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 59 :
			csc_matvecs_omp<npy_int64,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 60 :
			csc_matvecs_omp<npy_int64,npy_int8,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 61 :
			csc_matvecs_omp<npy_int64,npy_int8,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 62 :
			csc_matvecs_omp<npy_int64,npy_int8,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 63 :
			csc_matvecs_omp<npy_int64,npy_int8,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int8*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 64 :
			csc_matvecs_omp<npy_int64,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 65 :
			csc_matvecs_omp<npy_int64,npy_int16,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 66 :
			csc_matvecs_omp<npy_int64,npy_int16,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 67 :
			csc_matvecs_omp<npy_int64,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 68 :
			csc_matvecs_omp<npy_int64,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 69 :
			csc_matvecs_omp<npy_int64,npy_int16,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 70 :
			csc_matvecs_omp<npy_int64,npy_int16,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 71 :
			csc_matvecs_omp<npy_int64,npy_int16,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 72 :
			csc_matvecs_omp<npy_int64,npy_int16,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int16*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 73 :
			csc_matvecs_omp<npy_int64,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 74 :
			csc_matvecs_omp<npy_int64,npy_int32,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 75 :
			csc_matvecs_omp<npy_int64,npy_int32,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 76 :
			csc_matvecs_omp<npy_int64,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 77 :
			csc_matvecs_omp<npy_int64,npy_int32,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 78 :
			csc_matvecs_omp<npy_int64,npy_int32,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int32*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 79 :
			csc_matvecs_omp<npy_int64,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 80 :
			csc_matvecs_omp<npy_int64,npy_int64,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 81 :
			csc_matvecs_omp<npy_int64,npy_int64,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 82 :
			csc_matvecs_omp<npy_int64,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 83 :
			csc_matvecs_omp<npy_int64,npy_int64,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 84 :
			csc_matvecs_omp<npy_int64,npy_int64,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const npy_int64*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 85 :
			csc_matvecs_omp<npy_int64,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 86 :
			csc_matvecs_omp<npy_int64,cdouble,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 87 :
			csc_matvecs_omp<npy_int64,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 88 :
			csc_matvecs_omp<npy_int64,cdouble,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cdouble*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 89 :
			csc_matvecs_omp<npy_int64,double,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 90 :
			csc_matvecs_omp<npy_int64,double,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 91 :
			csc_matvecs_omp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 92 :
			csc_matvecs_omp<npy_int64,double,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 93 :
			csc_matvecs_omp<npy_int64,double,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 94 :
			csc_matvecs_omp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const double*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 95 :
			csc_matvecs_omp<npy_int64,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 96 :
			csc_matvecs_omp<npy_int64,cfloat,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 97 :
			csc_matvecs_omp<npy_int64,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 98 :
			csc_matvecs_omp<npy_int64,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 99 :
			csc_matvecs_omp<npy_int64,cfloat,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 100 :
			csc_matvecs_omp<npy_int64,cfloat,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const cfloat*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 101 :
			csc_matvecs_omp<npy_int64,float,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 102 :
			csc_matvecs_omp<npy_int64,float,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 103 :
			csc_matvecs_omp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 104 :
			csc_matvecs_omp<npy_int64,float,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 105 :
			csc_matvecs_omp<npy_int64,float,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 106 :
			csc_matvecs_omp<npy_int64,float,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 107 :
			csc_matvecs_omp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 108 :
			csc_matvecs_omp<npy_int64,float,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64*)Ap,(const npy_int64*)Aj,(const float*)Ax,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 109 :
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
			dia_matvec_noomp<npy_int32,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 1 :
			dia_matvec_noomp<npy_int32,npy_int8,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 2 :
			dia_matvec_noomp<npy_int32,npy_int8,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 3 :
			dia_matvec_noomp<npy_int32,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 4 :
			dia_matvec_noomp<npy_int32,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 5 :
			dia_matvec_noomp<npy_int32,npy_int8,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 6 :
			dia_matvec_noomp<npy_int32,npy_int8,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 7 :
			dia_matvec_noomp<npy_int32,npy_int8,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 8 :
			dia_matvec_noomp<npy_int32,npy_int8,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 9 :
			dia_matvec_noomp<npy_int32,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 10 :
			dia_matvec_noomp<npy_int32,npy_int16,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 11 :
			dia_matvec_noomp<npy_int32,npy_int16,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 12 :
			dia_matvec_noomp<npy_int32,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 13 :
			dia_matvec_noomp<npy_int32,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 14 :
			dia_matvec_noomp<npy_int32,npy_int16,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 15 :
			dia_matvec_noomp<npy_int32,npy_int16,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 16 :
			dia_matvec_noomp<npy_int32,npy_int16,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 17 :
			dia_matvec_noomp<npy_int32,npy_int16,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 18 :
			dia_matvec_noomp<npy_int32,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 19 :
			dia_matvec_noomp<npy_int32,npy_int32,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 20 :
			dia_matvec_noomp<npy_int32,npy_int32,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 21 :
			dia_matvec_noomp<npy_int32,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 22 :
			dia_matvec_noomp<npy_int32,npy_int32,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 23 :
			dia_matvec_noomp<npy_int32,npy_int32,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 24 :
			dia_matvec_noomp<npy_int32,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 25 :
			dia_matvec_noomp<npy_int32,npy_int64,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 26 :
			dia_matvec_noomp<npy_int32,npy_int64,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 27 :
			dia_matvec_noomp<npy_int32,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 28 :
			dia_matvec_noomp<npy_int32,npy_int64,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 29 :
			dia_matvec_noomp<npy_int32,npy_int64,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 30 :
			dia_matvec_noomp<npy_int32,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cdouble*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 31 :
			dia_matvec_noomp<npy_int32,cdouble,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cdouble*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 32 :
			dia_matvec_noomp<npy_int32,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cdouble*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 33 :
			dia_matvec_noomp<npy_int32,cdouble,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cdouble*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 34 :
			dia_matvec_noomp<npy_int32,double,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 35 :
			dia_matvec_noomp<npy_int32,double,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 36 :
			dia_matvec_noomp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 37 :
			dia_matvec_noomp<npy_int32,double,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 38 :
			dia_matvec_noomp<npy_int32,double,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 39 :
			dia_matvec_noomp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 40 :
			dia_matvec_noomp<npy_int32,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 41 :
			dia_matvec_noomp<npy_int32,cfloat,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 42 :
			dia_matvec_noomp<npy_int32,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 43 :
			dia_matvec_noomp<npy_int32,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 44 :
			dia_matvec_noomp<npy_int32,cfloat,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 45 :
			dia_matvec_noomp<npy_int32,cfloat,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 46 :
			dia_matvec_noomp<npy_int32,float,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 47 :
			dia_matvec_noomp<npy_int32,float,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 48 :
			dia_matvec_noomp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 49 :
			dia_matvec_noomp<npy_int32,float,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 50 :
			dia_matvec_noomp<npy_int32,float,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 51 :
			dia_matvec_noomp<npy_int32,float,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 52 :
			dia_matvec_noomp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 53 :
			dia_matvec_noomp<npy_int32,float,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 54 :
			dia_matvec_noomp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 55 :
			dia_matvec_noomp<npy_int64,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 56 :
			dia_matvec_noomp<npy_int64,npy_int8,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 57 :
			dia_matvec_noomp<npy_int64,npy_int8,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 58 :
			dia_matvec_noomp<npy_int64,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 59 :
			dia_matvec_noomp<npy_int64,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 60 :
			dia_matvec_noomp<npy_int64,npy_int8,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 61 :
			dia_matvec_noomp<npy_int64,npy_int8,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 62 :
			dia_matvec_noomp<npy_int64,npy_int8,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 63 :
			dia_matvec_noomp<npy_int64,npy_int8,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 64 :
			dia_matvec_noomp<npy_int64,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 65 :
			dia_matvec_noomp<npy_int64,npy_int16,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 66 :
			dia_matvec_noomp<npy_int64,npy_int16,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 67 :
			dia_matvec_noomp<npy_int64,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 68 :
			dia_matvec_noomp<npy_int64,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 69 :
			dia_matvec_noomp<npy_int64,npy_int16,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 70 :
			dia_matvec_noomp<npy_int64,npy_int16,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 71 :
			dia_matvec_noomp<npy_int64,npy_int16,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 72 :
			dia_matvec_noomp<npy_int64,npy_int16,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 73 :
			dia_matvec_noomp<npy_int64,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 74 :
			dia_matvec_noomp<npy_int64,npy_int32,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 75 :
			dia_matvec_noomp<npy_int64,npy_int32,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 76 :
			dia_matvec_noomp<npy_int64,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 77 :
			dia_matvec_noomp<npy_int64,npy_int32,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 78 :
			dia_matvec_noomp<npy_int64,npy_int32,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 79 :
			dia_matvec_noomp<npy_int64,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 80 :
			dia_matvec_noomp<npy_int64,npy_int64,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 81 :
			dia_matvec_noomp<npy_int64,npy_int64,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 82 :
			dia_matvec_noomp<npy_int64,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 83 :
			dia_matvec_noomp<npy_int64,npy_int64,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 84 :
			dia_matvec_noomp<npy_int64,npy_int64,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 85 :
			dia_matvec_noomp<npy_int64,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cdouble*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 86 :
			dia_matvec_noomp<npy_int64,cdouble,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cdouble*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 87 :
			dia_matvec_noomp<npy_int64,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cdouble*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 88 :
			dia_matvec_noomp<npy_int64,cdouble,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cdouble*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 89 :
			dia_matvec_noomp<npy_int64,double,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 90 :
			dia_matvec_noomp<npy_int64,double,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 91 :
			dia_matvec_noomp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 92 :
			dia_matvec_noomp<npy_int64,double,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 93 :
			dia_matvec_noomp<npy_int64,double,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 94 :
			dia_matvec_noomp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 95 :
			dia_matvec_noomp<npy_int64,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 96 :
			dia_matvec_noomp<npy_int64,cfloat,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 97 :
			dia_matvec_noomp<npy_int64,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 98 :
			dia_matvec_noomp<npy_int64,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 99 :
			dia_matvec_noomp<npy_int64,cfloat,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 100 :
			dia_matvec_noomp<npy_int64,cfloat,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 101 :
			dia_matvec_noomp<npy_int64,float,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 102 :
			dia_matvec_noomp<npy_int64,float,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 103 :
			dia_matvec_noomp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 104 :
			dia_matvec_noomp<npy_int64,float,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 105 :
			dia_matvec_noomp<npy_int64,float,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 106 :
			dia_matvec_noomp<npy_int64,float,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 107 :
			dia_matvec_noomp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 108 :
			dia_matvec_noomp<npy_int64,float,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 109 :
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
			dia_matvec_omp<npy_int32,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 1 :
			dia_matvec_omp<npy_int32,npy_int8,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 2 :
			dia_matvec_omp<npy_int32,npy_int8,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 3 :
			dia_matvec_omp<npy_int32,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 4 :
			dia_matvec_omp<npy_int32,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 5 :
			dia_matvec_omp<npy_int32,npy_int8,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 6 :
			dia_matvec_omp<npy_int32,npy_int8,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 7 :
			dia_matvec_omp<npy_int32,npy_int8,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 8 :
			dia_matvec_omp<npy_int32,npy_int8,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 9 :
			dia_matvec_omp<npy_int32,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 10 :
			dia_matvec_omp<npy_int32,npy_int16,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 11 :
			dia_matvec_omp<npy_int32,npy_int16,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 12 :
			dia_matvec_omp<npy_int32,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 13 :
			dia_matvec_omp<npy_int32,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 14 :
			dia_matvec_omp<npy_int32,npy_int16,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 15 :
			dia_matvec_omp<npy_int32,npy_int16,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 16 :
			dia_matvec_omp<npy_int32,npy_int16,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 17 :
			dia_matvec_omp<npy_int32,npy_int16,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 18 :
			dia_matvec_omp<npy_int32,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 19 :
			dia_matvec_omp<npy_int32,npy_int32,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 20 :
			dia_matvec_omp<npy_int32,npy_int32,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 21 :
			dia_matvec_omp<npy_int32,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 22 :
			dia_matvec_omp<npy_int32,npy_int32,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 23 :
			dia_matvec_omp<npy_int32,npy_int32,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 24 :
			dia_matvec_omp<npy_int32,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 25 :
			dia_matvec_omp<npy_int32,npy_int64,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 26 :
			dia_matvec_omp<npy_int32,npy_int64,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 27 :
			dia_matvec_omp<npy_int32,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 28 :
			dia_matvec_omp<npy_int32,npy_int64,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 29 :
			dia_matvec_omp<npy_int32,npy_int64,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 30 :
			dia_matvec_omp<npy_int32,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cdouble*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 31 :
			dia_matvec_omp<npy_int32,cdouble,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cdouble*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 32 :
			dia_matvec_omp<npy_int32,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cdouble*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 33 :
			dia_matvec_omp<npy_int32,cdouble,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cdouble*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 34 :
			dia_matvec_omp<npy_int32,double,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 35 :
			dia_matvec_omp<npy_int32,double,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 36 :
			dia_matvec_omp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 37 :
			dia_matvec_omp<npy_int32,double,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 38 :
			dia_matvec_omp<npy_int32,double,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 39 :
			dia_matvec_omp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 40 :
			dia_matvec_omp<npy_int32,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 41 :
			dia_matvec_omp<npy_int32,cfloat,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 42 :
			dia_matvec_omp<npy_int32,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 43 :
			dia_matvec_omp<npy_int32,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 44 :
			dia_matvec_omp<npy_int32,cfloat,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 45 :
			dia_matvec_omp<npy_int32,cfloat,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 46 :
			dia_matvec_omp<npy_int32,float,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 47 :
			dia_matvec_omp<npy_int32,float,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 48 :
			dia_matvec_omp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 49 :
			dia_matvec_omp<npy_int32,float,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 50 :
			dia_matvec_omp<npy_int32,float,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 51 :
			dia_matvec_omp<npy_int32,float,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 52 :
			dia_matvec_omp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 53 :
			dia_matvec_omp<npy_int32,float,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 54 :
			dia_matvec_omp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 55 :
			dia_matvec_omp<npy_int64,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 56 :
			dia_matvec_omp<npy_int64,npy_int8,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 57 :
			dia_matvec_omp<npy_int64,npy_int8,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 58 :
			dia_matvec_omp<npy_int64,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 59 :
			dia_matvec_omp<npy_int64,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 60 :
			dia_matvec_omp<npy_int64,npy_int8,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 61 :
			dia_matvec_omp<npy_int64,npy_int8,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 62 :
			dia_matvec_omp<npy_int64,npy_int8,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 63 :
			dia_matvec_omp<npy_int64,npy_int8,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 64 :
			dia_matvec_omp<npy_int64,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 65 :
			dia_matvec_omp<npy_int64,npy_int16,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 66 :
			dia_matvec_omp<npy_int64,npy_int16,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 67 :
			dia_matvec_omp<npy_int64,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 68 :
			dia_matvec_omp<npy_int64,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 69 :
			dia_matvec_omp<npy_int64,npy_int16,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 70 :
			dia_matvec_omp<npy_int64,npy_int16,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 71 :
			dia_matvec_omp<npy_int64,npy_int16,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 72 :
			dia_matvec_omp<npy_int64,npy_int16,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_byte,(const float*)x,y_stride_byte,(float*)y);
			break;
		case 73 :
			dia_matvec_omp<npy_int64,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 74 :
			dia_matvec_omp<npy_int64,npy_int32,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 75 :
			dia_matvec_omp<npy_int64,npy_int32,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 76 :
			dia_matvec_omp<npy_int64,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 77 :
			dia_matvec_omp<npy_int64,npy_int32,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 78 :
			dia_matvec_omp<npy_int64,npy_int32,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 79 :
			dia_matvec_omp<npy_int64,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 80 :
			dia_matvec_omp<npy_int64,npy_int64,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 81 :
			dia_matvec_omp<npy_int64,npy_int64,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 82 :
			dia_matvec_omp<npy_int64,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 83 :
			dia_matvec_omp<npy_int64,npy_int64,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 84 :
			dia_matvec_omp<npy_int64,npy_int64,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 85 :
			dia_matvec_omp<npy_int64,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cdouble*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 86 :
			dia_matvec_omp<npy_int64,cdouble,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cdouble*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 87 :
			dia_matvec_omp<npy_int64,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cdouble*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 88 :
			dia_matvec_omp<npy_int64,cdouble,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cdouble*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 89 :
			dia_matvec_omp<npy_int64,double,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 90 :
			dia_matvec_omp<npy_int64,double,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 91 :
			dia_matvec_omp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 92 :
			dia_matvec_omp<npy_int64,double,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 93 :
			dia_matvec_omp<npy_int64,double,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 94 :
			dia_matvec_omp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 95 :
			dia_matvec_omp<npy_int64,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 96 :
			dia_matvec_omp<npy_int64,cfloat,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 97 :
			dia_matvec_omp<npy_int64,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 98 :
			dia_matvec_omp<npy_int64,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 99 :
			dia_matvec_omp<npy_int64,cfloat,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 100 :
			dia_matvec_omp<npy_int64,cfloat,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 101 :
			dia_matvec_omp<npy_int64,float,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const cdouble*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 102 :
			dia_matvec_omp<npy_int64,float,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const double*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 103 :
			dia_matvec_omp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const double*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 104 :
			dia_matvec_omp<npy_int64,float,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const cfloat*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 105 :
			dia_matvec_omp<npy_int64,float,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const cfloat*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 106 :
			dia_matvec_omp<npy_int64,float,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const cdouble*)x,y_stride_byte,(cdouble*)y);
			break;
		case 107 :
			dia_matvec_omp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const double*)x,y_stride_byte,(double*)y);
			break;
		case 108 :
			dia_matvec_omp<npy_int64,float,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_byte,(const cfloat*)x,y_stride_byte,(cfloat*)y);
			break;
		case 109 :
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
			dia_matvecs_noomp<npy_int32,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 1 :
			dia_matvecs_noomp<npy_int32,npy_int8,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 2 :
			dia_matvecs_noomp<npy_int32,npy_int8,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 3 :
			dia_matvecs_noomp<npy_int32,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 4 :
			dia_matvecs_noomp<npy_int32,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 5 :
			dia_matvecs_noomp<npy_int32,npy_int8,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 6 :
			dia_matvecs_noomp<npy_int32,npy_int8,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 7 :
			dia_matvecs_noomp<npy_int32,npy_int8,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 8 :
			dia_matvecs_noomp<npy_int32,npy_int8,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 9 :
			dia_matvecs_noomp<npy_int32,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 10 :
			dia_matvecs_noomp<npy_int32,npy_int16,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 11 :
			dia_matvecs_noomp<npy_int32,npy_int16,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 12 :
			dia_matvecs_noomp<npy_int32,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 13 :
			dia_matvecs_noomp<npy_int32,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 14 :
			dia_matvecs_noomp<npy_int32,npy_int16,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 15 :
			dia_matvecs_noomp<npy_int32,npy_int16,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 16 :
			dia_matvecs_noomp<npy_int32,npy_int16,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 17 :
			dia_matvecs_noomp<npy_int32,npy_int16,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 18 :
			dia_matvecs_noomp<npy_int32,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 19 :
			dia_matvecs_noomp<npy_int32,npy_int32,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 20 :
			dia_matvecs_noomp<npy_int32,npy_int32,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 21 :
			dia_matvecs_noomp<npy_int32,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 22 :
			dia_matvecs_noomp<npy_int32,npy_int32,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 23 :
			dia_matvecs_noomp<npy_int32,npy_int32,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 24 :
			dia_matvecs_noomp<npy_int32,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 25 :
			dia_matvecs_noomp<npy_int32,npy_int64,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 26 :
			dia_matvecs_noomp<npy_int32,npy_int64,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 27 :
			dia_matvecs_noomp<npy_int32,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 28 :
			dia_matvecs_noomp<npy_int32,npy_int64,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 29 :
			dia_matvecs_noomp<npy_int32,npy_int64,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 30 :
			dia_matvecs_noomp<npy_int32,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cdouble*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 31 :
			dia_matvecs_noomp<npy_int32,cdouble,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cdouble*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 32 :
			dia_matvecs_noomp<npy_int32,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cdouble*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 33 :
			dia_matvecs_noomp<npy_int32,cdouble,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cdouble*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 34 :
			dia_matvecs_noomp<npy_int32,double,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 35 :
			dia_matvecs_noomp<npy_int32,double,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 36 :
			dia_matvecs_noomp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 37 :
			dia_matvecs_noomp<npy_int32,double,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 38 :
			dia_matvecs_noomp<npy_int32,double,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 39 :
			dia_matvecs_noomp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 40 :
			dia_matvecs_noomp<npy_int32,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 41 :
			dia_matvecs_noomp<npy_int32,cfloat,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 42 :
			dia_matvecs_noomp<npy_int32,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 43 :
			dia_matvecs_noomp<npy_int32,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 44 :
			dia_matvecs_noomp<npy_int32,cfloat,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 45 :
			dia_matvecs_noomp<npy_int32,cfloat,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 46 :
			dia_matvecs_noomp<npy_int32,float,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 47 :
			dia_matvecs_noomp<npy_int32,float,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 48 :
			dia_matvecs_noomp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 49 :
			dia_matvecs_noomp<npy_int32,float,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 50 :
			dia_matvecs_noomp<npy_int32,float,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 51 :
			dia_matvecs_noomp<npy_int32,float,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 52 :
			dia_matvecs_noomp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 53 :
			dia_matvecs_noomp<npy_int32,float,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 54 :
			dia_matvecs_noomp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 55 :
			dia_matvecs_noomp<npy_int64,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 56 :
			dia_matvecs_noomp<npy_int64,npy_int8,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 57 :
			dia_matvecs_noomp<npy_int64,npy_int8,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 58 :
			dia_matvecs_noomp<npy_int64,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 59 :
			dia_matvecs_noomp<npy_int64,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 60 :
			dia_matvecs_noomp<npy_int64,npy_int8,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 61 :
			dia_matvecs_noomp<npy_int64,npy_int8,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 62 :
			dia_matvecs_noomp<npy_int64,npy_int8,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 63 :
			dia_matvecs_noomp<npy_int64,npy_int8,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 64 :
			dia_matvecs_noomp<npy_int64,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 65 :
			dia_matvecs_noomp<npy_int64,npy_int16,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 66 :
			dia_matvecs_noomp<npy_int64,npy_int16,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 67 :
			dia_matvecs_noomp<npy_int64,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 68 :
			dia_matvecs_noomp<npy_int64,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 69 :
			dia_matvecs_noomp<npy_int64,npy_int16,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 70 :
			dia_matvecs_noomp<npy_int64,npy_int16,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 71 :
			dia_matvecs_noomp<npy_int64,npy_int16,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 72 :
			dia_matvecs_noomp<npy_int64,npy_int16,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 73 :
			dia_matvecs_noomp<npy_int64,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 74 :
			dia_matvecs_noomp<npy_int64,npy_int32,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 75 :
			dia_matvecs_noomp<npy_int64,npy_int32,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 76 :
			dia_matvecs_noomp<npy_int64,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 77 :
			dia_matvecs_noomp<npy_int64,npy_int32,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 78 :
			dia_matvecs_noomp<npy_int64,npy_int32,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 79 :
			dia_matvecs_noomp<npy_int64,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 80 :
			dia_matvecs_noomp<npy_int64,npy_int64,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 81 :
			dia_matvecs_noomp<npy_int64,npy_int64,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 82 :
			dia_matvecs_noomp<npy_int64,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 83 :
			dia_matvecs_noomp<npy_int64,npy_int64,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 84 :
			dia_matvecs_noomp<npy_int64,npy_int64,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 85 :
			dia_matvecs_noomp<npy_int64,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cdouble*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 86 :
			dia_matvecs_noomp<npy_int64,cdouble,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cdouble*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 87 :
			dia_matvecs_noomp<npy_int64,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cdouble*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 88 :
			dia_matvecs_noomp<npy_int64,cdouble,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cdouble*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 89 :
			dia_matvecs_noomp<npy_int64,double,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 90 :
			dia_matvecs_noomp<npy_int64,double,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 91 :
			dia_matvecs_noomp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 92 :
			dia_matvecs_noomp<npy_int64,double,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 93 :
			dia_matvecs_noomp<npy_int64,double,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 94 :
			dia_matvecs_noomp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 95 :
			dia_matvecs_noomp<npy_int64,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 96 :
			dia_matvecs_noomp<npy_int64,cfloat,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 97 :
			dia_matvecs_noomp<npy_int64,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 98 :
			dia_matvecs_noomp<npy_int64,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 99 :
			dia_matvecs_noomp<npy_int64,cfloat,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 100 :
			dia_matvecs_noomp<npy_int64,cfloat,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 101 :
			dia_matvecs_noomp<npy_int64,float,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 102 :
			dia_matvecs_noomp<npy_int64,float,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 103 :
			dia_matvecs_noomp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 104 :
			dia_matvecs_noomp<npy_int64,float,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 105 :
			dia_matvecs_noomp<npy_int64,float,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 106 :
			dia_matvecs_noomp<npy_int64,float,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 107 :
			dia_matvecs_noomp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 108 :
			dia_matvecs_noomp<npy_int64,float,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 109 :
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
			dia_matvecs_omp<npy_int32,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 1 :
			dia_matvecs_omp<npy_int32,npy_int8,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 2 :
			dia_matvecs_omp<npy_int32,npy_int8,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 3 :
			dia_matvecs_omp<npy_int32,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 4 :
			dia_matvecs_omp<npy_int32,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 5 :
			dia_matvecs_omp<npy_int32,npy_int8,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 6 :
			dia_matvecs_omp<npy_int32,npy_int8,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 7 :
			dia_matvecs_omp<npy_int32,npy_int8,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 8 :
			dia_matvecs_omp<npy_int32,npy_int8,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 9 :
			dia_matvecs_omp<npy_int32,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 10 :
			dia_matvecs_omp<npy_int32,npy_int16,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 11 :
			dia_matvecs_omp<npy_int32,npy_int16,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 12 :
			dia_matvecs_omp<npy_int32,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 13 :
			dia_matvecs_omp<npy_int32,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 14 :
			dia_matvecs_omp<npy_int32,npy_int16,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 15 :
			dia_matvecs_omp<npy_int32,npy_int16,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 16 :
			dia_matvecs_omp<npy_int32,npy_int16,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 17 :
			dia_matvecs_omp<npy_int32,npy_int16,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 18 :
			dia_matvecs_omp<npy_int32,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 19 :
			dia_matvecs_omp<npy_int32,npy_int32,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 20 :
			dia_matvecs_omp<npy_int32,npy_int32,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 21 :
			dia_matvecs_omp<npy_int32,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 22 :
			dia_matvecs_omp<npy_int32,npy_int32,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 23 :
			dia_matvecs_omp<npy_int32,npy_int32,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int32*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 24 :
			dia_matvecs_omp<npy_int32,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 25 :
			dia_matvecs_omp<npy_int32,npy_int64,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 26 :
			dia_matvecs_omp<npy_int32,npy_int64,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 27 :
			dia_matvecs_omp<npy_int32,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 28 :
			dia_matvecs_omp<npy_int32,npy_int64,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 29 :
			dia_matvecs_omp<npy_int32,npy_int64,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const npy_int64*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 30 :
			dia_matvecs_omp<npy_int32,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cdouble*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 31 :
			dia_matvecs_omp<npy_int32,cdouble,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cdouble*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 32 :
			dia_matvecs_omp<npy_int32,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cdouble*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 33 :
			dia_matvecs_omp<npy_int32,cdouble,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cdouble*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 34 :
			dia_matvecs_omp<npy_int32,double,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 35 :
			dia_matvecs_omp<npy_int32,double,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 36 :
			dia_matvecs_omp<npy_int32,double,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 37 :
			dia_matvecs_omp<npy_int32,double,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 38 :
			dia_matvecs_omp<npy_int32,double,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 39 :
			dia_matvecs_omp<npy_int32,double,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const double*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 40 :
			dia_matvecs_omp<npy_int32,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 41 :
			dia_matvecs_omp<npy_int32,cfloat,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 42 :
			dia_matvecs_omp<npy_int32,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 43 :
			dia_matvecs_omp<npy_int32,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 44 :
			dia_matvecs_omp<npy_int32,cfloat,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 45 :
			dia_matvecs_omp<npy_int32,cfloat,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const cfloat*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 46 :
			dia_matvecs_omp<npy_int32,float,cdouble,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 47 :
			dia_matvecs_omp<npy_int32,float,double,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 48 :
			dia_matvecs_omp<npy_int32,float,double,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 49 :
			dia_matvecs_omp<npy_int32,float,cfloat,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 50 :
			dia_matvecs_omp<npy_int32,float,cfloat,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 51 :
			dia_matvecs_omp<npy_int32,float,float,cdouble>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 52 :
			dia_matvecs_omp<npy_int32,float,float,double>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 53 :
			dia_matvecs_omp<npy_int32,float,float,cfloat>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 54 :
			dia_matvecs_omp<npy_int32,float,float,float>(overwrite_y,(const npy_int32)n_row,(const npy_int32)n_col,n_vecs,(const npy_int32)n_diags,(const npy_int32)L,(const npy_int32*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 55 :
			dia_matvecs_omp<npy_int64,npy_int8,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 56 :
			dia_matvecs_omp<npy_int64,npy_int8,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 57 :
			dia_matvecs_omp<npy_int64,npy_int8,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 58 :
			dia_matvecs_omp<npy_int64,npy_int8,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 59 :
			dia_matvecs_omp<npy_int64,npy_int8,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 60 :
			dia_matvecs_omp<npy_int64,npy_int8,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 61 :
			dia_matvecs_omp<npy_int64,npy_int8,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 62 :
			dia_matvecs_omp<npy_int64,npy_int8,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 63 :
			dia_matvecs_omp<npy_int64,npy_int8,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int8*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 64 :
			dia_matvecs_omp<npy_int64,npy_int16,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 65 :
			dia_matvecs_omp<npy_int64,npy_int16,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 66 :
			dia_matvecs_omp<npy_int64,npy_int16,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 67 :
			dia_matvecs_omp<npy_int64,npy_int16,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 68 :
			dia_matvecs_omp<npy_int64,npy_int16,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 69 :
			dia_matvecs_omp<npy_int64,npy_int16,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 70 :
			dia_matvecs_omp<npy_int64,npy_int16,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 71 :
			dia_matvecs_omp<npy_int64,npy_int16,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 72 :
			dia_matvecs_omp<npy_int64,npy_int16,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int16*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
		case 73 :
			dia_matvecs_omp<npy_int64,npy_int32,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 74 :
			dia_matvecs_omp<npy_int64,npy_int32,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 75 :
			dia_matvecs_omp<npy_int64,npy_int32,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 76 :
			dia_matvecs_omp<npy_int64,npy_int32,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 77 :
			dia_matvecs_omp<npy_int64,npy_int32,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 78 :
			dia_matvecs_omp<npy_int64,npy_int32,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int32*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 79 :
			dia_matvecs_omp<npy_int64,npy_int64,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 80 :
			dia_matvecs_omp<npy_int64,npy_int64,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 81 :
			dia_matvecs_omp<npy_int64,npy_int64,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 82 :
			dia_matvecs_omp<npy_int64,npy_int64,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 83 :
			dia_matvecs_omp<npy_int64,npy_int64,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 84 :
			dia_matvecs_omp<npy_int64,npy_int64,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const npy_int64*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 85 :
			dia_matvecs_omp<npy_int64,cdouble,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cdouble*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 86 :
			dia_matvecs_omp<npy_int64,cdouble,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cdouble*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 87 :
			dia_matvecs_omp<npy_int64,cdouble,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cdouble*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 88 :
			dia_matvecs_omp<npy_int64,cdouble,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cdouble*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 89 :
			dia_matvecs_omp<npy_int64,double,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 90 :
			dia_matvecs_omp<npy_int64,double,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 91 :
			dia_matvecs_omp<npy_int64,double,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 92 :
			dia_matvecs_omp<npy_int64,double,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 93 :
			dia_matvecs_omp<npy_int64,double,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 94 :
			dia_matvecs_omp<npy_int64,double,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const double*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 95 :
			dia_matvecs_omp<npy_int64,cfloat,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 96 :
			dia_matvecs_omp<npy_int64,cfloat,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 97 :
			dia_matvecs_omp<npy_int64,cfloat,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 98 :
			dia_matvecs_omp<npy_int64,cfloat,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 99 :
			dia_matvecs_omp<npy_int64,cfloat,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 100 :
			dia_matvecs_omp<npy_int64,cfloat,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const cfloat*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 101 :
			dia_matvecs_omp<npy_int64,float,cdouble,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const cdouble*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 102 :
			dia_matvecs_omp<npy_int64,float,double,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 103 :
			dia_matvecs_omp<npy_int64,float,double,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const double*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 104 :
			dia_matvecs_omp<npy_int64,float,cfloat,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 105 :
			dia_matvecs_omp<npy_int64,float,cfloat,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const cfloat*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 106 :
			dia_matvecs_omp<npy_int64,float,float,cdouble>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cdouble*)x,y_stride_row_byte,y_stride_col_byte,(cdouble*)y);
			break;
		case 107 :
			dia_matvecs_omp<npy_int64,float,float,double>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const double*)x,y_stride_row_byte,y_stride_col_byte,(double*)y);
			break;
		case 108 :
			dia_matvecs_omp<npy_int64,float,float,cfloat>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const cfloat*)x,y_stride_row_byte,y_stride_col_byte,(cfloat*)y);
			break;
		case 109 :
			dia_matvecs_omp<npy_int64,float,float,float>(overwrite_y,(const npy_int64)n_row,(const npy_int64)n_col,n_vecs,(const npy_int64)n_diags,(const npy_int64)L,(const npy_int64*)offsets,(const float*)diags,*(const float*)a,x_stride_row_byte,x_stride_col_byte,(const float*)x,y_stride_row_byte,y_stride_col_byte,(float*)y);
			break;
	    default:
	        throw std::runtime_error("internal error: invalid argument typenums");
	}
}
#endif