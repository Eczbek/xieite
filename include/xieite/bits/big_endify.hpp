#ifndef XIEITE_HEADER_BITS_BIG_ENDIFY
#	define XIEITE_HEADER_BITS_BIG_ENDIFY

#	include <bit>
#	include <concepts>
#	include "../system/endian.hpp"

namespace xieite::bits {
	template<std::integral Integral_>
	[[nodiscard]] constexpr Integral_ bigEndify(const Integral_ value) noexcept {
		return xieite::system::endian::little ? std::byteswap(value) : value;
	}
}

#endif
