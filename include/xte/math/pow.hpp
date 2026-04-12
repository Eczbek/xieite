#ifndef DETAIL_XTE_HEADER_MATH_POW
#	define DETAIL_XTE_HEADER_MATH_POW
#
#	include "../math/abs.hpp"
#	include "../trait/is_int.hpp"
#	include <type_traits>
#	include <utility>

namespace xte {
	[[nodiscard]] constexpr auto pow(xte::is_int auto base, xte::is_int auto exp) noexcept {
		using Common = std::common_type_t<decltype(base), decltype(exp)>;
		if ((base == 1) || (exp == 1)) {
			return static_cast<Common>(base);
		}
		if (base == -1) {
			return static_cast<Common>((exp & 1) ? base : -base);
		}
		if (exp < 0) {
			if (!base) {
				std::unreachable();
			}
			return static_cast<Common>(0);
		}
		if (!exp) {
			return static_cast<Common>(1);
		}
		Common power = 1;
		while (base && (exp > 1)) {
			if (exp & 1) {
				power *= base;
				--exp;
			}
			base *= base;
			exp >>= 1;
		}
		return power * base;
	}
}

#endif
