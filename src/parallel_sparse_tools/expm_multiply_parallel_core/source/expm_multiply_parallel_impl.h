#ifndef __EXPM_MULTIPLY_PARALLEL_IMPL_H__
#define __EXPM_MULTIPLY_PARALLEL_IMPL_H__

#include "numpy/ndarrayobject.h"
#include "numpy/ndarraytypes.h"
#include "expm_multiply_parallel.h"

inline bool EquivTypes(PyArray_Descr * dtype1,PyArray_Descr * dtype2){
	return PyArray_EquivTypes(dtype1,dtype2);
}



#include <iostream>

int get_switch_expm_multiply(PyArray_Descr * dtype1,PyArray_Descr * dtype2,PyArray_Descr * dtype3,PyArray_Descr * dtype4){
    int I = dtype1->type_num;
    int T1 = dtype2->type_num;
    int T2 = dtype3->type_num;
    int T3 = dtype4->type_num;
    
    if(0){}
	else if(PyArray_EquivTypenums(I,NPY_INT32)){
		if(0){}
		else if(T1 == NPY_COMPLEX128 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 0;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 1;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 2;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 3;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX64){return 4;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 5;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 6;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX64){return 7;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT32){return 8;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 9;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 10;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX64){return 11;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT32){return 12;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 13;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 14;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX64){return 15;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT32){return 16;}
		else {return -1;}
	}
	else if(PyArray_EquivTypenums(I,NPY_INT64)){
		if(0){}
		else if(T1 == NPY_COMPLEX128 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 17;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 18;}
		else if(T1 == NPY_FLOAT64 && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 19;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 20;}
		else if(T1 == NPY_COMPLEX64 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX64){return 21;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 22;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 23;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX64){return 24;}
		else if(T1 == NPY_FLOAT32 && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT32){return 25;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 26;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 27;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX64){return 28;}
		else if(PyArray_EquivTypenums(T1,NPY_INT16) && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT32){return 29;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_FLOAT64 && T3 == NPY_COMPLEX128){return 30;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_FLOAT64 && T3 == NPY_FLOAT64){return 31;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_FLOAT32 && T3 == NPY_COMPLEX64){return 32;}
		else if(PyArray_EquivTypenums(T1,NPY_INT8) && T2 == NPY_FLOAT32 && T3 == NPY_FLOAT32){return 33;}
		else {return -1;}
	}
	else {return -1;}

    return -1;
}

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

{
    switch(switch_num){
		case 0 :
			expm_multiply<npy_int32,cdouble,double,cdouble>(static_cast<const npy_int32>(n),reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const cdouble*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 1 :
			expm_multiply<npy_int32,double,double,cdouble>(static_cast<const npy_int32>(n),reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const double*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 2 :
			expm_multiply<npy_int32,double,double,double>(static_cast<const npy_int32>(n),reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const double*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const double*>(mu),*reinterpret_cast<const double*>(a),reinterpret_cast<double*>(F),reinterpret_cast<double*>(work));
			break;
		case 3 :
			expm_multiply<npy_int32,cfloat,double,cdouble>(static_cast<const npy_int32>(n),reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const cfloat*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 4 :
			expm_multiply<npy_int32,cfloat,float,cfloat>(static_cast<const npy_int32>(n),reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const cfloat*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const cfloat*>(mu),*reinterpret_cast<const cfloat*>(a),reinterpret_cast<cfloat*>(F),reinterpret_cast<cfloat*>(work));
			break;
		case 5 :
			expm_multiply<npy_int32,float,double,cdouble>(static_cast<const npy_int32>(n),reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const float*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 6 :
			expm_multiply<npy_int32,float,double,double>(static_cast<const npy_int32>(n),reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const float*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const double*>(mu),*reinterpret_cast<const double*>(a),reinterpret_cast<double*>(F),reinterpret_cast<double*>(work));
			break;
		case 7 :
			expm_multiply<npy_int32,float,float,cfloat>(static_cast<const npy_int32>(n),reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const float*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const cfloat*>(mu),*reinterpret_cast<const cfloat*>(a),reinterpret_cast<cfloat*>(F),reinterpret_cast<cfloat*>(work));
			break;
		case 8 :
			expm_multiply<npy_int32,float,float,float>(static_cast<const npy_int32>(n),reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const float*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const float*>(mu),*reinterpret_cast<const float*>(a),reinterpret_cast<float*>(F),reinterpret_cast<float*>(work));
			break;
		case 9 :
			expm_multiply<npy_int32,npy_int16,double,cdouble>(static_cast<const npy_int32>(n),reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const npy_int16*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 10 :
			expm_multiply<npy_int32,npy_int16,double,double>(static_cast<const npy_int32>(n),reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const npy_int16*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const double*>(mu),*reinterpret_cast<const double*>(a),reinterpret_cast<double*>(F),reinterpret_cast<double*>(work));
			break;
		case 11 :
			expm_multiply<npy_int32,npy_int16,float,cfloat>(static_cast<const npy_int32>(n),reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const npy_int16*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const cfloat*>(mu),*reinterpret_cast<const cfloat*>(a),reinterpret_cast<cfloat*>(F),reinterpret_cast<cfloat*>(work));
			break;
		case 12 :
			expm_multiply<npy_int32,npy_int16,float,float>(static_cast<const npy_int32>(n),reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const npy_int16*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const float*>(mu),*reinterpret_cast<const float*>(a),reinterpret_cast<float*>(F),reinterpret_cast<float*>(work));
			break;
		case 13 :
			expm_multiply<npy_int32,npy_int8,double,cdouble>(static_cast<const npy_int32>(n),reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const npy_int8*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 14 :
			expm_multiply<npy_int32,npy_int8,double,double>(static_cast<const npy_int32>(n),reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const npy_int8*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const double*>(mu),*reinterpret_cast<const double*>(a),reinterpret_cast<double*>(F),reinterpret_cast<double*>(work));
			break;
		case 15 :
			expm_multiply<npy_int32,npy_int8,float,cfloat>(static_cast<const npy_int32>(n),reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const npy_int8*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const cfloat*>(mu),*reinterpret_cast<const cfloat*>(a),reinterpret_cast<cfloat*>(F),reinterpret_cast<cfloat*>(work));
			break;
		case 16 :
			expm_multiply<npy_int32,npy_int8,float,float>(static_cast<const npy_int32>(n),reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const npy_int8*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const float*>(mu),*reinterpret_cast<const float*>(a),reinterpret_cast<float*>(F),reinterpret_cast<float*>(work));
			break;
		case 17 :
			expm_multiply<npy_int64,cdouble,double,cdouble>(static_cast<const npy_int64>(n),reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const cdouble*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 18 :
			expm_multiply<npy_int64,double,double,cdouble>(static_cast<const npy_int64>(n),reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const double*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 19 :
			expm_multiply<npy_int64,double,double,double>(static_cast<const npy_int64>(n),reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const double*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const double*>(mu),*reinterpret_cast<const double*>(a),reinterpret_cast<double*>(F),reinterpret_cast<double*>(work));
			break;
		case 20 :
			expm_multiply<npy_int64,cfloat,double,cdouble>(static_cast<const npy_int64>(n),reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const cfloat*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 21 :
			expm_multiply<npy_int64,cfloat,float,cfloat>(static_cast<const npy_int64>(n),reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const cfloat*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const cfloat*>(mu),*reinterpret_cast<const cfloat*>(a),reinterpret_cast<cfloat*>(F),reinterpret_cast<cfloat*>(work));
			break;
		case 22 :
			expm_multiply<npy_int64,float,double,cdouble>(static_cast<const npy_int64>(n),reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const float*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 23 :
			expm_multiply<npy_int64,float,double,double>(static_cast<const npy_int64>(n),reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const float*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const double*>(mu),*reinterpret_cast<const double*>(a),reinterpret_cast<double*>(F),reinterpret_cast<double*>(work));
			break;
		case 24 :
			expm_multiply<npy_int64,float,float,cfloat>(static_cast<const npy_int64>(n),reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const float*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const cfloat*>(mu),*reinterpret_cast<const cfloat*>(a),reinterpret_cast<cfloat*>(F),reinterpret_cast<cfloat*>(work));
			break;
		case 25 :
			expm_multiply<npy_int64,float,float,float>(static_cast<const npy_int64>(n),reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const float*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const float*>(mu),*reinterpret_cast<const float*>(a),reinterpret_cast<float*>(F),reinterpret_cast<float*>(work));
			break;
		case 26 :
			expm_multiply<npy_int64,npy_int16,double,cdouble>(static_cast<const npy_int64>(n),reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const npy_int16*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 27 :
			expm_multiply<npy_int64,npy_int16,double,double>(static_cast<const npy_int64>(n),reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const npy_int16*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const double*>(mu),*reinterpret_cast<const double*>(a),reinterpret_cast<double*>(F),reinterpret_cast<double*>(work));
			break;
		case 28 :
			expm_multiply<npy_int64,npy_int16,float,cfloat>(static_cast<const npy_int64>(n),reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const npy_int16*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const cfloat*>(mu),*reinterpret_cast<const cfloat*>(a),reinterpret_cast<cfloat*>(F),reinterpret_cast<cfloat*>(work));
			break;
		case 29 :
			expm_multiply<npy_int64,npy_int16,float,float>(static_cast<const npy_int64>(n),reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const npy_int16*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const float*>(mu),*reinterpret_cast<const float*>(a),reinterpret_cast<float*>(F),reinterpret_cast<float*>(work));
			break;
		case 30 :
			expm_multiply<npy_int64,npy_int8,double,cdouble>(static_cast<const npy_int64>(n),reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const npy_int8*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 31 :
			expm_multiply<npy_int64,npy_int8,double,double>(static_cast<const npy_int64>(n),reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const npy_int8*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const double*>(mu),*reinterpret_cast<const double*>(a),reinterpret_cast<double*>(F),reinterpret_cast<double*>(work));
			break;
		case 32 :
			expm_multiply<npy_int64,npy_int8,float,cfloat>(static_cast<const npy_int64>(n),reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const npy_int8*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const cfloat*>(mu),*reinterpret_cast<const cfloat*>(a),reinterpret_cast<cfloat*>(F),reinterpret_cast<cfloat*>(work));
			break;
		case 33 :
			expm_multiply<npy_int64,npy_int8,float,float>(static_cast<const npy_int64>(n),reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const npy_int8*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const float*>(mu),*reinterpret_cast<const float*>(a),reinterpret_cast<float*>(F),reinterpret_cast<float*>(work));
			break;
        default:
            throw std::runtime_error("internal error: invalid argument typenums");
    }    
}

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

{
    switch(switch_num){
		case 0 :
			expm_multiply_batch<npy_int32,cdouble,double,cdouble>(static_cast<const npy_int32>(n),n_vecs,reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const cdouble*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 1 :
			expm_multiply_batch<npy_int32,double,double,cdouble>(static_cast<const npy_int32>(n),n_vecs,reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const double*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 2 :
			expm_multiply_batch<npy_int32,double,double,double>(static_cast<const npy_int32>(n),n_vecs,reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const double*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const double*>(mu),*reinterpret_cast<const double*>(a),reinterpret_cast<double*>(F),reinterpret_cast<double*>(work));
			break;
		case 3 :
			expm_multiply_batch<npy_int32,cfloat,double,cdouble>(static_cast<const npy_int32>(n),n_vecs,reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const cfloat*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 4 :
			expm_multiply_batch<npy_int32,cfloat,float,cfloat>(static_cast<const npy_int32>(n),n_vecs,reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const cfloat*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const cfloat*>(mu),*reinterpret_cast<const cfloat*>(a),reinterpret_cast<cfloat*>(F),reinterpret_cast<cfloat*>(work));
			break;
		case 5 :
			expm_multiply_batch<npy_int32,float,double,cdouble>(static_cast<const npy_int32>(n),n_vecs,reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const float*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 6 :
			expm_multiply_batch<npy_int32,float,double,double>(static_cast<const npy_int32>(n),n_vecs,reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const float*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const double*>(mu),*reinterpret_cast<const double*>(a),reinterpret_cast<double*>(F),reinterpret_cast<double*>(work));
			break;
		case 7 :
			expm_multiply_batch<npy_int32,float,float,cfloat>(static_cast<const npy_int32>(n),n_vecs,reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const float*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const cfloat*>(mu),*reinterpret_cast<const cfloat*>(a),reinterpret_cast<cfloat*>(F),reinterpret_cast<cfloat*>(work));
			break;
		case 8 :
			expm_multiply_batch<npy_int32,float,float,float>(static_cast<const npy_int32>(n),n_vecs,reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const float*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const float*>(mu),*reinterpret_cast<const float*>(a),reinterpret_cast<float*>(F),reinterpret_cast<float*>(work));
			break;
		case 9 :
			expm_multiply_batch<npy_int32,npy_int16,double,cdouble>(static_cast<const npy_int32>(n),n_vecs,reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const npy_int16*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 10 :
			expm_multiply_batch<npy_int32,npy_int16,double,double>(static_cast<const npy_int32>(n),n_vecs,reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const npy_int16*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const double*>(mu),*reinterpret_cast<const double*>(a),reinterpret_cast<double*>(F),reinterpret_cast<double*>(work));
			break;
		case 11 :
			expm_multiply_batch<npy_int32,npy_int16,float,cfloat>(static_cast<const npy_int32>(n),n_vecs,reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const npy_int16*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const cfloat*>(mu),*reinterpret_cast<const cfloat*>(a),reinterpret_cast<cfloat*>(F),reinterpret_cast<cfloat*>(work));
			break;
		case 12 :
			expm_multiply_batch<npy_int32,npy_int16,float,float>(static_cast<const npy_int32>(n),n_vecs,reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const npy_int16*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const float*>(mu),*reinterpret_cast<const float*>(a),reinterpret_cast<float*>(F),reinterpret_cast<float*>(work));
			break;
		case 13 :
			expm_multiply_batch<npy_int32,npy_int8,double,cdouble>(static_cast<const npy_int32>(n),n_vecs,reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const npy_int8*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 14 :
			expm_multiply_batch<npy_int32,npy_int8,double,double>(static_cast<const npy_int32>(n),n_vecs,reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const npy_int8*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const double*>(mu),*reinterpret_cast<const double*>(a),reinterpret_cast<double*>(F),reinterpret_cast<double*>(work));
			break;
		case 15 :
			expm_multiply_batch<npy_int32,npy_int8,float,cfloat>(static_cast<const npy_int32>(n),n_vecs,reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const npy_int8*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const cfloat*>(mu),*reinterpret_cast<const cfloat*>(a),reinterpret_cast<cfloat*>(F),reinterpret_cast<cfloat*>(work));
			break;
		case 16 :
			expm_multiply_batch<npy_int32,npy_int8,float,float>(static_cast<const npy_int32>(n),n_vecs,reinterpret_cast<const npy_int32*>(Ap),reinterpret_cast<const npy_int32*>(Aj),reinterpret_cast<const npy_int8*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const float*>(mu),*reinterpret_cast<const float*>(a),reinterpret_cast<float*>(F),reinterpret_cast<float*>(work));
			break;
		case 17 :
			expm_multiply_batch<npy_int64,cdouble,double,cdouble>(static_cast<const npy_int64>(n),n_vecs,reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const cdouble*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 18 :
			expm_multiply_batch<npy_int64,double,double,cdouble>(static_cast<const npy_int64>(n),n_vecs,reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const double*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 19 :
			expm_multiply_batch<npy_int64,double,double,double>(static_cast<const npy_int64>(n),n_vecs,reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const double*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const double*>(mu),*reinterpret_cast<const double*>(a),reinterpret_cast<double*>(F),reinterpret_cast<double*>(work));
			break;
		case 20 :
			expm_multiply_batch<npy_int64,cfloat,double,cdouble>(static_cast<const npy_int64>(n),n_vecs,reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const cfloat*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 21 :
			expm_multiply_batch<npy_int64,cfloat,float,cfloat>(static_cast<const npy_int64>(n),n_vecs,reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const cfloat*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const cfloat*>(mu),*reinterpret_cast<const cfloat*>(a),reinterpret_cast<cfloat*>(F),reinterpret_cast<cfloat*>(work));
			break;
		case 22 :
			expm_multiply_batch<npy_int64,float,double,cdouble>(static_cast<const npy_int64>(n),n_vecs,reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const float*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 23 :
			expm_multiply_batch<npy_int64,float,double,double>(static_cast<const npy_int64>(n),n_vecs,reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const float*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const double*>(mu),*reinterpret_cast<const double*>(a),reinterpret_cast<double*>(F),reinterpret_cast<double*>(work));
			break;
		case 24 :
			expm_multiply_batch<npy_int64,float,float,cfloat>(static_cast<const npy_int64>(n),n_vecs,reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const float*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const cfloat*>(mu),*reinterpret_cast<const cfloat*>(a),reinterpret_cast<cfloat*>(F),reinterpret_cast<cfloat*>(work));
			break;
		case 25 :
			expm_multiply_batch<npy_int64,float,float,float>(static_cast<const npy_int64>(n),n_vecs,reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const float*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const float*>(mu),*reinterpret_cast<const float*>(a),reinterpret_cast<float*>(F),reinterpret_cast<float*>(work));
			break;
		case 26 :
			expm_multiply_batch<npy_int64,npy_int16,double,cdouble>(static_cast<const npy_int64>(n),n_vecs,reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const npy_int16*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 27 :
			expm_multiply_batch<npy_int64,npy_int16,double,double>(static_cast<const npy_int64>(n),n_vecs,reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const npy_int16*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const double*>(mu),*reinterpret_cast<const double*>(a),reinterpret_cast<double*>(F),reinterpret_cast<double*>(work));
			break;
		case 28 :
			expm_multiply_batch<npy_int64,npy_int16,float,cfloat>(static_cast<const npy_int64>(n),n_vecs,reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const npy_int16*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const cfloat*>(mu),*reinterpret_cast<const cfloat*>(a),reinterpret_cast<cfloat*>(F),reinterpret_cast<cfloat*>(work));
			break;
		case 29 :
			expm_multiply_batch<npy_int64,npy_int16,float,float>(static_cast<const npy_int64>(n),n_vecs,reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const npy_int16*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const float*>(mu),*reinterpret_cast<const float*>(a),reinterpret_cast<float*>(F),reinterpret_cast<float*>(work));
			break;
		case 30 :
			expm_multiply_batch<npy_int64,npy_int8,double,cdouble>(static_cast<const npy_int64>(n),n_vecs,reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const npy_int8*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const cdouble*>(mu),*reinterpret_cast<const cdouble*>(a),reinterpret_cast<cdouble*>(F),reinterpret_cast<cdouble*>(work));
			break;
		case 31 :
			expm_multiply_batch<npy_int64,npy_int8,double,double>(static_cast<const npy_int64>(n),n_vecs,reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const npy_int8*>(Ax),s,m_star,*reinterpret_cast<const double*>(tol),*reinterpret_cast<const double*>(mu),*reinterpret_cast<const double*>(a),reinterpret_cast<double*>(F),reinterpret_cast<double*>(work));
			break;
		case 32 :
			expm_multiply_batch<npy_int64,npy_int8,float,cfloat>(static_cast<const npy_int64>(n),n_vecs,reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const npy_int8*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const cfloat*>(mu),*reinterpret_cast<const cfloat*>(a),reinterpret_cast<cfloat*>(F),reinterpret_cast<cfloat*>(work));
			break;
		case 33 :
			expm_multiply_batch<npy_int64,npy_int8,float,float>(static_cast<const npy_int64>(n),n_vecs,reinterpret_cast<const npy_int64*>(Ap),reinterpret_cast<const npy_int64*>(Aj),reinterpret_cast<const npy_int8*>(Ax),s,m_star,*reinterpret_cast<const float*>(tol),*reinterpret_cast<const float*>(mu),*reinterpret_cast<const float*>(a),reinterpret_cast<float*>(F),reinterpret_cast<float*>(work));
			break;
        default:
            throw std::runtime_error("internal error: invalid argument typenums");
    }    
}
#endif