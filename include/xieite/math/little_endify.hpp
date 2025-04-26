#ifndef DETAIL_XIEITE_HEADER_MATH_LITTLE_ENDIFY
#	define DETAIL_XIEITE_HEADER_MATH_LITTLE_ENDIFY
#
#	include <bit>
#	include <concepts>

namespace xieite {
	template<std::integral Int>
	[[nodiscard]] constexpr Int little_endify(Int x) noexcept {
		return (std::endian::native == std::endian::big) ? std::byteswap(x) : x;
	}
}

#endif
