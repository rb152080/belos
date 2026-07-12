#include "datatypes.h"
#include <pybind11/chrono.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>
#include <vector>

namespace py = pybind11;

class Vector
{
  private:
    std::vector<f64> vector_data;

  public:
    // constructors
    Vector() = default; // > Vector() {} because it is faster, more optimized
    Vector(u64 size, f64 initial_value = 0.0) : vector_data(size, initial_value)
    {}
    // std::initializer_list introduced in c++11; can't use it here because it
    // is compile time; python needs it at run time
    Vector(const std::vector<f64>& list_data) : vector_data(list_data) {}

    // for len()
    u64 size() const
    {
        return static_cast<u64>(vector_data.size());
    }

    // for str()
    std::string to_string() const
    {
        std::stringstream ss;
        ss << "[";
        for (auto i { 0uz }; i < vector_data.size(); ++i)
        {
            ss << vector_data[i];
            if (i != vector_data.size() - 1)
                ss << ", ";
        }
        ss << "]";
        return ss.str();
    }

    // index retrieval
    f64 get_item(i64 index) const
    {
        if (index < 0)
        {
            index += static_cast<i64>(size());
        }
        if (index < 0 || static_cast<u64>(index) >= size())
        {
            throw py::index_error("Vector index out of range");
        }
        return vector_data[static_cast<u64>(index)];
    }

    // for slicing
};

PYBIND11_MODULE(belos, m)
{
    m.doc() = "belos";
    py::class_<Vector>(m, "Vector")
        .def(py::init<>())
        .def(py::init<u64, f64>(), py::arg("size"),
             py::arg("initial_value") = 0.0)
        .def(py::init<const std::vector<f64>&>())
        .def("__len__", &Vector::size)
        .def("__str__", &Vector::to_string)
        .def("__repr__", &Vector::to_string)
        .def("__getitem__", &Vector::get_item);
}
