#pragma once
#include <cmath>
#include <concepts>
#include <type_traits>

namespace xieite::math {
	template<std::integral N>
	[[nodiscard]]
	constexpr std::make_unsigned_t<N> difference(const N a, const N b) noexcept {
		return (a > b)
			? static_cast<std::make_unsigned_t<N>>(a) - static_cast<std::make_unsigned_t<N>>(b)
			: static_cast<std::make_unsigned_t<N>>(b) - static_cast<std::make_unsigned_t<N>>(a);
	}

	template<std::floating_point N>
	[[nodiscard]]
	constexpr N difference(const N a, const N b) noexcept {
		return std::abs(a - b);
	}
}