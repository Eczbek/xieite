#ifndef DETAIL_XIEITE_HEADER_MATH_EXT_BIT_CAST
#	define DETAIL_XIEITE_HEADER_MATH_EXT_BIT_CAST
#
#	include <algorithm>
#	include <bit>
#	include "../fn/unroll.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<typename T>
	[[nodiscard]] constexpr T ext_bit_cast(auto&& x) noexcept {
		return xieite::unroll<std::min(sizeof(T), sizeof(x))>([&x]<std::size_t... i> -> T {
			struct Array0 {
				unsigned char data[sizeof(x)];
			};
			struct Array1 {
				unsigned char data[sizeof(T)];
			};
			const auto bits = std::bit_cast<Array0>(XIEITE_FWD(x));
			return std::bit_cast<T>(Array1 { bits[i]... });
		});
	}
}

#endif
