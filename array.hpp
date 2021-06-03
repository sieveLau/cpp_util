#pragma once
#include <vector>

namespace sieve {
namespace util {

template<typename T>
T *to_array(std::vector<T> &source, size_t *size = nullptr)
{
    auto arr_size = source.size();
    T *dest = new T[arr_size];
    std::copy(source.begin(), source.end(), dest);
    if (size != nullptr)
        *size = arr_size;
    return dest;
}
}
}
