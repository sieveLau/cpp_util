#include "../include/path_helper.h"
#include <filesystem>
//
// Created by Sieve Lau on 2022/10/10.
//
std::string exec_dir(const char* argv_zero) {
    auto dir = std::filesystem::weakly_canonical(std::filesystem::path(argv_zero)).parent_path();
//    printf("%s",dir.c_str());
    return dir;
}
