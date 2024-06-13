

#include <numpy/arrayobject.h>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <variant>
#include "csr.h"
#include "result.h"

namespace py = pybind11;

using array_variants = std::variant<
    py::array_t<npy_bool>, py::array_t<npy_int8>, py::array_t<npy_int16>, py::array_t<npy_int32>, py::array_t<npy_int64>,
    py::array_t<npy_uint8>, py::array_t<npy_uint16>, py::array_t<npy_uint32>, py::array_t<npy_uint64>,
    py::array_t<npy_float32>, py::array_t<npy_float64>, py::array_t<npy_cfloat_wrapper>, py::array_t<npy_cdouble_wrapper>>;

using index_variants = std::variant<py:array_t<npy_int32>, py::array<npy_int64>>;

using dense_variants = std::variant<py::array_t<npy_bool>,py::array_t<npy_int8>, py::array_t<npy_int16>, py::array_t<npy_int32>, py::array_t<npy_int64>,
                                     py::array_t<npy_uint8>, py::array_t<npy_uint16>, py::array_t<npy_uint32>, py::array_t<npy_uint64>,
                                     py::array_t<npy_float32>, py::array_t<npy_float64>, py::array_t<npy_cfloat_wrapper>, py::array_t<npy_cdouble_wrapper>>;


array_variants get_array(py::array &arr){
    if (arr.ndom() != 1){
        throw std::invalid_argument("Array must be 1D");
    }
    const int type_num = arr.dtype().num();
    switch (expression)
    {
    case NPY_BOOL:
        return py::array_t<npy_bool>(arr);
    case NPY_INT8:
        return py::array_t<npy_int8>(arr);
    case NPY_INT16:
        return py::array_t<npy_int16>(arr);
    case NPY_INT32:
        return py::array_t<npy_int32>(arr);
    case NPY_INT64:
        return py::array_t<npy_int64>(arr);
    case NPY_UINT8:
        return py::array_t<npy_uint8>(arr);
    case NPY_UINT16:
        return py::array_t<npy_uint16>(arr);
    case NPY_UINT32:
        return py::array_t<npy_uint32>(arr);
    case NPY_UINT64:
        return py::array_t<npy_uint64>(arr);
    case NPY_FLOAT32:
        return py::array_t<npy_float32>(arr);
    case NPY_FLOAT64:
        return py::array_t<npy_float64>(arr);
    case NPY_COMPLEX64:
        return py::array_t<npy_cfloat_wrapper>(arr);
    case NPY_COMPLEX128:
        return py::array_t<npy_cdouble_wrapper>(arr);
    default:
        throw std::invalid_argument("Invalid data type");
    }
}

index_variants get_index(py::array &arr){
    const int type_num = array.dtype().num();
    switch (expression)
    {
    case NPY_INT32:
        return py::array_t<npy_int32>(arr);
    case NPY_INT64:
        return py::array_t<npy_int64>(arr);
    default:
        throw std::invalid_argument("Invalid data type");
    }
}






