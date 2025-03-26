#ifndef DETAIL_XIEITE_HEADER_CTNR_VIEW_BEFORE
#	define DETAIL_XIEITE_HEADER_CTNR_VIEW_BEFORE
#
#	include <algorithm>
#	include <ranges>
#	include "../trait/is_fwd_input_range.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<xieite::is_fwd_input_range R0, xieite::is_fwd_input_range R1>
	[[nodiscard]] constexpr auto view_before(R0&& range, R1&& subrange)
	noexcept(xieite::is_noex_range<R0> && xieite::is_noex_range<R1>) {
		return std::ranges::subrange(std::ranges::begin(range), std::ranges::search(range, subrange).begin());
	}

	template<std::ranges::input_range R>
	[[nodiscard]] constexpr auto view_before(R&& range, std::ranges::range_common_reference_t<R> x)
	noexcept(xieite::is_noex_range<R>) {
		return std::ranges::subrange(std::ranges::begin(range), std::ranges::find(range, x));
	}
}

#endif
