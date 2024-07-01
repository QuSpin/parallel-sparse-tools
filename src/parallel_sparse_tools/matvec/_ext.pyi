import enum
from numpy import ndarray

class ReturnState(enum.Enum):
    SUCCESS = 0
    INVALID_DENSE_TYPE = enum.auto()
    INVALID_INDEX_TYPE = enum.auto()
    INVALID_N_ROW = enum.auto()
    INVALID_N_COL = enum.auto()
    MISMATCH_IN_OUT_TYPES = enum.auto()
    MISMATCH_INDEX_TYPES = enum.auto()
    INVALID_OUT_TYPE = enum.auto()
    INVALID_OUT_NDIM = enum.auto()
    MISMATCH_IN_DIM = enum.auto()
    INVALID_IN_NDIM = enum.auto()
    INVALID_IN_TYPE = enum.auto()
    MISMATCH_OUT_DIM = enum.auto()
    DIM_MISMATCH_IN_OUT = enum.auto()
    INDPTR_NOT_C_CONTIGUOUS = enum.auto()
    INVALID_INDPTR_TYPE = enum.auto()
    INDICES_NOT_C_CONTIGUOUS = enum.auto()
    INVALID_INDICES_TYPE = enum.auto()
    DATA_NOT_C_CONTIGUOUS = enum.auto()
    INVALID_DATA_TYPE = enum.auto()
    INVALID_INDPTR_NDIM = enum.auto()
    INVALID_INDPTR_SIZE = enum.auto()
    INVALID_INDICES_NDIM = enum.auto()
    INVALID_DATA_NDIM = enum.auto()
    INVALID_ALPHA_TYPE = enum.auto()
    INVALID_ALPHA_NDIM = enum.auto()
    INVALID_DIAGS_TYPE = enum.auto()
    INVALID_DIAGS_NDIM = enum.auto()
    INVALID_OFFSETS_TYPE = enum.auto()
    MISMATCH_DIAGS_OFFSETS = enum.auto()

def csr_matvec(
    overwrite_out: bool,
    n_row: int,
    n_col: int,
    alpha: ndarray,
    indptr: ndarray,
    indices: ndarray,
    data: ndarray,
    input: ndarray,
    output: ndarray,
) -> ReturnState: ...
def csc_matvec(
    overwrite_out: bool,
    n_row: int,
    n_col: int,
    alpha: ndarray,
    indptr: ndarray,
    indices: ndarray,
    data: ndarray,
    input: ndarray,
    output: ndarray,
) -> ReturnState: ...
def dia_matvec(
    overwrite_out: bool,
    n_row: int,
    n_col: int,
    alpha: ndarray,
    diags: ndarray,
    offsets: ndarray,
    input: ndarray,
    output: ndarray,
) -> ReturnState: ...
