#ifndef DETAIL_XTE_HEADER_MATH_SIGN_CAST
#	define DETAIL_XTE_HEADER_MATH_SIGN_CAST
#
#	include "../math/as_signed.hpp"
#	include "../math/as_unsigned.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include "../trait/is_int.hpp"
#	include "../trait/is_unsigned.hpp"
#	include "../util/cast.hpp"

namespace xte {
	template<xte::is_int T>
	constexpr auto sign_cast = [][[nodiscard]](xte::is_arithmetic auto x) static noexcept -> T {
		if constexpr (xte::is_unsigned<T>) {
			return xte::cast<T>(xte::as_unsigned(x));
		} else {
			return xte::cast<T>(xte::as_signed(x));
		}
	};
}

#endif
