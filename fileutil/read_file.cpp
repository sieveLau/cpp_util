#include "fileutil.hpp"
#include <fstream>
#include <iostream>

namespace sieve {
namespace util {
std::string read_file(const std::string &file_path) noexcept
{
    std::string dest;
    try {
        std::ifstream input;
        input.open(file_path);
        if (input.is_open()) {
            std::string buffer;
            while (std::getline(input,buffer)) {
                dest+=buffer;
            }
            input.close();
        }
    }catch (std::exception& e) {
        std::cerr<<e.what()<<std::endl;
    }
    return dest;
}
}}
