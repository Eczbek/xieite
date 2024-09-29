#pragma once

#include <xieite/compiler.hpp>
#include <xieite/language_standard.hpp>

#if XIEITE_LANGUAGE_STANDARD_CPP_2011 || XIEITE_LANGUAGE_STANDARD_C_2023
#	define XIEITE_STATIC_ASSERT(...) static_assert(__VA_ARGS__)
#elif XIEITE_LANGUAGE_STANDARD_C_2011
#	define XIEITE_STATIC_ASSERT(...) _Static_assert(__VA_ARGS__)
#elif XIEITE_COMPILER_TYPE_MSVC
#	include <crtdbg.h>

#	define XIEITE_STATIC_ASSERT(...) _STATIC_ASSERT(__VA_ARGS__)
#else
#	define XIEITE_STATIC_ASSERT(...)
#endif

// https://github.com/isar/libmdbx/blob/master/src/preface.h
