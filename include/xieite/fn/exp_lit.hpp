#ifndef DETAIL_XIEITE_HEADER_FN_EXP_LIT
#	define DETAIL_XIEITE_HEADER_FN_EXP_LIT
#
#	include "../math/exp.hpp"

namespace xieite::exp_lit {
	[[nodiscard]] consteval auto operator""_exp(unsigned long long int n) noexcept {
		return xieite::exp(n);
	}

	[[nodiscard]] consteval auto operator""_exp(long double n) noexcept {
		return xieite::exp(n);
	}
}

#endif
