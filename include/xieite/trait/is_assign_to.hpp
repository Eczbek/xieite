#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_ASSIGN_TO
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_ASSIGN_TO
#
#	include <concepts>

namespace xieite {
	template<typename T, typename U>
	concept is_assign_to = std::assignable_from<U, T>;
}

#endif
