#ifndef DETAIL_XIEITE_HEADER_MATH_XOR_SHIFT
#	define DETAIL_XIEITE_HEADER_MATH_XOR_SHIFT
#
#	include <concepts>
#	include <cstddef>

namespace xieite {
	template<std::integral T>
	[[nodiscard]] constexpr T xor_shift(T n, std::size_t bits) noexcept {
		return n ^ (n >> bits);
	}
}

#endif
