#ifndef XIEITE_HEADER_MATH_SIGNED_128
#	define XIEITE_HEADER_MATH_SIGNED_128

#	include "../macros/compiler.hpp"

#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG

namespace xieite::math {
	using Signed128 = __int128_t;
}

#	elif XIEITE_COMPILER_TYPE_MSVC
#		include <__msvc_int128.hpp>

namespace xieite::math {
	using Signed128 = std::_Signed128;
}

#	else
#		error "Compiler not supported"
#	endif

#endif
