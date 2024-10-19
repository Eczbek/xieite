export module xieite:strings.compareIgnoreCase;

import std;
import :strings.uppercase;

export namespace xieite::strings {
	[[nodiscard]] constexpr std::strong_ordering compareIgnoreCase(const char left, const char right) noexcept {
		return xieite::strings::uppercase(left) <=> xieite::strings::uppercase(right);
	}

	[[nodiscard]] constexpr std::strong_ordering compareIgnoreCase(const std::string_view left, const std::string_view right) noexcept {
		const std::size_t size = std::min(left.size(), right.size());
		for (std::size_t i = 0; i < size; ++i) {
			const std::strong_ordering order = xieite::strings::compareIgnoreCase(left[i], right[i]);
			if (!std::is_eq(order)) {
				return order;
			}
		}
		return std::strong_ordering::equal;
	}
}
