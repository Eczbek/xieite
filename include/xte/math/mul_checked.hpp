#ifndef DETAIL_XTE_HEADER_MATH_MUL_CHECKED
#	define DETAIL_XTE_HEADER_MATH_MUL_CHECKED
#
#	include "../data/null.hpp"
#	include "../data/opt.hpp"
#	include "../math/abs.hpp"
#	include "../math/approx_equal.hpp"
#	include "../math/is_finite.hpp"
#	include "../math/mul.hpp"
#	include "../preproc/has_builtin.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include "../util/assign.hpp"
#	include <limits>
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto mul_checked(xte::is_number auto first, xte::is_number auto... rest) noexcept {
		using common_type = std::common_type_t<decltype(first), decltype(rest)...>;
		auto prod = static_cast<common_type>(first);
#	if XTE_HAS_BUILTIN(mul_overflow)
		if constexpr (!xte::is_float<common_type>) {
			return (... || __builtin_mul_overflow(prod, static_cast<common_type>(rest), &prod)) ? xte::null : xte::opt(prod);
		}
#	endif
		bool overflow;
		(void)(!xte::is_finite(prod) || ... || (xte::approx_equal(prod, 0) || (overflow = !xte::is_finite(rest) || (xte::abs(static_cast<common_type>(rest)) > (xte::abs(((prod < 0) == (rest < 0)) ? std::numeric_limits<common_type>::max() : std::numeric_limits<common_type>::lowest()) / xte::abs(prod)))) || !xte::assign(prod, prod * static_cast<common_type>(rest))));
		return overflow ? xte::null : xte::opt(prod);
	}
}

#endif
