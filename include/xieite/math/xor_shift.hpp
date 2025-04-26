#ifndef DETAIL_XIEITE_HEADER_MATH_XOR_SHIFT
#	define DETAIL_XIEITE_HEADER_MATH_XOR_SHIFT
#
#	include <concepts>
#	include <cstddef>

namespace xieite {
	template<std::integral Int>
	[[nodiscard]] constexpr Int xor_shift(Int x, std::size_t bits) noexcept {
		return x ^ (x >> bits);
	}
}

#endif
