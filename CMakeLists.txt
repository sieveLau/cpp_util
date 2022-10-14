cmake_minimum_required(VERSION 3.16)


include_guard()

include(FetchContent)
project(cpputil)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${googletest_SOURCE_DIR}/googletest/include)
include_directories(include)

add_library(path_helper src/path_helper.cpp include/path_helper.h)

add_subdirectory(test)

add_subdirectory(fileutil)


# If you are creating a shared library and your source cpp files #include the headers of another library (Say, QtNetwork for example), but your header files don't include QtNetwork headers, then QtNetwork is a PRIVATE dependency.
# If your source files and your headers include the headers of another library, then it is a PUBLIC dependency.
# If your header files but not your source files include the headers of another library, then it is an INTERFACE dependency.
# Other build properties of PUBLIC and INTERFACE dependencies are propagated to consuming libraries. http://www.cmake.org/cmake/help/v3.0/manual/cmake-buildsystem.7.html#transitive-usage-requirements
add_library(util util.h util.cpp)
target_link_libraries(util fileutil)
