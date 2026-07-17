#ifndef DETAIL_XTE_HEADER_MATH_DIV
#	define DETAIL_XTE_HEADER_MATH_DIV
#
#	include "../math/abs.hpp"
#	include "../math/sign.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include "../trait/try_unsigned.hpp"
#	include "../util/make.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto div(xte::is_arithmetic auto dividend, xte::is_arithmetic auto... divisors) noexcept {
		using common_type = std::common_type_t<decltype(dividend), decltype(divisors)...>;
		using unsigned_type = xte::try_unsigned<common_type>;
		return static_cast<common_type>(xte::make<unsigned_type>((xte::make<unsigned_type>(xte::abs(dividend)) / ... / xte::make<unsigned_type>(xte::abs(divisors))))
			* static_cast<unsigned_type>(xte::sign(dividend, divisors...)));
	};
}

#endif
