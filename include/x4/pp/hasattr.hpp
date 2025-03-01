#pragma once

#include "../pp/cplr.hpp"
#include "../pp/lang.hpp"

#if X4LANGLEAST(CPP, 2020)
#	define X4HASATTR(...) __has_cpp_attribute(__VA_ARGS__)
#elif X4LANGLEAST(C, 2023)
#	define X4HASATTR(...) __has_c_attribute(__VA_ARGS__)
#elif X4CPLR_GCC || X4CPLR_CLANG
#	define X4HASATTR(...) __has_attribute(__VA_ARGS__)
#else
#	define X4HASATTR(...) 0
#endif
