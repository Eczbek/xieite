#ifndef DETAIL_XTE_HEADER_MATH_SIGN_CAST
#	define DETAIL_XTE_HEADER_MATH_SIGN_CAST
#
#	include "../trait/is_arithmetic.hpp"
#	include "../trait/is_int.hpp"
#	include "../trait/is_signed_int.hpp"
#	include "../trait/is_unsigned_int.hpp"
#	include "../trait/try_signed.hpp"
#	include "../trait/try_unsigned.hpp"

namespace xte {
	[[nodiscard]] constexpr auto as_unsigned(xte::is_arithmetic auto value) noexcept {
		return static_cast<xte::try_unsigned<decltype(value)>>(value);
	};

	[[nodiscard]] constexpr auto as_signed(xte::is_arithmetic auto value) noexcept {
		return static_cast<xte::try_signed<decltype(value)>>(value);
	};

	template<xte::is_int target_type>
	[[nodiscard]] constexpr target_type sign_cast(xte::is_int auto value) noexcept {
		if constexpr (xte::is_unsigned_int<target_type>) {
			return static_cast<target_type>(xte::as_unsigned(value));
		} else {
			return static_cast<target_type>(xte::as_signed(value));
		}
	};
}

#endif
