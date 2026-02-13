#ifndef DETAIL_XTE_HEADER_MATH_SUB_CHECKED
#	define DETAIL_XTE_HEADER_MATH_SUB_CHECKED
#
#	include "../data/null.hpp"
#	include "../data/opt.hpp"
#	include "../func/unfold.hpp"
#	include "../math/is_finite.hpp"
#	include "../math/sub.hpp"
#	include "../preproc/has_builtin.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include "../util/assign.hpp"
#	include <limits>
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto sub_checked(xte::is_number auto x, xte::is_number auto... ys) noexcept {
		using Common = std::common_type_t<decltype(x), decltype(ys)...>;
		auto diff = static_cast<Common>(x);
#	if XTE_HAS_BUILTIN(sub_overflow)
		if constexpr (!xte::is_float<Common>) {
			return (... || __builtin_sub_overflow(diff, static_cast<Common>(ys), &diff)) ? xte::null : xte::opt(diff);
		}
#	endif
		return (!xte::is_finite(diff) || ... || ((!xte::is_finite(ys) && (xte::neg(static_cast<Common>(ys)) ? ((std::numeric_limits<Common>::max() + static_cast<Common>(ys)) < diff) : ((std::numeric_limits<Common>::lowest() + static_cast<Common>(ys)) < diff))) || (diff -= static_cast<Common>(ys), false))) ? xte::null : xte::opt(diff);
	}
}

#endif
