#ifndef DETAIL_XTE_HEADER_MATH_WRAP
#	define DETAIL_XTE_HEADER_MATH_WRAP
#
#	include "../math/minmax.hpp"
#	include "../math/mod.hpp"
#	include "../trait/is_number.hpp"
#	include <limits>
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto wrap(xte::is_number auto x, xte::is_number auto limit0, xte::is_number auto limit1) noexcept {
		using Common = std::common_type_t<decltype(x), decltype(limit0), decltype(limit1)>;
		if (limit0 == limit1) {
			return static_cast<Common>(limit0);
		}
		auto [min, max] = xte::minmax(static_cast<Common>(limit0), static_cast<Common>(limit1));
		Common y = static_cast<Common>(x);
		return ((y >= min) && (y <= max))
			? y
			: (min == std::numeric_limits<Common>::min())
				? (y - max + min)
				: (max == std::numeric_limits<Common>::max())
					? (y != std::numeric_limits<Common>::min())
						? max
						: (min - y + max)
					: (xte::mod(y - min, max - min + 1) + min);
	}
}

#endif
