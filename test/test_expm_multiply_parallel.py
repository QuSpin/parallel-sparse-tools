from parallel_sparse_tools.expm_multiply_parallel_core import ExpmMultiplyParallel
from scipy.sparse import random
from scipy.sparse.linalg import expm_multiply
import numpy as np
import pytest


def test_matvec_p():
    from parallel_sparse_tools.expm_multiply_parallel_core.expm_multiply_parallel_core import (
        matvec_p,
    )

    v = np.random.rand(10)
    A = random(10, 10, density=0.1, format="csr")
    mu = 0.1
    a = 0.1

    M = a * (A.toarray() - mu * np.eye(10))

    expected_u = (M @ M @ M).dot(v)
    u = matvec_p(v, A, a, mu, 3)

    print(u)
    print(expected_u)
    assert np.allclose(expected_u, u)


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


def test_vector():
    A = random(100, 100, density=0.1, format="csr")
    v = np.random.rand(100)

    t = 0.1

    expected_u = expm_multiply(t * A, v)

    U = ExpmMultiplyParallel(A, a=t)

    np.allclose(U.dot(v), expected_u)

    t = -0.1j

    expected_u = expm_multiply(t * A, v)

    U.set_a(t)

    np.allclose(U.dot(v), expected_u)

    t = 0.1
    A = random(100, 100, density=0.1, format="csr") >= 0.5
    A = A.astype(np.int8)

    U = ExpmMultiplyParallel(A, a=t, dtype=np.float64)
    expected_u = expm_multiply(t * A, v)

    np.allclose(U.dot(v), expected_u)

    t = 0.1
    A = random(100, 100, density=0.1, format="csr") >= 0.5
    A = A.astype(np.int8)

    U = ExpmMultiplyParallel(A, a=t, dtype=np.float64)
    expected_u = expm_multiply(t * A, v)

    np.allclose(U.dot(v, tol=1e-13), expected_u)


def test_batch():
    A = random(100, 100, density=0.1, format="csr")
    v = np.random.rand(100, 4)

    t = 0.1

    expected_u = expm_multiply(t * A, v)

    U = ExpmMultiplyParallel(A, a=t)

    np.allclose(U.dot(v), expected_u)

    t = -0.1j

    expected_u = expm_multiply(t * A, v)

    U.set_a(t)

    np.allclose(U.dot(v), expected_u)

    t = 0.1
    A = random(100, 100, density=0.1, format="csr") >= 0.5
    A = A.astype(np.int8)

    U = ExpmMultiplyParallel(A, a=t, dtype=np.float64)
    expected_u = expm_multiply(t * A, v)

    np.allclose(U.dot(v), expected_u)

    t = 10.0
    A = random(100, 100, density=0.1, format="csr") >= 0.5
    A = A.astype(np.int8)

    U = ExpmMultiplyParallel(A, a=t, dtype=np.float64)
    expected_u = expm_multiply(t * A, v)

    np.allclose(U.dot(v, tol=1e-13, overwrite_v=True), expected_u)
