#ifndef DETAIL_XIEITE_HEADER_DATA_AFTER
#	define DETAIL_XIEITE_HEADER_DATA_AFTER
#
#	include <algorithm>
#	include <iterator>
#	include <ranges>
#	include "../trait/is_fwd_range.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<xieite::is_fwd_range Range0, xieite::is_fwd_range Range1>
	[[nodiscard]] constexpr auto after(Range0&& range, Range1&& subrange)
	noexcept(xieite::is_noex_range<Range0> && xieite::is_noex_range<Range1>) {
		return std::ranges::subrange(std::ranges::search(range, subrange).end(), std::ranges::end(range));
	}

	template<std::ranges::input_range Range>
	[[nodiscard]] constexpr auto after(Range&& range, std::ranges::range_common_reference_t<Range> x)
	noexcept(xieite::is_noex_range<Range>) {
		return std::ranges::subrange(std::ranges::next(std::ranges::find(range, x), 1, std::ranges::end(range)), std::ranges::end(range));
	}
}

#endif
