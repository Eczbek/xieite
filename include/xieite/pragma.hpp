#pragma once

#include <xieite/cplr.hpp>
#include <xieite/lang.hpp>

#if XIEITE_LANG_LEAST(CPP, 2011) || XIEITE_LANG_LEAST(C, 1999)
#	define XIEITE_PRAGMA(...) _Pragma(#__VA_ARGS__)
#elif XIEITE_CPLR_TYPE_MSVC
#	define XIEITE_PRAGMA(...) __pragma(__VA_ARGS__)
#else
#	define XIEITE_PRAGMA(...)
#endif
