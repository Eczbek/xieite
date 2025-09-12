#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VIEW
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VIEW
#
#	include <ranges>
#	include "../trait/is_satisfied.hpp"

namespace xieite {
	template<typename T, auto fn = []<typename> {}>
	concept is_view = std::ranges::view<T> && xieite::is_satisfied<fn, std::ranges::range_value_t<T>>;
}

#endif
