import numpy as np
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

np.random.seed(0)

FORMATS = ["csr", "csc", "dia"]
SIZES = [1, 10, 100, 200]
F_TYPES = [np.float32, np.float64, np.complex64, np.complex128]
T_TYPES = [np.int8, np.int16, np.int32, np.int64, np.float32, np.float64, np.complex64, np.complex128]

PARAMETERS = list(product(SIZES, T_TYPES, F_TYPES, F_TYPES, FORMATS))

def test_get_matvec():
    A = random(10, 10, density=0.1, format="csr")

    assert get_matvec_function(A) is _csr_dot

    A = A.tocsc()

    assert get_matvec_function(A) is _csc_dot

    A = A.todia()

    assert get_matvec_function(A) is _dia_dot

    A = A.toarray()

    assert get_matvec_function(A) is _other_dot


def almost_equal(u, v, tol) -> bool:
    norm = np.linalg.norm(u - v, ord=np.inf)
    return  norm <= tol


def get_tolerance(A, a, v):
    if isinstance(A, np.floating):
        tol = (np.finfo(A.dtype).eps * np.finfo(a.dtype).eps * np.finfo(v.type).eps)**(1.0/(2.0*3))
    else:
        tol = (np.finfo(a.dtype).eps * np.finfo(v.dtype).eps)**(1.0/(2.0*2))

    A_norm = np.linalg.norm(A.toarray(), ord=np.inf)
    vv_norm = np.linalg.norm(v, ord=np.inf)

    tol = tol * A_norm * vv_norm
    return tol


def get_A(N, dtype, format):
    return random(N, N, density=min(0.1, np.log(N)/N), format=format, dtype=dtype)


@pytest.mark.parametrize(("N", "dtype_A", "dtype_a", "dtype_v", "format"), PARAMETERS)
def test_matvec(N, dtype_A, dtype_a, dtype_v, format):

    A = get_A(N, dtype_A, format)
    dtype_a = np.result_type(dtype_A, dtype_a)
    a = np.asarray(-0.1, dtype=dtype_a)
    vv = np.random.rand(N).astype(dtype_v)

    tol = get_tolerance(A, a, vv)

    expected_u = a * A.dot(vv)
    

    out = np.random.normal(size=vv.shape).astype(expected_u.dtype)

    u_1 = matvec(A, vv, a=a)
    u_2 = matvec(A, vv, a=a, out=out, overwrite_out=True).copy()
    u_3 = matvec(A, vv, a=a, out=out, overwrite_out=False)
    assert almost_equal(expected_u, u_1, tol)
    assert almost_equal(expected_u, u_2, tol)
    expected_u += a * A.dot(vv)        
    assert almost_equal(expected_u, u_3, tol)


@pytest.mark.parametrize(("N", "dtype_A", "dtype_a", "dtype_v", "format"), PARAMETERS)
def test_matvecs_C(N, dtype_A, dtype_a, dtype_v, format):

    A = get_A(N, dtype_A, format)
    dtype_a = np.result_type(dtype_A, dtype_a)
    a = np.asarray(-0.1, dtype=dtype_a)
    V = np.random.rand(2*N, 10).astype(dtype_v)
    V = np.asfortranarray(V)
    vv = V[::2, 1::2]

    tol = get_tolerance(A, a, vv)

    expected_u = a * A.dot(vv)
    

    out = np.random.normal(size=vv.shape).astype(expected_u.dtype)

    u_1 = matvec(A, vv, a=a)
    u_2 = matvec(A, vv, a=a, out=out, overwrite_out=True).copy()
    u_3 = matvec(A, vv, a=a, out=out, overwrite_out=False)
    assert almost_equal(expected_u, u_1, tol)
    assert almost_equal(expected_u, u_2, tol)
    expected_u += a * A.dot(vv)        
    assert almost_equal(expected_u, u_3, tol)


def test_dense():

	M = np.arange(16).reshape(4,4).astype(np.float64) 
	M = (M.T.conj() + M)/2.0
	M = np.asarray(M).astype(np.complex128)

	psi0 = np.ones((4,),dtype=np.complex128)
	psi0 /= np.linalg.norm(psi0)

	time=np.pi/np.sqrt(0.5)

	matvec = get_matvec_function(M)
	V_out = np.zeros_like(psi0)
	matvec(M,psi0,a=np.cos(time),out=V_out,overwrite_out=False)
	#
	V_out2=np.cos(time)*M@psi0

	np.testing.assert_allclose(V_out-V_out2,0,atol=1e-10)
