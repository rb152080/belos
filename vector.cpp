#include "datatypes.h"
#include <pybind11/pybind11.h>
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
    // std::initializer_list introduced in c++11
    Vector(std::initializer_list<f64> list_data) : vector_data(list_data) {}

    // for len()
    std::size_t size() const
    {
        return vector_data.size();
    }

    // for str()
    std::string to_string() const
    {
        std::stringstream ss;
        ss << "[";
        for (std::size_t i {}; i < vector_data.size(); ++i)
        {
            ss << vector_data[i];
            if (i != vector_data.size() - 1)
                ss << ", ";
        }
        ss << "]";
        return ss.str();
    }

    // index retrieval
    f64 get_item()
};
