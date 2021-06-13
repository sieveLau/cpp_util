if(TARGET fileutil)
return()
endif()

file(GLOB src ./*.cpp)
file(GLOB header ./*.hpp)

add_library(fileutil STATIC ${src} ${header})
add_library(fileutil_dll SHARED ${src} ${header})
target_compile_definitions(fileutil PRIVATE _LIB)
target_compile_definitions(fileutil_dll PRIVATE FILEUTIL_EXPORT)