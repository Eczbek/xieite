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
	[[nodiscard]] constexpr auto sub_checked(xte::is_number auto minuend, xte::is_number auto... subtrahends) noexcept {
		using common_type = std::common_type_t<decltype(minuend), decltype(subtrahends)...>;
		auto diff = static_cast<common_type>(minuend);
#	if XTE_HAS_BUILTIN(sub_overflow)
		if constexpr (!xte::is_float<common_type>) {
			return (... || __builtin_sub_overflow(diff, static_cast<common_type>(subtrahends), &diff)) ? xte::null : xte::opt(diff);
		}
#	endif
		return (!xte::is_finite(diff) || ... || ((!xte::is_finite(subtrahends) && ((subtrahends < 0) ? ((std::numeric_limits<common_type>::max() + static_cast<common_type>(subtrahends)) < diff) : ((std::numeric_limits<common_type>::lowest() + static_cast<common_type>(subtrahends)) < diff))) || (diff -= static_cast<common_type>(subtrahends), false))) ? xte::null : xte::opt(diff);
	}
}

#endif
