export module xieite:math.isPowerOf2;

import std;

export namespace xieite::math {
	template<std::unsigned_integral UnsignedIntegral>
	[[nodiscard]] constexpr bool isPowerOf2(const UnsignedIntegral value) noexcept {
		return value && !(value & (value - 1));
	}
}

// https://graphics.stanford.edu/~seander/bithacks.html#DetermineIfPowerOf2
