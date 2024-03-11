#ifndef XIEITE_HEADER_BITS_XOR_SHIFT
#	define XIEITE_HEADER_BITS_XOR_SHIFT

#	include <concepts>
#	include <cstddef>

namespace xieite::bits {
	template<std::integral Integer>
	[[nodiscard]] constexpr Integer xorShift(const Integer value, const std::size_t bits) noexcept {
		return value ^ (value >> bits);
	}
}

#endif
