cmake_minimum_required(VERSION 3.16)

if(TARGET util)
return()
endif()

project(cpputil)
set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE src ./*.cpp)
file(GLOB_RECURSE header ./*.hpp)

add_library(util STATIC ${src} ${header})