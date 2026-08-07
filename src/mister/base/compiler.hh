//===------------------------------------------------------------------------------------------===//
// mister/base/compiler.hh
//===------------------------------------------------------------------------------------------===//
#pragma once

#define MISTER_COMPILER_MSVC 0
#define MISTER_COMPILER_CLANG 0
#define MISTER_COMPILER_CLANG_CL 0
#define MISTER_COMPILER_APPLE_CLANG 0
#define MISTER_COMPILER_GCC 0

#if defined(_MSC_VER)
    #undef MISTER_COMPILER_MSVC
    #define MISTER_COMPILER_MSVC 1
#endif

#if defined(__clang__)
    #undef MISTER_COMPILER_CLANG
    #define MISTER_COMPILER_CLANG 1

    #if MISTER_COMPILER_MSVC
        #undef MISTER_COMPILER_CLANG_CL
        #define MISTER_COMPILER_CLANG_CL 1
    #endif

    #if defined(__apple_build_version__)
        #undef MISTER_COMPILER_APPLE_CLANG
        #define MISTER_COMPILER_APPLE_CLANG 1
    #endif
#endif

#if !MISTER_COMPILER_CLANG && (defined(__GNUC__) || defined(__GNUG__))
    #undef MISTER_COMPILER_GCC
    #define MISTER_COMPILER_GCC 1
#endif
