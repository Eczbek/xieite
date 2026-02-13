#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SIZED_RANGE
#	define DETAIL_XTE_HEADER_TRAIT_IS_SIZED_RANGE
#
#	include "../meta/req.hpp"
#	include <ranges>

namespace xte {
	template<typename T, decltype(auto)... predicates>
	concept is_sized_range = std::ranges::sized_range<T> && xte::req<std::ranges::range_value_t<T>, predicates...>;
}

#endif
