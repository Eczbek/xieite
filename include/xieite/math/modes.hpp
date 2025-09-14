#ifndef DETAIL_XIEITE_HEADER_MATH_MODES
#	define DETAIL_XIEITE_HEADER_MATH_MODES
#
#	include <cstddef>
#	include <functional>
#	include <ranges>
#	include <vector>
#	include "../trait/is_arith.hpp"
#	include "../trait/is_invoc.hpp"
#	include "../trait/is_noex_invoc.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::ranges::forward_range Range, xieite::is_invoc<bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)> Pred = std::greater<>>
	requires(std::ranges::sized_range<Range> && xieite::is_arith<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr std::vector<std::ranges::iterator_t<Range>> modes(Range& range, Pred&& pred = {})
	noexcept(xieite::is_noex_invoc<Pred, bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)> && xieite::is_noex_range<Range>) {
		std::vector<std::ranges::iterator_t<Range>> its;
		const std::size_t size = std::ranges::size(range);
		if (size == 1) {
			its.push_back(std::ranges::begin(range));
		}
		if (size <= 1) {
			return its;
		}
		auto prev = std::ranges::begin(range);
		auto curr = std::ranges::next(prev);
		for (std::size_t i = 1; i < (size - 1); ++i) {
			if (std::invoke(pred, *curr, *prev)) {
				const auto next = std::ranges::next(curr);
				if (std::invoke(pred, *curr, *next)) {
					its.push_back(curr);
				} else if (i == (size - 2)) {
					its.push_back(next);
				}
			} else if (i == 1) {
				its.push_back(prev);
			}
			prev = curr++;
		}
		if (std::ranges::size(range) && !its.size()) {
			its.push_back(std::ranges::begin(range));
		}
		return its;
	}
}

#endif
