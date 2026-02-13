#ifndef DETAIL_XTE_HEADER_MATH_DIFF
#	define DETAIL_XTE_HEADER_MATH_DIFF
#
#	include "../math/abs.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto diff(xte::is_number auto x, xte::is_number auto y) noexcept {
		using Common = std::common_type_t<decltype(x), decltype(y)>;
		if constexpr (xte::is_float<Common>) {
			return xte::abs(static_cast<Common>(x) - static_cast<Common>(y));
		} else {
			using Unsigned = std::make_unsigned_t<Common>;
			return (static_cast<Common>(x) < static_cast<Common>(y))
				? (static_cast<Unsigned>(y) - static_cast<Unsigned>(x))
				: (static_cast<Unsigned>(x) - static_cast<Unsigned>(y));
		}
	};
}

#endif
