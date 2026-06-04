#ifndef DETAIL_XTE_HEADER_MATH_DIFF
#	define DETAIL_XTE_HEADER_MATH_DIFF
#
#	include "../math/abs.hpp"
#	include "../math/highest.hpp"
#	include "../math/sub_checked.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include "../util/cast.hpp"
#	include <limits>
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto diff(xte::is_number auto x, xte::is_number auto y) noexcept {
		if constexpr (using common_type = std::common_type_t<decltype(x), decltype(y)>; xte::is_float<common_type>) {
			if (auto diff = xte::sub_checked(x, y)) {
				return xte::abs(*diff);
			} else if constexpr (std::numeric_limits<common_type>::has_infinity) {
				return std::numeric_limits<common_type>::infinity();
			} else {
				return xte::highest<common_type>;
			}
		} else {
			using unsigned_type = std::make_unsigned_t<common_type>;
			return (static_cast<common_type>(x) < static_cast<common_type>(y))
				? static_cast<unsigned_type>(static_cast<unsigned_type>(y) - static_cast<unsigned_type>(x))
				: static_cast<unsigned_type>(static_cast<unsigned_type>(x) - static_cast<unsigned_type>(y));
		}
	};
}

#endif
