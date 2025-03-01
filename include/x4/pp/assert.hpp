#pragma once

#include "../pp/cplr.hpp"
#include "../pp/lang.hpp"

#if X4LANGLEAST(CPP, 2011) || X4LANGLEAST(C, 2023)
#	define X4ASSERT(...) static_assert(__VA_ARGS__)
#elif X4LANGLEAST(C, 2011)
#	define X4ASSERT(...) _Static_assert(__VA_ARGS__)
#elif X4CPLR_MSVC
#	include <crtdbg.h>

#	define X4ASSERT(...) _STATIC_ASSERT(__VA_ARGS__)
#else
#	define X4ASSERT(...)
#endif
