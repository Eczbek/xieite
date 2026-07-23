#ifndef DETAIL_XTE_HEADER_MATH_MUL_CHECKED
#	define DETAIL_XTE_HEADER_MATH_MUL_CHECKED
#
#	include "../data/null.hpp"
#	include "../data/opt.hpp"
#	include "../math/abs.hpp"
#	include "../math/approx_equal.hpp"
#	include "../math/highest.hpp"
#	include "../math/is_finite.hpp"
#	include "../math/lowest.hpp"
#	include "../math/mul.hpp"
#	include "../preproc/has_builtin.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include "../trait/is_float.hpp"
#	include "../util/assign.hpp"
#	include "../util/make.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto mul_checked(xte::is_arithmetic auto first, xte::is_arithmetic auto... rest) noexcept {
		using common_type = std::common_type_t<decltype(first), decltype(rest)...>;
		auto prod = xte::make<common_type>(first);
#	if XTE_HAS_BUILTIN(mul_overflow)
		if constexpr (!xte::is_float<common_type>) {
			return (... || __builtin_mul_overflow(prod, static_cast<common_type>(rest), &prod)) ? xte::null : xte::opt(prod);
		}
#	endif
		bool overflow;
		(void)(!xte::is_finite(prod) || ... || (xte::approx_equal(prod, 0) || (overflow = !xte::is_finite(rest) || (xte::abs(xte::make<common_type>(rest)) > (xte::abs(((0 < prod) == (0 < rest)) ? xte::highest<common_type> : xte::lowest<common_type>) / xte::abs(prod)))) || !xte::assign(prod, prod * xte::make<common_type>(rest))));
		return overflow ? xte::null : xte::opt(prod);
	}
}

#endif
