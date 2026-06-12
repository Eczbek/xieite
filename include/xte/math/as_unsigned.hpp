#ifndef DETAIL_XTE_HEADER_MATH_AS_UNSIGNED
#	define DETAIL_XTE_HEADER_MATH_AS_UNSIGNED
#
#	include "../trait/is_arithmetic.hpp"
#	include "../trait/try_unsigned.hpp"

namespace xte {
	inline constexpr auto as_unsigned = [][[nodiscard]](xte::is_arithmetic auto x) static noexcept {
		return static_cast<xte::try_unsigned<decltype(x)>>(x);
	};
}

#endif
