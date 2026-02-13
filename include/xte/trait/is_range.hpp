#ifndef DETAIL_XTE_HEADER_TRAIT_IS_RANGE
#	define DETAIL_XTE_HEADER_TRAIT_IS_RANGE
#
#	include "../meta/req.hpp"
#	include <ranges>

namespace xte {
	template<typename T, decltype(auto)... predicates>
	concept is_range = std::ranges::range<T> && xte::req<std::ranges::range_value_t<T>, predicates...>;
}

#endif
