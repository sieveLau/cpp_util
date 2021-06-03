file(GLOB_RECURSE src ./*.cpp)
file(GLOB_RECURSE header ./*.hpp)

add_library(util STATIC ${src} ${header})