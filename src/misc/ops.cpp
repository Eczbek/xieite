export module xieite:ops;

import std;
import :is_ordering;

template<xieite::is_ordering Ordering>
[[nodiscard]] constexpr Ordering operator||(Ordering left, Ordering right) noexcept {
	return std::is_eq(left) ? right : left;
}

template<typename T>
[[nodiscard]] constexpr auto operator<=>(const std::ranges::view_interface<T>& left, const std::ranges::view_interface<T>& right) noexcept {
	return std::lexicographical_compare_three_way(left.cbegin(), left.cend(), right.cbegin(), right.cend());
}
