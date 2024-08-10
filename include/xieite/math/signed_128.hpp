#ifndef XIEITE_HEADER_MATH_SIGNED_128
#	define XIEITE_HEADER_MATH_SIGNED_128

#	include "../macros/compiler.hpp"

#	if XIEITE_COMPILER_TYPE_MSVC
#		include <__msvc_int128.hpp> // Internal header
#	elif !XIEITE_COMPILER_TYPE_GCC && !XIEITE_COMPILER_TYPE_CLANG
#		warning "Compiler not supported"
#	endif

namespace xieite::math {
#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
	using Signed128 = __int128;
#	elif XIEITE_COMPILER_TYPE_MSVC
	using Signed128 = std::_Signed128;
#	endif
}

#endif
