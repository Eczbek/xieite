#ifndef DETAIL_XTE_HEADER_MATH_REM
#	define DETAIL_XTE_HEADER_MATH_REM
#
#	include "../math/abs.hpp"
#	include "../math/sign.hpp"
#	include "../trait/is_number.hpp"
#	include "../trait/is_float.hpp"
#	include <cmath>
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto rem(xte::is_number auto dividend, xte::is_number auto... divisors) noexcept {
		using common_type = std::common_type_t<decltype(dividend), decltype(divisors)...>;
		if constexpr (xte::is_float<common_type>) {
			auto result = static_cast<common_type>(dividend);
			return (..., (result = std::fmod(result, static_cast<common_type>(divisors))));
		} else {
			using unsigned_type = std::make_unsigned_t<common_type>;
			return static_cast<common_type>(static_cast<unsigned_type>((static_cast<unsigned_type>(xte::abs(dividend)) % ... % static_cast<unsigned_type>(xte::abs(divisors))))
				* static_cast<unsigned_type>(xte::sign(dividend)));
		}
	};
}

#endif
