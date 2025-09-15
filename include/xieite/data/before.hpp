#ifndef DETAIL_XIEITE_HEADER_DATA_BEFORE
#	define DETAIL_XIEITE_HEADER_DATA_BEFORE
#
#	include <algorithm>
#	include <functional>
#	include <ranges>
#	include "../trait/is_invoc.hpp"
#	include "../trait/is_noex_invoc.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::ranges::forward_range Range, std::ranges::forward_range Subrange, xieite::is_invoc<bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Subrange>)> Pred = std::ranges::equal_to>
	[[nodiscard]] constexpr auto before(Range&& range, Subrange&& subrange, Pred&& pred = {})
	noexcept(xieite::is_noex_range<Range> && xieite::is_noex_range<Subrange> && xieite::is_noex_invoc<Pred, bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Subrange>)>) {
		return std::ranges::subrange(std::ranges::begin(range), std::ranges::search(range, subrange, pred).begin());
	}

	template<std::ranges::input_range Range>
	[[nodiscard]] constexpr auto before(Range&& range, std::ranges::range_common_reference_t<Range> x)
	noexcept(xieite::is_noex_range<Range>) {
		return std::ranges::subrange(std::ranges::begin(range), std::ranges::find(range, x));
	}
}

#endif
