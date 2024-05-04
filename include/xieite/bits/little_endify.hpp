#ifndef XIEITE_HEADER_BITS_LITTLE_ENDIFY
#	define XIEITE_HEADER_BITS_LITTLE_ENDIFY

#	include <bit>
#	include <concepts>
#	include "../system/endian.hpp"

namespace xieite::bits {
	template<std::integral Integral_>
	[[nodiscard]] constexpr Integral_ littleEndify(const Integral_ value) noexcept {
		return xieite::system::endian::big ? std::byteswap(value) : value;
	}
}

#endif
