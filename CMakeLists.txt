cmake_minimum_required(VERSION 3.16)

if(TARGET util)
return()
endif()

project(cpputil)
set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

file(GLOB src ./*.cpp)
file(GLOB header ./*.hpp)

add_subdirectory(fileutil)

add_library(util STATIC ${src} ${header})
target_compile_definitions(util PRIVATE _LIB)
target_link_libraries(util fileutil)

add_library(util_dll SHARED ${src} ${header})
target_compile_definitions(util_dll PRIVATE UTIL_EXPORT)
target_link_libraries(util_dll fileutil_dll)
