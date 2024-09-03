export module xieite:bits.littleEndify;

import std;

export namespace xieite::bits {
	template<std::integral Integral>
	[[nodiscard]] constexpr Integral littleEndify(const Integral value) noexcept {
		return (std::endian::native == std::endian::big) ? std::byteswap(value) : value;
	}
}
