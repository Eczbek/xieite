#ifndef DETAIL_XIEITE_HEADER_MATH_BIG_ENDIFY
#	define DETAIL_XIEITE_HEADER_MATH_BIG_ENDIFY
#
#	include <bit>
#	include <concepts>

namespace xieite {
	template<std::integral Int>
	[[nodiscard]] constexpr Int big_endify(Int x) noexcept {
		return (std::endian::native == std::endian::little) ? std::byteswap(x) : x;
	}
}

#endif
