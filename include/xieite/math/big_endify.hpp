#ifndef DETAIL_XIEITE_HEADER_MATH_BIG_ENDIFY
#	define DETAIL_XIEITE_HEADER_MATH_BIG_ENDIFY
#
#	include <bit>
#	include <concepts>

namespace xieite {
	template<std::integral T>
	[[nodiscard]] constexpr T big_endify(T n) noexcept {
		return (std::endian::native == std::endian::little) ? std::byteswap(n) : n;
	}
}

#endif
