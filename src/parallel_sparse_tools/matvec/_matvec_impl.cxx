#include "csr.h"
#include "runtime.h"
#include <pybind11/pybind11.h>

PYBIND11_MODULE(_matvec_impl, m) {
  m.doc() = "Utilities for matrix-vector multiplication";
  define_runtime(m);
  define_csr(m);
}
