#ifndef DETAIL_XTE_HEADER_MATH_MOD
#	define DETAIL_XTE_HEADER_MATH_MOD
#
#	include "../math/rem.hpp"
#	include "../math/sign.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include "../util/make.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto mod(xte::is_arithmetic auto dividend, xte::is_arithmetic auto... divisors) noexcept {
		using common_type = std::common_type_t<decltype(dividend), decltype(divisors)...>;
		auto result = xte::make<common_type>(dividend);
		return (..., (result = xte::rem(xte::rem(result, divisors) + xte::make<common_type>(divisors) * (xte::sign(result, divisors) < 0), divisors)));
	};
}

#endif
