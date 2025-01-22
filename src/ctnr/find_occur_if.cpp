export module xieite:find_occur_if;

import std;
import :is_invoc;
import :is_noex_invoc;
import :is_noex_range;
import :iters;

export namespace xieite {
	template<std::ranges::forward_range R, xieite::is_invoc<bool(std::ranges::range_common_reference_t<R>)> F>
	[[nodiscard]] constexpr std::ranges::iterator_t<R> find_occur_if(R& range, std::size_t n, F&& cond = {})
	noexcept(xieite::is_noex_invoc<F, bool(std::ranges::range_common_reference_t<R>)> && xieite::is_noex_range<R>) {
		for (auto iter : xieite::iters(range)) {
			if (std::invoke_r<bool>(cond, *iter) && !n--) {
				return iter;
			}
		}
		return std::ranges::end(range);
	}
}
