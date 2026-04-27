#ifndef DETAIL_XTE_HEADER_MATH_DIFF
#	define DETAIL_XTE_HEADER_MATH_DIFF
#
#	include "../math/abs.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto diff(xte::is_number auto x, xte::is_number auto y) noexcept {
		using common_type = std::common_type_t<decltype(x), decltype(y)>;
		if constexpr (xte::is_float<common_type>) {
			return xte::abs(static_cast<common_type>(x) - static_cast<common_type>(y));
		} else {
			using unsigned_type = std::make_unsigned_t<common_type>;
			return (static_cast<common_type>(x) < static_cast<common_type>(y))
				? static_cast<unsigned_type>(static_cast<unsigned_type>(y) - static_cast<unsigned_type>(x))
				: static_cast<unsigned_type>(static_cast<unsigned_type>(x) - static_cast<unsigned_type>(y));
		}
	};
}

#endif
