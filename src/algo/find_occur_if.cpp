export module xieite:find_occur_if;

import std;
import :is_invoc;
import :is_nothrow_invoc;
import :is_nothrow_range;

export namespace xieite {
	template<std::ranges::forward_range R, xieite::is_invoc<bool(std::ranges::range_common_reference_t<R>)> F>
	[[nodiscard]] constexpr std::ranges::iterator_t<R> find_occur_if(R& range, std::size_t n, F&& cond = {})
	noexcept(xieite::is_nothrow_invoc<F, bool(std::ranges::range_common_reference_t<R>)> && xieite::is_nothrow_range<R>) {
		for (auto it = std::ranges::begin(range); it != std::ranges::end(range); ++it) {
			if (std::invoke_r<bool>(cond, *it) && !n--) {
				return it;
			}
		}
		return end;
	}
}
