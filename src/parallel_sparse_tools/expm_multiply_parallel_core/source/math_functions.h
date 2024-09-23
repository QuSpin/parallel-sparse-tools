#ifndef __MATH_FUNCTIONS_H__
#define __MATH_FUNCTIONS_H__ 


#include <complex>
#include <cmath>
#include <algorithm>
#include <complex>
#include "complex_ops.h"

namespace math_functions
{

// abs

template <typename T>
inline T abs(const std::complex<T> &value){
	return std::hypot(value.real(),value.imag());
}

inline float abs(const float &value){
	return std::abs(value);
}

inline double abs(const double &value){
	return std::abs(value);
}

inline float abs(const cfloat &value){
	return std::hypot(value.real(),value.imag());
}

inline double abs(const cdouble &value){
	return std::hypot(value.real(),value.imag());
}

inline float compare_abs(const float R,const float B){
	return std::max(R,std::abs(B));
}

inline double compare_abs(const double R,const double B){
	return std::max(R,std::abs(B));
}

// checks of complex number 
inline float compare_abs(const float R,const cfloat &B){
	const float x = std::abs(B.real());
	const float y = std::abs(B.imag());

	if(x+y <= R){
		return R;
	}
	if(x > R || y > R){
		return std::hypot(x,y);
	}

	float RR = std::hypot(x,y);
	if(RR < R){
		return R;
	}
	else{
		return RR;
	}
}

inline double compare_abs(const double R,const cdouble &B){
	// std::hypot is expensive to calculate, check limiting cases before
	// resorting to using it by checking to see if x,y point falls inside circle 
	// of radius R that defines the current highest magnitude. 
	const double x = std::abs(B.real());
	const double y = std::abs(B.imag());
	
	if(x+y <= R){ // => (x+y)^2 = x^2+y^2+2xy <= R^2 
		return R;
	}
	if(x > R || y > R){ // => x^2+y^2 > R
		return std::hypot(x,y);
	}

	double RR = std::hypot(x,y);
	if(RR <= R){
		return R;
	}
	else{
		return RR;
	}
}

template <typename T>
inline T compare_abs(const T R,const std::complex<T> &B){
	const T x = std::abs(B.real());
	const T y = std::abs(B.imag());

	if(x+y <= R){
		return R;
	}
	if(x > R || y > R){
		return std::hypot(x,y);
	}

	T RR = std::hypot(x,y);
	if(RR < R){
		return R;
	}
	else{
		return RR;
	}
}




// exponentiation

template <typename T>
inline std::complex<T> exp(const std::complex<T> &value){
	auto res = std::exp(value);
	return std::complex<T> (res.real(),res.imag());
}


inline cdouble exp(const cdouble &value){
	std::complex<double> res = std::exp(std::complex<double>(value.real(),value.imag()));
	return cdouble(res.real(),res.imag());
}

inline cfloat exp(const cfloat &value){
	std::complex<float> res = std::exp(std::complex<float>(value.real(),value.imag()));
	return cfloat(res.real(),res.imag());
}

inline double exp(const double &value){
	return std::exp(value);
}

inline float exp(const float &value){
	return std::exp(value);
}



inline void print(const cdouble value){
	printf("(%f, %f)\n",value.real(),value.imag());
}

inline void print(const cfloat value){
	printf("(%f, %f)\n",value.real(),value.imag());
}

inline void print(const double value){
	printf("%f\n",value);
}

inline void print(const float value){
	printf("%f\n",value);
}

}

#endif