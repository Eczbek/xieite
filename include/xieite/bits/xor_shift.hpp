#ifndef XIEITE_HEADER_BITS_XOR_SHIFT
#	define XIEITE_HEADER_BITS_XOR_SHIFT

#	include <concepts>
#	include <cstddef>

namespace xieite::bits {
	template<std::integral Integral_>
	[[nodiscard]] constexpr Integral_ xorShift(const Integral_ value, const std::size_t bits) noexcept {
		return value ^ (value >> bits);
	}
}

#endif
