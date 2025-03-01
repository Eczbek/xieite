#pragma once

#include <algorithm>
#include <array>
#include <bit>
#include "../fn/unroll.hpp"

namespace x4 {
	template<typename T, typename U>
	[[nodiscard]] constexpr T bitcast(const U& x) noexcept {
		return x4::unroll<std::min(sizeof(T), sizeof(U))>([&x]<std::size_t... i> -> T {
			const auto bits = std::bit_cast<std::array<char, sizeof(U)>>(x);
			return std::bit_cast<T>(std::array<char, sizeof(T)> { bits[i]... });
		});
	}
}
