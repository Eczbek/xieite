#ifndef XIEITE_HEADER_BITS_XOR_SHIFT
#	define XIEITE_HEADER_BITS_XOR_SHIFT

#	include <concepts>
#	include <cstddef>

namespace xieite::bits {
	template<std::integral Integral>
	[[nodiscard]] constexpr Integral xorShift(const Integral value, const std::size_t bits) noexcept {
		return value ^ (value >> bits);
	}
}

#endif
