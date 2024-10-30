export module xieite:median;

import std;
import :is_arith;
import :avg;

export namespace xieite {
	template<std::ranges::forward_range R, typename T = std::common_type_t<std::ranges::range_value_t<R>, double>>
	requires(std::ranges::sized_range<R> && xieite::is_arith<std::ranges::range_value_t<R>>)
	[[nodiscard]] constexpr T median(R&& range) noexcept {
		std::vector<std::ranges::iterator_t<R>> its;
		const std::size_t size = std::ranges::size(range);
		its.reserve(size);
		for (auto it = std::ranges::begin(range); it != std::ranges::end(range); ++it) {
			its.push_back(it);
		}
		std::ranges::sort(its, std::ranges::less());
		return (size % 2)
			? static_cast<T>(*its[size / 2])
			: static_cast<T>(xieite::avg(*its[size / 2 - 1], *its[size / 2]));
	}
}
