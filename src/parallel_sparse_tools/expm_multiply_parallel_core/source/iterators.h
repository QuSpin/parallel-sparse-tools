#ifndef __ITERATORS_H__
#define __ITERATORS_H__ 

#include <cmath>
#include <algorithm>
#include <complex>
#include "complex_ops.h"
#include "math_functions.h"


namespace functors
{


template<class T>
struct Abs
{
	inline T operator()(const T &val){
		return math_functions::abs(val);
	}
};


template<>
struct Abs<cfloat>
{
	inline float operator()(const cfloat &val){
		return math_functions::abs(val);
	}
};


template<>
struct Abs<cdouble>
{
	inline double operator()(const cdouble &val){
		return math_functions::abs(val);
	}
};

template<class T>
struct Add
{
	inline T operator()(const T& a, const T& b) const
	{
		return a + b;
	}
};


template<class T>
struct Max
: std::binary_function<T, T, T>
{
    inline T operator()(const T& a, const T& b) const
    {
        return std::max(a, b);
    }
};




#endif