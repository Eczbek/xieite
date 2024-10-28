module;

#include <xieite/cplr.hpp>

#if XIEITE_CPLR_TYPE_MSVC
#	include <__msvc_int128.hpp>
#elif !XIEITE_CPLR_TYPE_GCC && !XIEITE_CPLR_TYPE_CLANG
#	warning "unsupported compiler"
#endif

export module xieite:int128;

export namespace xieite {
#if XIEITE_CPLR_TYPE_MSVC
	using int128 = std::_Signed128;
	using uint128 = std::_Unsigned128;
#else
	__extension__ using int128 = __int128;
	__extension__ using uint128 = unsigned __int128;
#endif
}
