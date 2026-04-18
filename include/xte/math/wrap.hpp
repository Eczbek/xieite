#ifndef DETAIL_XTE_HEADER_MATH_WRAP
#	define DETAIL_XTE_HEADER_MATH_WRAP
#
#	include "../math/minmax.hpp"
#	include "../math/mod.hpp"
#	include "../math/sub.hpp"
#	include "../trait/is_number.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto wrap(xte::is_number auto x, xte::is_number auto limit0, xte::is_number auto limit1) noexcept {
		using Common = std::common_type_t<decltype(x), decltype(limit0), decltype(limit1)>;
		auto [min, max] = xte::minmax(static_cast<Common>(limit0), static_cast<Common>(limit1));
		return xte::mod(static_cast<Common>(x) - min, max - min + 1) + min;
	}

	[[nodiscard]] constexpr auto wrap(xte::is_number auto x, xte::is_number auto max) noexcept {
		return xte::wrap(x, max, static_cast<decltype(x)>(0));
	}
}

#endif
