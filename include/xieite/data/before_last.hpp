#ifndef DETAIL_XIEITE_HEADER_DATA_BEFORE_LAST
#	define DETAIL_XIEITE_HEADER_DATA_BEFORE_LAST
#
#	include <algorithm>
#	include <ranges>
#	include "../trait/is_fwd_input_range.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<xieite::is_fwd_input_range Range0, xieite::is_fwd_input_range Range1>
	[[nodiscard]] constexpr auto before_last(Range0&& range, Range1&& subrange)
	noexcept(xieite::is_noex_range<Range0> && xieite::is_noex_range<Range1>) {
		return std::ranges::subrange(std::ranges::begin(range), std::ranges::find_end(range, subrange).begin());
	}

	template<std::ranges::input_range Range>
	[[nodiscard]] constexpr auto before_last(Range&& range, std::ranges::range_common_reference_t<Range> x)
	noexcept(xieite::is_noex_range<Range>) {
		return std::ranges::subrange(std::ranges::begin(range), std::ranges::find_last(range, x));
	}
}

#endif
