#ifndef DETAIL_XIEITE_HEADER_DATA_PARTIAL_REVERSE
#	define DETAIL_XIEITE_HEADER_DATA_PARTIAL_REVERSE
#
#	include <algorithm>
#	include <iterator>
#	include <ranges>
#	include "../trait/is_invoc.hpp"
#	include "../trait/is_noex_invoc.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::ranges::bidirectional_range Range, xieite::is_invoc<bool(std::ranges::range_common_reference_t<Range>)> Fn>
	requires(std::indirectly_swappable<std::ranges::iterator_t<Range>>)
	constexpr void partial_reverse(Range& range, Fn&& cond)
	noexcept(xieite::is_noex_invoc<Fn, bool(std::ranges::range_common_reference_t<Range>)> && xieite::is_noex_range<Range>) {
		auto first = std::ranges::begin(range);
		auto last = std::ranges::end(range);
		while (true) {
			first = std::ranges::find_if(first, last, cond);
			last = std::ranges::find_last_if(first, last, cond);
			if (first == last) {
				break;
			}
			std::ranges::iter_swap(first, last);
			++first;
			--last;
		}
	}
}

#endif
