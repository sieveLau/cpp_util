#pragma once
#include "fileutil/fileutil.hpp"
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

namespace sieve {
namespace util {
template <int N> auto to_hex(const unsigned char (&bytes)[N]) -> std::string {
  std::ostringstream sout;
  sout << std::hex << std::setfill('0');
  for (long long c : bytes) {
    sout << std::setw(2) << (long long)c;
  }
  return sout.str();
}
template <size_t N>
auto to_hex(std::array<unsigned char, N> bytes) -> std::string {
  std::ostringstream sout;
  sout << std::hex << std::setfill('0');
  for (long long c : bytes) {
    sout << std::setw(2) << (long long)c;
  }
  return sout.str();
}

template <typename T>
T *to_array(std::vector<T> &source, size_t *size = nullptr) {
  auto arr_size = source.size();
  T *dest = new T[arr_size];
  std::copy(source.begin(), source.end(), dest);
  if (size != nullptr)
    *size = arr_size;
  return dest;
}

} // namespace util
} // namespace sieve
