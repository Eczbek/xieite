#ifndef DETAIL_XTE_HEADER_MATH_BETWEEN
#	define DETAIL_XTE_HEADER_MATH_BETWEEN
#
#	include "../func/visitor.hpp"
#	include "../math/min_max.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include "../util/cast.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr bool between(xte::is_arithmetic auto x, xte::is_arithmetic auto limit0, xte::is_arithmetic auto limit1, bool min_incl, bool max_incl) noexcept {
		using common_type = std::common_type_t<decltype(x), decltype(limit0), decltype(limit1)>;
		auto [min, max] = xte::min_max(xte::cast<common_type>(limit0), xte::cast<common_type>(limit1));
		auto mid = xte::cast<common_type>(x);
		return (min_incl ? (min <= mid) : (min < mid))
			&& (max_incl ? (mid <= max) : (mid < max));
	}

	[[nodiscard]] constexpr bool between(xte::is_arithmetic auto x, xte::is_arithmetic auto limit0, xte::is_arithmetic auto limit1) noexcept {
		return xte::between(x, limit0, limit1, true, true);
	}
}

#endif
