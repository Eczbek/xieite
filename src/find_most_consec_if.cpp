export module xieite:find_most_consec_if;

import std;
import :is_invoc;
import :is_nothrow_invoc;
import :is_nothrow_range;

export namespace xieite {
	template<std::ranges::forward_range R, xieite::is_invoc<bool(std::ranges::range_reference_t<R>)> F>
	requires(std::ranges::sized_range<R>)
	[[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<R>> find_most_consec_if(R& range, F&& sel = {})
	noexcept(xieite::is_nothrow_invoc<F, bool(std::ranges::range_reference_t<R>)> && xieite::is_nothrow_range<R>) {
		auto it = std::ranges::begin(range);
		auto curr_begin = it;
		auto curr_end = it;
		auto result_begin = curr_begin;
		auto result_end = curr_end;
		bool prev = false;
		for (; it != std::ranges::end(range); ++it) {
			const bool curr = std::invoke_r<bool>(sel, *it);
			if (curr) {
				if (!prev) {
					curr_begin = it;
					curr_end = it;
				}
				++curr_end;
			} else if (prev && (std::ranges::distance(curr_begin, curr_end) > std::ranges::distance(result_begin, result_end))) {
				result_begin = curr_begin;
				result_end = curr_end;
			}
			prev = curr;
		}
		if (prev && (std::ranges::distance(curr_begin, curr_end) > std::ranges::distance(result_begin, result_end))) {
			return std::ranges::subrange<std::ranges::iterator_t<R>>(curr_begin, curr_end);
		}
		return std::ranges::subrange<std::ranges::iterator_t<R>>(result_begin, result_end);
	}
}
