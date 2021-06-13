#ifndef B6160D72_D8D1_41EC_9DE8_80F77B822B3D
#define B6160D72_D8D1_41EC_9DE8_80F77B822B3D

#include <string>
#include <fstream>
#include <iostream>

#ifdef WIN32
    #ifdef FILEUTIL_EXPORT
        #define FILEUTIL_DLL __declspec(dllexport)
    #else
        #ifdef _LIB
            #define FILEUTIL_DLL
        #else
            #define FILEUTIL_DLL __declspec(dllimport)
        #endif
    #endif
#else
    #define FILEUTIL_DLL
#endif

namespace sieve {
namespace util {
std::string FILEUTIL_DLL read_file(const std::string &file_path) noexcept;
}
}

#endif /* B6160D72_D8D1_41EC_9DE8_80F77B822B3D */
