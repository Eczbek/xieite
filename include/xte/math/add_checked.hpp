#ifndef DETAIL_XTE_HEADER_MATH_ADD_CHECKED
#	define DETAIL_XTE_HEADER_MATH_ADD_CHECKED
#
#	include "../data/null.hpp"
#	include "../data/opt.hpp"
#	include "../func/unfold.hpp"
#	include "../math/add.hpp"
#	include "../math/is_finite.hpp"
#	include "../preproc/has_builtin.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include <limits>
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto add_checked(xte::is_number auto augend, xte::is_number auto... addends) noexcept {
		using common_type = std::common_type_t<decltype(augend), decltype(addends)...>;
		auto sum = static_cast<common_type>(augend);
#	if XTE_HAS_BUILTIN(add_overflow)
		if constexpr (!xte::is_float<common_type>) {
			return (... || __builtin_add_overflow(sum, static_cast<common_type>(addends), &sum)) ? xte::null : xte::opt(sum);
		}
#	endif
		return (!xte::is_finite(augend) || ... || (!xte::is_finite(addends) || ((sum < 0) ? ((std::numeric_limits<common_type>::lowest() - sum) > static_cast<common_type>(addends)) : ((std::numeric_limits<common_type>::max() - sum) < static_cast<common_type>(addends))) || (sum += static_cast<common_type>(addends), false))) ? xte::null : xte::opt(sum);
	};
}

#endif
