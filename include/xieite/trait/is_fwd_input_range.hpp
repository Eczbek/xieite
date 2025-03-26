#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_FWD_INPUT_RANGE
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_FWD_INPUT_RANGE
#
#	include <ranges>
#	include "../trait/is_satisfd.hpp"

namespace xieite {
	template<typename T, auto fn = []<typename> {}>
	concept is_fwd_input_range = std::ranges::forward_range<T> && std::ranges::input_range<T> && xieite::is_satisfd<fn, std::ranges::range_value_t<T>>;
}

#endif
