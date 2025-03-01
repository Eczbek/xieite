#pragma once

#include "../math/bits.hpp"

namespace x4 {
	template<std::integral T>
	[[nodiscard]] constexpr T lshift(T x, std::size_t n) noexcept {
		if (n < x4::bits<T>) {
			return x << n;
		}
		return 0;
	}
}
