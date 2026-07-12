import belos
import pytest

def test_vector_init():
    v = belos.Vector([1, 2, 3])
    assert len(v) == 3
    assert str(v) == "[1, 2, 3]"

def test_vector_valid_index():
    v = belos.Vector([1, 2, 3])
    assert v[0] == 1.0
    assert v[-2] == 2.0
    assert v[1] == 2

def test_vector_invalid_index():
    v = belos.Vector([1, 2, 3])
    with pytest.raises(IndexError):
        _ = v[4]
        _ = v[-4]
