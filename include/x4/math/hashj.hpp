#pragma once

#include <bit>
#include <concepts>
#include <cstddef>
#include "../math/bits.hpp"
#include "../math/hashdist.hpp"

namespace x4 {
	template<std::integral T = std::size_t, std::convertible_to<T>... Ts>
	[[nodiscard]] constexpr T hashj(T first, Ts... rest) noexcept {
		(..., (first = std::rotl(first, static_cast<int>(x4::bits<T> / 3)) ^ x4::hashdist(static_cast<T>(rest))));
		return first;
	}
}
