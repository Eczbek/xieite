#pragma once

#include <xieite/macros/COMPILER_TYPE.hpp>

#if defined(XIETIE_COMPILER_TYPE_GCC)
#	define XIEITE_VANISH \
		sizeof(decltype(std))
#else
#	error "Compiler not supported"
#endif
