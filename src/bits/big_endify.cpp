export module xieite:bits.bigEndify;

import std;

export namespace xieite::bits {
	template<std::integral Integral>
	[[nodiscard]] constexpr Integral bigEndify(const Integral value) noexcept {
		return (std::endian::native == std::endian::little) ? std::byteswap(value) : value;
	}
}
