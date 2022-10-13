#pragma once
#include <cmath>
#include <concepts>
#include <type_traits>

namespace gcufl::math {
	template<std::integral N>
	constexpr auto difference(const N a, const N b) noexcept -> std::make_unsigned_t<N> {
		return (a > b)
			? static_cast<std::make_unsigned_t<N>>(a) - static_cast<std::make_unsigned_t<N>>(b)
			: static_cast<std::make_unsigned_t<N>>(b) - static_cast<std::make_unsigned_t<N>>(a);
	}

	template<std::floating_point N>
	constexpr N difference(const N a, const N b) noexcept {
		return std::abs(a - b);
	}
}
