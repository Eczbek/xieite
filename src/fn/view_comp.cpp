export module xieite:view_comp;

import std;

namespace xieite::view_comp {
	template<typename T>
	[[nodiscard]] constexpr auto operator<=>(const std::ranges::view_interface<T>& left, const std::ranges::view_interface<T>& right) noexcept {
		return std::ranges::lexicographical_compare(left, right);
	}
}
