#ifndef DETAIL_XIEITE_HEADER_DATA_FIND_OCCUR
#	define DETAIL_XIEITE_HEADER_DATA_FIND_OCCUR
#
#	include <algorithm>
#	include <functional>
#	include <ranges>
#	include "../data/find_occur_if.hpp"
#	include "../trait/is_fwd_sized_range.hpp"
#	include "../trait/is_lref_invoc.hpp"
#	include "../trait/is_noex_lref_invoc.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::ranges::forward_range Range, xieite::is_fwd_sized_range Subrange, xieite::is_lref_invoc<bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Subrange>)> Pred = std::ranges::equal_to>
	[[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<Range>> find_occur(Range& range, std::ranges::range_size_t<Range> n, Subrange&& subrange, Pred&& pred = {})
	noexcept(xieite::is_noex_range<Range> && xieite::is_noex_range<Subrange> && xieite::is_noex_lref_invoc<Pred, bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Subrange>)>) {
		return xieite::find_occur_if(range, n, std::ranges::size(subrange), [&](auto&& other) { return std::ranges::equal(subrange, other, pred); });
	}

	template<std::ranges::forward_range Range, xieite::is_lref_invoc<bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)> Pred = std::equal_to<>>
	[[nodiscard]] constexpr std::ranges::iterator_t<Range> find_occur(Range& range, std::ranges::range_size_t<Range> n, std::ranges::range_common_reference_t<const Range> value, Pred&& pred = {})
	noexcept(xieite::is_noex_range<Range> && xieite::is_noex_lref_invoc<Pred, bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)>) {
		return xieite::find_occur_if(range, n, [&](auto&& other) { return std::invoke_r<bool>(pred, value, other); });
	}
}

#endif
