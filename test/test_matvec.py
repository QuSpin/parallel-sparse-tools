from itertools import product

import pytest
from parallel_sparse_tools.matvec import get_matvec_function, matvec
from parallel_sparse_tools.matvec._oputils import (
    _csr_dot,
    _csc_dot,
    _dia_dot,
    _other_dot,
)
from scipy.sparse import random
import numpy as np


def test_get_matvec():
    A = random(10, 10, density=0.1, format="csr")

    assert get_matvec_function(A) is _csr_dot

    A = A.tocsc()

    assert get_matvec_function(A) is _csc_dot

    A = A.todia()

    assert get_matvec_function(A) is _dia_dot

    A = A.toarray()

    assert get_matvec_function(A) is _other_dot


@pytest.mark.parametrize("N", [2, 4, 8, 16, 32, 64, 128])
def test_matvec(N):
    np.random.seed(0)

    dtypes = [np.float32, np.float64, np.complex64, np.complex128]
    for dtype_A, dtype_v in product(dtypes, dtypes):
        print(dtype_v, dtype_A)

        A = random(N, N, density=0.1, format="csr", dtype=dtype_A)
        v = np.random.rand(N).astype(dtype_v)
        V = np.random.rand(N, 4).astype(dtype_v)
        V_f = np.asfortranarray(V).astype(dtype_v)
        V_s = V[:, 1::2]

        a = np.asarray(-0.1, dtype=dtype_A)

        for vv in [v, V, V_f, V_s]:
            expected_u = a * A.dot(vv)

            out = np.zeros(vv.shape, dtype=expected_u.dtype)

            u_1 = matvec(A, vv, a=a)
            u_2 = matvec(A, vv, a=a, out=out, overwrite_out=True).copy()
            u_3 = matvec(A, vv, a=a, out=out, overwrite_out=False)

            assert np.allclose(expected_u, u_1)
            assert np.allclose(expected_u, u_2)
            assert np.allclose(2 * expected_u, u_3)
