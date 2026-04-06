#ifndef DETAIL_XTE_HEADER_MATH_AS_SIGNED
#	define DETAIL_XTE_HEADER_MATH_AS_SIGNED
#
#	include "../trait/is_number.hpp"
#	include "../trait/try_signed.hpp"

namespace xte {
	inline constexpr auto as_signed = [][[nodiscard]](xte::is_number auto x) static noexcept {
		return static_cast<xte::try_signed<decltype(x)>>(x);
	};
}

#endif
