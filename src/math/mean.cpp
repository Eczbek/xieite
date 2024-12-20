export module xieite:mean;

import std;
import :is_arith;

export namespace xieite {
	template<std::ranges::forward_range R, typename T = std::common_type_t<std::ranges::range_value_t<R>, double>>
	requires(std::ranges::sized_range<R> && xieite::is_arith<std::ranges::range_value_t<R>>)
	[[nodiscard]] constexpr T mean(R&& range) noexcept {
		T result = 0;
		for (auto it = std::ranges::begin(range); it != std::ranges::end(range); ++it) {
			result += static_cast<T>(*it);
		}
		return result / std::ranges::size(range);
	}
}
