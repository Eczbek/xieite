export module xieite:xor_shift;

import std;

export namespace xieite {
	template<std::integral T>
	[[nodiscard]] constexpr T xor_shift(T n, std::size_t bits) noexcept {
		return n ^ (n >> bits);
	}
}
