#pragma once

#include "../pp/cplr.hpp"

#if X4CPLR_CLANG
#	ifdef __has_declspec_attribute
#		define X4HASDECLSPEC(...) __has_declspec_attribute(__VA_ARGS__)
#	else
#		define X4HASDECLSPEC(...) 0
#	endif
#elif X4CPLR_MSVC
#	define X4HASDECLSPEC(...) 1
#else
#	define X4HASDECLSPEC(...) 0
#endif
