#pragma once

#include "array.hpp"
#include <iomanip>
#include <string>
#include <sstream>

namespace sieve {
namespace util {
template<int N>
auto to_hex(const unsigned char (&bytes)[N]) -> std::string
{
    std::ostringstream sout;
    sout << std::hex << std::setfill('0');
    for (long long c : bytes) {
        sout << std::setw(2) << (long long) c;
    }
    return sout.str();
}
template<int N>
auto to_hex(std::array<unsigned char,N> bytes) -> std::string
{
    std::ostringstream sout;
    sout << std::hex << std::setfill('0');
    for (long long c : bytes) {
        sout << std::setw(2) << (long long) c;
    }
    return sout.str();
}
}
}
