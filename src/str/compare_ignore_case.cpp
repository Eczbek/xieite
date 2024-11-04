export module xieite:compare_ignore_case;

import std;
import :sv;
import :uppercase;

export namespace xieite {
	template<typename C = char, typename Traits = std::char_traits<C>>
	[[nodiscard]] constexpr std::strong_ordering compare_ignore_case(xieite::sv<C, Traits> left, xieite::sv<C, Traits> right) noexcept {
		const std::size_t size = std::min(left.view.size(), right.view.size());
		for (std::size_t i = 0; i < size; ++i) {
			if (std::strong_ordering order = xieite::uppercase(left.view[i]) <=> xieite::uppercase(right.view[i]); !std::is_eq(order)) {
				return order;
			}
		}
		return std::strong_ordering::equal;
	}
}
