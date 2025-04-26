#ifndef DETAIL_XIEITE_HEADER_DATA_VIEW_BEFORE
#	define DETAIL_XIEITE_HEADER_DATA_VIEW_BEFORE
#
#	include <algorithm>
#	include <ranges>
#	include "../trait/is_fwd_input_range.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<xieite::is_fwd_input_range Range0, xieite::is_fwd_input_range Range1>
	[[nodiscard]] constexpr auto view_before(Range0&& range, Range1&& subrange)
	noexcept(xieite::is_noex_range<Range0> && xieite::is_noex_range<Range1>) {
		return std::ranges::subrange(std::ranges::begin(range), std::ranges::search(range, subrange).begin());
	}

	template<std::ranges::input_range Range>
	[[nodiscard]] constexpr auto view_before(Range&& range, std::ranges::range_common_reference_t<Range> x)
	noexcept(xieite::is_noex_range<Range>) {
		return std::ranges::subrange(std::ranges::begin(range), std::ranges::find(range, x));
	}
}

#endif
