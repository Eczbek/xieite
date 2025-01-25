#pragma once

#include "../pp/cplr.hpp"
#include "../pp/lang.hpp"
#include "../pp/str.hpp"

#if XIEITE_LANG_LEAST(CPP, 2011) || XIEITE_LANG_LEAST(C, 1999)
#	define XIEITE_PRAGMA(...) _Pragma(XIEITE_STR(__VA_ARGS__))
#elif XIEITE_CPLR_TYPE_MSVC
#	define XIEITE_PRAGMA(...) __pragma(__VA_ARGS__)
#else
#	define XIEITE_PRAGMA(...)
#endif
