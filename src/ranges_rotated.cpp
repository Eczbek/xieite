export module xieite:ranges_rotated;

import std;
import :is_invoc;
import :is_nothrow_invoc;
import :is_nothrow_range;

export namespace xieite {
	template<std::ranges::input_range R0, std::ranges::input_range R1, xieite::is_invoc<bool(std::ranges::range_reference_t<R0>, std::ranges::range_reference_t<R1>)> F = std::ranges::equal_to>
	[[nodiscard]] constexpr bool ranges_rotated(R0&& range0, R1&& range1, F&& comp = {})
	noexcept(xieite::is_nothrow_invoc<F, bool(std::ranges::range_reference_t<R0>, std::ranges::range_reference_t<R1>)> && xieite::is_nothrow_range<R0> && xieite::is_nothrow_range<R1>) {
		const auto begin0 = std::ranges::begin(range0);
		const auto begin1 = std::ranges::begin(range1);
		if (std::ranges::size(range0) == std::ranges::size(range1)) {
			for (auto it = begin0; it != std::ranges::end(range0); ++it) {
				auto copy1 = it;
				auto copy2 = begin1;
				while (copy2 != end2) {
					if (copy1 == end1) {
						copy1 = begin0;
					}
					if (!std::invoke_r<bool>(comp, *copy1, *copy2)) {
						break;
					}
					++copy1;
					++copy2;
				}
				if (copy2 == std::ranges::end(range1)) {
					return true;
				}
			}
		}
		return false;
	}
}
