#ifndef DETAIL_XIEITE_HEADER_MATH_MODES
#	define DETAIL_XIEITE_HEADER_MATH_MODES
#
#	include <functional>
#	include <iterator>
#	include <ranges>
#	include <vector>
#	include "../trait/is_arith.hpp"
#	include "../trait/is_fwd_sized_range.hpp"
#	include "../trait/is_lref_invoc.hpp"
#	include "../trait/is_noex_lref_invoc.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<xieite::is_fwd_sized_range<[]<xieite::is_arith> {}> Range, xieite::is_lref_invoc<bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)> Pred = std::greater<>>
	[[nodiscard]] constexpr std::vector<std::ranges::iterator_t<Range>> modes(Range& range, Pred&& pred = {})
	noexcept(xieite::is_noex_range<Range> && xieite::is_noex_lref_invoc<Pred, bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)>) {
		std::vector<std::ranges::iterator_t<Range>> iters;
		auto prev = std::ranges::begin(range);
		auto current = prev;
		if (current != std::ranges::end(range)) {
			iters.push_back(current);
			++current;
		}
		if (current == std::ranges::end(range)) {
			return iters;
		}
		const auto size = std::ranges::size(range);
		for (std::ranges::range_size_t<Range> i = 1; i < (size - 1); ++i) {
			if (std::invoke(pred, *current, *prev)) {
				const auto next = std::ranges::next(current);
				if (std::invoke(pred, *current, *next)) {
					iters.push_back(current);
				} else if (i == (size - 2)) {
					iters.push_back(next);
				}
			} else if (i == 1) {
				iters.push_back(prev);
			}
			prev = current;
			++current;
		}
		if (std::ranges::size(range) && !iters.size()) {
			iters.push_back(std::ranges::begin(range));
		}
		return iters;
	}
}

#endif

// TODO: Do not require range to be sized
