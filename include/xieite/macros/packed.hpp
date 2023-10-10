#pragma once

#include "../macros/compiler.hpp"

#if XIEITE_COMPILER_GCC
#	define XIEITE_PACKED [[gnu::packed]]
#else
#	define XIEITE_PACKED
#endif
