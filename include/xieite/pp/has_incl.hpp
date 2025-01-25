#pragma once

#include "../pp/lang.hpp"

#if defined(__has_include) || XIEITE_LANG_LEAST(CPP, 2017) || XIEITE_LANG_LEAST(C, 2023)
#	define XIEITE_HAS_INCL(...) __has_include(__VA_ARGS__)
#else
#	define XEIITE_HAS_INCL(...) 0
#endif
