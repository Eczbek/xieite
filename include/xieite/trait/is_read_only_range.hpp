#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_READ_ONLY_RANGE
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_READ_ONLY_RANGE
#
#	include <ranges>
#	include "../trait/is_satisfied.hpp"

namespace xieite {
	template<typename T, auto fn = []<typename> {}>
	concept is_read_only_range = std::ranges::constant_range<T> && xieite::is_satisfied<fn, std::ranges::range_value_t<T>>;
}

#endif
