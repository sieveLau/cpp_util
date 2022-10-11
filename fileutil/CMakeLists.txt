if(TARGET fileutil)
return()
endif()

file(GLOB src ./*.cpp)
file(GLOB header ./*.hpp)

add_library(fileutil ${src} ${header})