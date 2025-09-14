#ifndef DETAIL_XIEITE_HEADER_DATA_FIND_MOST_CONSEC
#	define DETAIL_XIEITE_HEADER_DATA_FIND_MOST_CONSEC
#
#	include <functional>
#	include <ranges>
#	include "../data/find_most_consec_if.hpp"
#	include "../pp/arrow.hpp"
#	include "../trait/is_fwd_sized_range.hpp"
#	include "../trait/is_invoc.hpp"
#	include "../trait/is_noex_invoc.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<xieite::is_fwd_sized_range Range, xieite::is_invoc<bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)> Pred = std::equal_to<>>
	[[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<Range>> find_most_consec(Range& range, std::ranges::range_common_reference_t<const Range> value, Pred&& pred = {})
	noexcept(xieite::is_noex_range<Range> && xieite::is_noex_invoc<Pred, bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)>) {
		return xieite::find_most_consec_if(range, [&](auto&& other) XIEITE_ARROW(std::invoke_r<bool>(pred, value, other)));
	}
}

#endif
