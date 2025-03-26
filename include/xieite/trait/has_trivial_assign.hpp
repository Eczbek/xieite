#ifndef DETAIL_XIEITE_HEADER_TRAIT_HAS_TRIVIAL_ASSIGN
#	define DETAIL_XIEITE_HEADER_TRAIT_HAS_TRIVIAL_ASSIGN
#
#	include <type_traits>

namespace xieite {
	template<typename T, typename U>
	concept has_trivial_assign = std::is_trivially_assignable_v<T, U>;
}

#endif
