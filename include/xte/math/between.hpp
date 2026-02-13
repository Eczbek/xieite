#ifndef DETAIL_XTE_HEADER_MATH_BETWEEN
#	define DETAIL_XTE_HEADER_MATH_BETWEEN
#
#	include "../func/visitor.hpp"
#	include "../math/minmax.hpp"
#	include "../trait/is_number.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr bool between(xte::is_number auto x, xte::is_number auto limit0, xte::is_number auto limit1, bool min_incl, bool max_incl) noexcept {
		using Common = std::common_type_t<decltype(x), decltype(limit0), decltype(limit1)>;
		auto [min, max] = xte::minmax(static_cast<Common>(limit0), static_cast<Common>(limit1));
		auto mid = static_cast<Common>(x);
		return (min_incl ? (min <= mid) : (min < mid))
			&& (max_incl ? (mid <= max) : (mid < max));
	}

	[[nodiscard]] constexpr bool between(xte::is_number auto x, xte::is_number auto limit0, xte::is_number auto limit1) noexcept {
		return xte::between(x, limit0, limit1, true, true);
	}
}

#endif
