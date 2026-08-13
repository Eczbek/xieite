#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CONTIGUOUS_RANGE
#	define DETAIL_XTE_HEADER_TRAIT_IS_CONTIGUOUS_RANGE
#
#	include "../meta/req.hpp"
#	include <ranges>

namespace xte {
	template<typename T, decltype(auto)... predicates>
	concept is_contiguous_range = std::ranges::contiguous_range<T> && xte::req<std::ranges::range_value_t<T>, predicates...>;
}

#endif
