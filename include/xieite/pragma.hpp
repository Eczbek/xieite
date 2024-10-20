#pragma once

#include <xieite/compiler.hpp>
#include <xieite/language.hpp>

#if (XIEITE_LANGUAGE_CPP >= 2011) || (XIEITE_LANGUAGE_C >= 1999)
#	define XIEITE_PRAGMA(...) _Pragma(#__VA_ARGS__)
#elif XIEITE_COMPILER_TYPE_MSVC
#	define XIEITE_PRAGMA(...) __pragma(__VA_ARGS__)
#else
#	define XIEITE_PRAGMA(...)
#endif
