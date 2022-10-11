//
// Created by Sieve Lau on 2022/10/10.
//
#include <filesystem>
#include <gtest/gtest.h>
#include "path_helper.h"
TEST(PathHelper, CorrectOutput) {
    auto current_path = std::filesystem::current_path();
    const char* test_path = current_path.c_str();
    const char* expected_path = current_path.parent_path().c_str();
    EXPECT_STREQ(expected_path, exec_dir(test_path).c_str());
}