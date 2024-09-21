from parallel_sparse_tools.expm_multiply_parallel_core import ExpmMultiplyParallel
from scipy.sparse import random
from scipy.sparse.linalg import expm_multiply
import numpy as np
import pytest

def almost_equal(u, v, tol=None) -> bool:
    norm = np.linalg.norm(u - v, ord=np.inf)
    
    if tol is None:
        tol = np.finfo(norm.dtype).eps * max(np.linalg.norm(u, ord=np.inf), np.linalg.norm(v, ord=np.inf), 100)

    return norm <= tol


@pytest.mark.parametrize("N", [10, 100, 1000])
def test_matvec_p(N):
    from parallel_sparse_tools.expm_multiply_parallel_core.expm_multiply_parallel_core import (
        matvec_p,
    )

    v = np.random.rand(N)
    A = random(N, N, density=0.1, format="csr")
    mu = 0.1
    a = 0.1

    M = a * (A.toarray() - mu * np.eye(N))

    expected_u = (M @ M @ M).dot(v)
    u = matvec_p(v, A, a, mu, 3)

    print(np.linalg.norm(u - expected_u))
    almost_equal(expected_u, u)


def test_errors():
    A = random(10, 10, density=0.1, format="csr")
    B = random(10, 9, density=0.1, format="csr")

    with pytest.raises(ValueError):
        ExpmMultiplyParallel(A, a=[0.1])

    with pytest.raises(ValueError):
        ExpmMultiplyParallel(B, a=0.1)

    with pytest.raises(ValueError):
        ExpmMultiplyParallel(A, a=0.1, dtype=np.int8)

    U = ExpmMultiplyParallel(A, a=0.1)

    with pytest.raises(ValueError):
        U.set_a([0.1])

    with pytest.raises(ValueError):
        U.set_a(0.1, dtype=np.int8)

    v = np.random.rand(9, 2, 2)

    with pytest.raises(ValueError):
        U.dot(v)

    v = np.random.rand(9)

    with pytest.raises(ValueError):
        U.dot(v)

    v_c = np.random.rand(10)

    U = ExpmMultiplyParallel(A, a=-0.1j)

    with pytest.raises(ValueError):
        U.dot(v_c, overwrite_v=True)

    v_c = np.random.rand(20).astype(np.complex128)[::2]

    with pytest.raises(TypeError):
        U.dot(v_c, overwrite_v=True)

    v_c = np.random.rand(10).astype(np.complex128)
    work = np.zeros(2 * v_c.size + 1, dtype=np.complex128)

    with pytest.raises(ValueError):
        U.dot(v_c, work_array=work)

    work = np.zeros(2 * v_c.size, dtype=np.float64)

    with pytest.raises(ValueError):
        U.dot(v_c, work_array=work)


def test_methods():
    a = 0.1
    A = random(10, 10, density=a, format="csr")
    U = ExpmMultiplyParallel(A, a=0.1)

    assert (U.A == A).toarray().all()
    assert U.a == a

    U.set_a(0.0)

    assert U._m_star == 0
    assert U._s == 1


def test_set_a():
    a = 0.1
    A = random(10, 10, density=a, format="csr")
    U = ExpmMultiplyParallel(A, a=0.1)

    assert U.a == a

    a = -0.1j
    U.set_a(a)

    assert U.a == a

    a = 0.1
    U.set_a(a, dtype=np.complex128)

    assert U.a == a

@pytest.mark.parametrize("N", [10, 100, 1000])
def test_vector(N):
    A = random(N, N, density=0.1, format="csr")
    v = np.random.rand(N)

    t = 0.1

    expected_u = expm_multiply(t * A, v)

    U = ExpmMultiplyParallel(A, a=t)

    almost_equal(U.dot(v), expected_u)

    t = -0.1j

    expected_u = expm_multiply(t * A, v)

    U.set_a(t)

    almost_equal(U.dot(v), expected_u)

    t = 0.1
    A = random(N, N, density=0.1, format="csr") >= 0.5
    A = A.astype(np.int8)

    U = ExpmMultiplyParallel(A, a=t, dtype=np.float64)
    expected_u = expm_multiply(t * A, v)

    almost_equal(U.dot(v), expected_u)

    t = 0.1
    A = random(N, N, density=0.1, format="csr") >= 0.5
    A = A.astype(np.int8)

    U = ExpmMultiplyParallel(A, a=t, dtype=np.float64)
    expected_u = expm_multiply(t * A, v)

    almost_equal(U.dot(v, tol=1e-13), expected_u)

@pytest.mark.parametrize("N", [10,100,1000])
def test_batch(N):
    A = random(N, N, density=np.log(N)/N) + 1j * random(N, N, density=np.log(N)/N)
    A = A.tocsr()
    v = np.random.normal(0, 1, size=(N, 10)) + 1j * np.random.normal(
        0, 1, size=(N, 10)
    )
    v /= np.linalg.norm(v)
    t = 0.00001

    expected_u = expm_multiply(t * A, v)

    U = ExpmMultiplyParallel(A, a=t)

    almost_equal(U.dot(v), expected_u)

    t = -0.00001j

    expected_u = expm_multiply(t * A, v)

    U.set_a(t)

    almost_equal(U.dot(v), expected_u)

    t = 0.000001
    A = random(N, N, density=0.1, format="csr") >= 0.5
    A = A.astype(np.int8)

    U = ExpmMultiplyParallel(A, a=t, dtype=np.float64)
    expected_u = expm_multiply(t * A, v)

    almost_equal(U.dot(v), expected_u)

    t = 0.000001
    A = random(N, N, density=0.1, format="csr") >= 0.5
    A = A.astype(np.int8)

    U = ExpmMultiplyParallel(A, a=t, dtype=np.float64)
    expected_u = expm_multiply(t * A, v)

    almost_equal(U.dot(v, tol=1e-13, overwrite_v=True), expected_u)


