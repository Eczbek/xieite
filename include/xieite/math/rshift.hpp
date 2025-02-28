#pragma once

#include "../math/bit_size.hpp"

namespace xieite {
	template<std::integral T>
	[[nodiscard]] constexpr T rshift(T x, std::size_t n) noexcept {
		if (n < xieite::bit_size<T>) {
			return x >> n;
		}
		return 0;
	}
}
