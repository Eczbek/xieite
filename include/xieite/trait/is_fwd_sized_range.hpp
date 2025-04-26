#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_FWD_SIZED_RANGE
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_FWD_SIZED_RANGE
#
#	include <ranges>
#	include "../trait/is_satisfied.hpp"

namespace xieite {
	template<typename T, auto fn = []<typename> {}>
	concept is_fwd_sized_range = std::ranges::forward_range<T> && std::ranges::sized_range<T> && xieite::is_satisfied<fn, std::ranges::range_value_t<T>>;;
}

#endif
