#pragma once
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include "fileutil/fileutil.hpp"

#ifdef WIN32
    #ifdef UTIL_EXPORT
        #define UTIL_DLL __declspec(dllexport)
    #else
        #ifdef _LIB
            #define UTIL_DLL
        #else
            #define UTIL_DLL __declspec(dllimport)
        #endif
    #endif
#else
    #define UTIL_DLL
#endif

namespace sieve {
namespace util {
template<int N>
auto UTIL_DLL to_hex(const unsigned char (&bytes)[N]) -> std::string
{
    std::ostringstream sout;
    sout << std::hex << std::setfill('0');
    for (long long c : bytes) {
        sout << std::setw(2) << (long long) c;
    }
    return sout.str();
}
template<size_t N>
auto UTIL_DLL to_hex(std::array<unsigned char,N> bytes) -> std::string
{
    std::ostringstream sout;
    sout << std::hex << std::setfill('0');
    for (long long c : bytes) {
        sout << std::setw(2) << (long long) c;
    }
    return sout.str();
}

template<typename T>
T UTIL_DLL * to_array(std::vector<T> &source, size_t *size = nullptr)
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
