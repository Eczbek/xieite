#pragma once

#include <xieite/language.hpp>

#if defined(__has_include) || (XIEITE_LANGUAGE_CPP >= XIEITE_LANGUAGE_CPP_2017) || (XIEITE_LANGUAGE_C >= XIEITE_LANGUAGE_C_2023)
#	define XIEITE_HAS_INCLUDE(...) __has_include(__VA_ARGS__)
#else
#	define XEIITE_HAS_INCLUDE(...) 0
#endif
