#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CONTIGUOUS_INPUT_RANGE
#	define DETAIL_XTE_HEADER_TRAIT_IS_CONTIGUOUS_INPUT_RANGE
#
#	include "../meta/req.hpp"
#	include <ranges>

namespace xte {
	template<typename T, decltype(auto)... predicates>
	concept is_contiguous_input_range = std::ranges::input_range<T> && std::ranges::contiguous_range<T> && xte::req<std::ranges::range_value_t<T>, predicates...>;
}

#endif
