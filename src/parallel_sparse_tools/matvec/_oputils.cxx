

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

array_variants get_array(py::array &arr, const int ndim = -1, const std::string &name){
    if (ndim >= 0 && arr.ndim() != ndim){
        throw std::invalid_argument("Array "+name+" must be "+std::to_string(ndim)+"-dimensional");
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

index_variants get_index(py::array &arr, const std::string &name){
    if (arr.ndim() != 1){
        throw std::invalid_argument(name+" array must be 1-dimensional");
    }
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



int csr_matvec_runtime(
    const bool overwrite,
    const 
    const npy_intp n_row,
    py::array py_indptr,
    py::array py_indices,
    py::array py_data,
    py::array py_x,
    py::array py_y
) {
    if (n_row < 0) {
        throw std::invalid_argument("n_row must be non-negative");
    }
    if (n_row == 0) {
        return;
    }

    index_variants indptr = get_index(py_indptr, 1, "indptr");
    index_variants indices = get_index(py_indices, 1, "indices");
    array_variants data = get_array(py_data, 1, "data");
    array_variants x = get_array(py_x, -1);
    array_variants y = get_array(py_y);

    std::visit(
        [&n_row](const auto& indptr, const auto& indices, const auto& data, const auto &y, auto &x){
            using indptr_t = typename decltype(indptr)::value_type;
            using indices_t = typename decltype(indices)::value_type;
            using data_t = typename decltype(data)::value_type;
            using y_t = typename decltype(y)::value_type;
            using x_t = typename decltype(x)::value_type;
            using result_t = result_type_t<data_t, 

        }
    )

}





