#ifndef DETAIL_XIEITE_HEADER_DATA_FIND_OCCUR_IF
#	define DETAIL_XIEITE_HEADER_DATA_FIND_OCCUR_IF
#
#	include <cstddef>
#	include <functional>
#	include <ranges>
#	include "../data/iters.hpp"
#	include "../trait/is_invoc.hpp"
#	include "../trait/is_noex_invoc.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::ranges::forward_range Range, xieite::is_invoc<bool(std::ranges::range_common_reference_t<Range>)> Pred>
	[[nodiscard]] constexpr std::ranges::iterator_t<Range> find_occur_if(Range& range, std::size_t idx, Pred&& pred = {})
	noexcept(xieite::is_noex_invoc<Pred, bool(std::ranges::range_common_reference_t<Range>)> && xieite::is_noex_range<Range>) {
		for (auto iter : xieite::iters(range)) {
			if (std::invoke_r<bool>(pred, *iter) && !idx--) {
				return iter;
			}
		}
		return std::ranges::end(range);
	}
}

#endif
