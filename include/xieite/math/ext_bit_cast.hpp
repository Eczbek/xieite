#ifndef DETAIL_XIEITE_HEADER_MATH_EXT_BIT_CAST
#	define DETAIL_XIEITE_HEADER_MATH_EXT_BIT_CAST
#
#	include <algorithm>
#	include <bit>
#	include "../fn/unroll.hpp"
#	include "../pp/attr.hpp"

namespace DETAIL_XIEITE::ext_bit_cast {
	template<typename T>
	struct XIEITE_ATTR_PACK(array {
		char data[sizeof(T)];
	});
}

namespace xieite {
	template<typename T, typename U>
	[[nodiscard]] constexpr T ext_bit_cast(const U& x) noexcept {
		return xieite::unroll<std::min(sizeof(T), sizeof(U))>([&x]<std::size_t... i> -> T {
			const auto bits = std::bit_cast<DETAIL_XIEITE::ext_bit_cast::array<U>>(x);
			return std::bit_cast<T>(DETAIL_XIEITE::ext_bit_cast::array<T> { bits[i]... });
		});
	}
}

#endif
