#pragma once

#include "../pp/lang.hpp"

#if defined(__has_include) || X4LANGLEAST(CPP, 2017) || X4LANGLEAST(C, 2023)
#	define X4HASINCL(...) __has_include(__VA_ARGS__)
#else
#	define X4HASINCL(...) 0
#endif
