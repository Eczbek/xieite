#ifndef DETAIL_XTE_HEADER_MATH_AS_UNSIGNED
#	define DETAIL_XTE_HEADER_MATH_AS_UNSIGNED
#
#	include "../math/try_unsigned.hpp"
#	include "../trait/is_number.hpp"

namespace xte {
	inline constexpr auto as_unsigned = [][[nodiscard]](xte::is_number auto x) static noexcept {
		return static_cast<xte::try_unsigned<decltype(x)>>(x);
	};
}

#endif
