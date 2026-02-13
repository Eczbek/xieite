#ifndef DETAIL_XTE_HEADER_MATH_ADD_CHECKED
#	define DETAIL_XTE_HEADER_MATH_ADD_CHECKED
#
#	include "../data/null.hpp"
#	include "../data/opt.hpp"
#	include "../func/unfold.hpp"
#	include "../math/add.hpp"
#	include "../math/is_finite.hpp"
#	include "../math/neg.hpp"
#	include "../preproc/has_builtin.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include <limits>
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto add_checked(xte::is_number auto x, xte::is_number auto... ys) noexcept {
		using Common = std::common_type_t<decltype(x), decltype(ys)...>;
		auto sum = static_cast<Common>(x);
#	if XTE_HAS_BUILTIN(add_overflow)
		if constexpr (!xte::is_float<Common>) {
			return (... || __builtin_add_overflow(sum, static_cast<Common>(ys), &sum)) ? xte::null : xte::opt(sum);
		}
#	endif
		return (!xte::is_finite(x) || ... || (!xte::is_finite(ys) || (xte::neg(sum) ? ((std::numeric_limits<Common>::lowest() - sum) > static_cast<Common>(ys)) : ((std::numeric_limits<Common>::max() - sum) < static_cast<Common>(ys))) || (sum += static_cast<Common>(ys), false))) ? xte::null : xte::opt(sum);
	};
}

#endif
