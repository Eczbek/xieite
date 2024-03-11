#ifndef XIEITE_HEADER_BITS_LITTLE_ENDIFY
#	define XIEITE_HEADER_BITS_LITTLE_ENDIFY

#	include <bit>
#	include <concepts>
#	include "../system/endian.hpp"

namespace xieite::bits {
	template<std::integral Integer>
	[[nodiscard]] constexpr Integer littleEndify(const Integer value) noexcept {
		return xieite::system::endian::big ? std::byteswap(value) : value;
	}
}

#endif
