#ifndef DETAIL_XIEITE_HEADER_TRAIT_HAS_NOEX_ASSIGN
#	define DETAIL_XIEITE_HEADER_TRAIT_HAS_NOEX_ASSIGN
#
#	include <type_traits>

namespace xieite {
	template<typename T, typename U>
	concept has_noex_assign = std::is_nothrow_assignable_v<T, U>;
}

#endif
