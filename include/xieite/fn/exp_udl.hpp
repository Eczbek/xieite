#ifndef DETAIL_XIEITE_HEADER_FN_EXP_UDL
#	define DETAIL_XIEITE_HEADER_FN_EXP_UDL
#
#	include "../math/exp.hpp"

namespace xieite::exp_udl {
	[[nodiscard]] consteval auto operator""_exp(unsigned long long int x) noexcept {
		return xieite::exp(x);
	}

	[[nodiscard]] consteval auto operator""_exp(long double x) noexcept {
		return xieite::exp(x);
	}
}

#endif
