#ifndef DETAIL_XIEITE_HEADER_DATA_FIND_OCCUR_IF
#	define DETAIL_XIEITE_HEADER_DATA_FIND_OCCUR_IF
#
#	include <cstddef>
#	include <functional>
#	include <ranges>
#	include "../trait/is_lref_invoc.hpp"
#	include "../trait/is_noex_lref_invoc.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::ranges::forward_range Range, xieite::is_lref_invoc<bool(std::ranges::subrange<std::ranges::iterator_t<Range>>)> Pred>
	[[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<Range>> find_occur_if(Range& range, std::size_t n, std::ranges::range_size_t<Range> subrange_size, Pred&& pred = {})
	noexcept(xieite::is_noex_range<Range> && xieite::is_noex_lref_invoc<Pred, bool(std::ranges::subrange<std::ranges::iterator_t<Range>>)>) {
		auto begin = std::ranges::begin(range);
		auto end = begin;
		for (; subrange_size--; ++end) {
			if (end == std::ranges::end(range)) {
				return std::ranges::subrange(end, end);
			}
		}
		for (; end != std::ranges::end(range); void(++begin), ++end) {
			if (auto subrange = std::ranges::subrange(begin, end); std::invoke_r<bool>(pred, subrange) && !n--) {
				return subrange;
			}
		}
		return std::ranges::subrange(end, end);
	}

	template<std::ranges::forward_range Range, xieite::is_lref_invoc<bool(std::ranges::range_common_reference_t<Range>)> Pred>
	[[nodiscard]] constexpr std::ranges::iterator_t<Range> find_occur_if(Range& range, std::size_t n, Pred&& pred = {})
	noexcept(xieite::is_noex_range<Range> && xieite::is_noex_lref_invoc<Pred, bool(std::ranges::range_common_reference_t<Range>)>) {
		return xieite::find_occur_if(range, n, 1, [&](auto&& subrange) { return std::invoke_r<bool>(pred, subrange.front()); }).begin();
	}
}

#endif
