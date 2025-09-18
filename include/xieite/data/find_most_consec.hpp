#ifndef DETAIL_XIEITE_HEADER_DATA_FIND_MOST_CONSEC
#	define DETAIL_XIEITE_HEADER_DATA_FIND_MOST_CONSEC
#
#	include <algorithm>
#	include <functional>
#	include <ranges>
#	include "../data/find_most_consec_if.hpp"
#	include "../trait/is_fwd_sized_range.hpp"
#	include "../trait/is_lref_invoc.hpp"
#	include "../trait/is_noex_lref_invoc.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::ranges::forward_range Range, xieite::is_fwd_sized_range Subrange, xieite::is_lref_invoc<bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Subrange>)> Pred = std::ranges::equal_to>
	[[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<Range>> find_most_consec(Range& range, Subrange&& subrange, Pred&& pred = {})
	noexcept(xieite::is_noex_range<Range> && xieite::is_noex_range<Subrange> && xieite::is_noex_lref_invoc<Pred, bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Subrange>)>) {
		return xieite::find_most_consec_if(range, std::ranges::size(subrange), [&](auto&& other) { return std::ranges::equal(subrange, other, pred); });
	}

	template<std::ranges::forward_range Range, xieite::is_lref_invoc<bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)> Pred = std::equal_to<>>
	[[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<Range>> find_most_consec(Range& range, std::ranges::range_common_reference_t<Range> value, Pred&& pred = {})
	noexcept(xieite::is_noex_range<Range> && xieite::is_noex_lref_invoc<Pred, bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)>) {
		return xieite::find_most_consec_if(range, [&](auto&& other) { return std::invoke_r<bool>(pred, value, other); });
	}
}

#endif
