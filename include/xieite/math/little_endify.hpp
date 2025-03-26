#ifndef DETAIL_XIEITE_HEADER_MATH_LITTLE_ENDIFY
#	define DETAIL_XIEITE_HEADER_MATH_LITTLE_ENDIFY
#
#	include <bit>
#	include <concepts>

namespace xieite {
	template<std::integral T>
	[[nodiscard]] constexpr T little_endify(T n) noexcept {
		return (std::endian::native == std::endian::big) ? std::byteswap(n) : n;
	}
}

#endif
