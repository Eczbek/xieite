#ifndef DETAIL_XTE_HEADER_MATH_GCD
#	define DETAIL_XTE_HEADER_MATH_GCD
#
#	include "../exchange.hpp"
#	include "../trait/is_int.hpp"
#	include "../trait/is_unsigned_int.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto gcd(xte::is_int auto x, xte::is_int auto y) noexcept
	requires(xte::is_unsigned_int<decltype(x)> == xte::is_unsigned_int<decltype(y)>) {
		using common_type = std::common_type_t<decltype(x), decltype(y)>;
		auto a = static_cast<common_type>(x);
		auto b = static_cast<common_type>(y);
		while (b) {
			b = xte::exchange(a %= b, b);
		}
		return a;
	}
}

#endif
