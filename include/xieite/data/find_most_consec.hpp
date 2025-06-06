#ifndef DETAIL_XIEITE_HEADER_DATA_FIND_MOST_CONSEC
#	define DETAIL_XIEITE_HEADER_DATA_FIND_MOST_CONSEC
#
#	include <functional>
#	include <ranges>
#	include "../data/find_most_consec_if.hpp"
#	include "../pp/arrow.hpp"
#	include "../trait/is_invoc.hpp"
#	include "../trait/is_noex_invoc.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::ranges::forward_range Range, xieite::is_invoc<bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)> Fn = std::ranges::equal_to>
	requires(std::ranges::sized_range<Range>)
	[[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<Range>> find_most_consec(Range& range, std::ranges::range_common_reference_t<Range> value, Fn&& cmp = {})
	noexcept(xieite::is_noex_invoc<Fn, bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)> && xieite::is_noex_range<Range>) {
		return xieite::find_most_consec_if(range, [&](auto& other) XIEITE_ARROW(std::invoke_r<bool>(cmp, value, other)));
	}
}

#endif
