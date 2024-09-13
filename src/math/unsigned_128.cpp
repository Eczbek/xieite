module;

#include <xieite/compiler.hpp>

#if XIEITE_COMPILER_TYPE_MSVC
#	include <__msvc_int128.hpp>
#elif !XIEITE_COMPILER_TYPE_GCC && !XIEITE_COMPILER_TYPE_CLANG
#	warning "Compiler not supported"
#endif

export module xieite:math.Unsigned128;

export namespace xieite::math {
#if XIEITE_COMPILER_TYPE_MSVC
	using Unsigned128 = std::_Unsigned128;
#else
	__extension__ using Unsigned128 = unsigned __int128;
#endif
}
