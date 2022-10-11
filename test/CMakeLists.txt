enable_testing()

add_executable(
        test_path_helper
        test_path_helper.cpp
)
target_link_libraries(
        test_path_helper
        path_helper
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_path_helper)