export module xieite:little_endify;

import std;

export namespace xieite {
	template<std::integral T>
	[[nodiscard]] constexpr T little_endify(T value) noexcept {
		return (std::endian::native == std::endian::big) ? std::byteswap(value) : value;
	}
}
