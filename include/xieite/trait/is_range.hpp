#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_RANGE
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_RANGE
#
#	include <ranges>
#	include "../trait/is_satisfd.hpp"

namespace xieite {
	template<typename T, auto fn = []<typename> {}>
	concept is_range = std::ranges::range<T> && xieite::is_satisfd<fn, std::ranges::range_value_t<T>>;
}

#endif
