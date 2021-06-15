cmake_minimum_required(VERSION 3.16)

if(TARGET util)
return()
endif()

project(cpputil)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB src ./*.cpp)
file(GLOB header ./*.hpp)

add_subdirectory(fileutil)


# If you are creating a shared library and your source cpp files #include the headers of another library (Say, QtNetwork for example), but your header files don't include QtNetwork headers, then QtNetwork is a PRIVATE dependency.
# If your source files and your headers include the headers of another library, then it is a PUBLIC dependency.
# If your header files but not your source files include the headers of another library, then it is an INTERFACE dependency.
# Other build properties of PUBLIC and INTERFACE dependencies are propagated to consuming libraries. http://www.cmake.org/cmake/help/v3.0/manual/cmake-buildsystem.7.html#transitive-usage-requirements
add_library(util STATIC ${src} ${header})
target_compile_definitions(util PRIVATE _LIB)
target_link_libraries(util fileutil)

add_library(util_dll SHARED ${src} ${header})
target_compile_definitions(util_dll PRIVATE UTIL_EXPORT)
target_link_libraries(util_dll fileutil_dll)
