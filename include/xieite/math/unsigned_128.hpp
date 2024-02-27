#ifndef XIEITE_HEADER_MATH_UNSIGNED_128
#	define XIEITE_HEADER_MATH_UNSIGNED_128

#	include "../macros/compiler.hpp"

#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG

namespace xieite::math {
	using Unsigned128 = unsigned __int128;
}

#	elif XIEITE_COMPILER_TYPE_MSVC
#		include <__msvc_int128.hpp>

namespace xieite::math {
	using Unsigned128 = std::_Unsigned128;
}

#	else
#		error "Compiler not supported"
#	endif

#endif
