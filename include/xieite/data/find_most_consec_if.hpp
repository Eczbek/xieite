#ifndef DETAIL_XIEITE_HEADER_DATA_FIND_MOST_CONSEC_IF
#	define DETAIL_XIEITE_HEADER_DATA_FIND_MOST_CONSEC_IF
#
#	include <functional>
#	include <iterator>
#	include <ranges>
#	include "../data/iters.hpp"
#	include "../trait/is_invoc.hpp"
#	include "../trait/is_noex_invoc.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::ranges::forward_range Range, xieite::is_invoc<bool(std::ranges::range_common_reference_t<Range>)> Fn>
	requires(std::ranges::sized_range<Range>)
	[[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<Range>> find_most_consec_if(Range& range, Fn&& cond = {})
	noexcept(xieite::is_noex_invoc<Fn, bool(std::ranges::range_common_reference_t<Range>)> && xieite::is_noex_range<Range>) {
		auto curr_begin = std::ranges::begin(range);
		auto curr_end = curr_begin;
		auto result_begin = curr_begin;
		auto result_end = curr_end;
		bool prev = false;
		for (auto iter : xieite::iters(range)) {
			const bool curr = std::invoke_r<bool>(cond, *iter);
			if (curr) {
				if (!prev) {
					curr_begin = iter;
					curr_end = iter;
				}
				++curr_end;
			} else if (prev && (std::ranges::distance(curr_begin, curr_end) > std::ranges::distance(result_begin, result_end))) {
				result_begin = curr_begin;
				result_end = curr_end;
			}
			prev = curr;
		}
		if (prev && (std::ranges::distance(curr_begin, curr_end) > std::ranges::distance(result_begin, result_end))) {
			return std::ranges::subrange<std::ranges::iterator_t<Range>>(curr_begin, curr_end);
		}
		return std::ranges::subrange<std::ranges::iterator_t<Range>>(result_begin, result_end);
	}
}

#endif
