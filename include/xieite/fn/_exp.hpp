#ifndef DETAIL_XIEITE_HEADER_FN_EXP
#	define DETAIL_XIEITE_HEADER_FN_EXP
#
#	include "../math/exp.hpp"

namespace xieite::_exp {
	[[nodiscard]] consteval auto operator""_exp(unsigned long long int n) noexcept {
		return xieite::exp(n);
	}

	[[nodiscard]] consteval auto operator""_exp(long double n) noexcept {
		return xieite::exp(n);
	}
}

#endif
