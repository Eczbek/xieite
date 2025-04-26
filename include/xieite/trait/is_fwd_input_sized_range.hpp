#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_FWD_INPUT_SIZED_RANGE
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_FWD_INPUT_SIZED_RANGE
#
#	include <ranges>
#	include "../trait/is_fwd_input_range.hpp"
#	include "../trait/is_satisfied.hpp"

namespace xieite {
	template<typename T, auto fn = []<typename> {}>
	concept is_fwd_input_sized_range = xieite::is_fwd_input_range<T> && std::ranges::sized_range<T> && xieite::is_satisfied<fn, std::ranges::range_value_t<T>>;;
}

#endif
