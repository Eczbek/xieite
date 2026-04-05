#ifndef DETAIL_XTE_HEADER_MATH_SIGN_CAST
#	define DETAIL_XTE_HEADER_MATH_SIGN_CAST
#
#	include "../math/as_signed.hpp"
#	include "../math/as_unsigned.hpp"
#	include "../trait/is_int.hpp"
#	include "../trait/is_number.hpp"
#	include "../trait/is_unsigned.hpp"

namespace xte {
	template<xte::is_int T>
	constexpr auto sign_cast = [][[nodiscard]](xte::is_number auto x) static noexcept -> T {
		if constexpr (xte::is_unsigned<T>) {
			return static_cast<T>(xte::as_unsigned(x));
		} else {
			return static_cast<T>(xte::as_signed(x));
		}
	};
}

#endif
