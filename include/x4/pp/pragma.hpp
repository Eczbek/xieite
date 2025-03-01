#pragma once

#include "../pp/cplr.hpp"
#include "../pp/lang.hpp"
#include "../pp/str.hpp"

#if X4CPLR_GCC || X4CPLR_CLANG || X4LANGLEAST(CPP, 2011) || X4LANGLEAST(C, 1999)
#	define X4PRAGMA(...) _Pragma(X4STR(__VA_ARGS__))
#elif X4CPLR_MSVC
#	define X4PRAGMA(...) __pragma(__VA_ARGS__)
#else
#	define X4PRAGMA(...)
#endif
