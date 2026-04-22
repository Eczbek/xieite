#ifndef DETAIL_XTE_HEADER_MATH_WRAP
#	define DETAIL_XTE_HEADER_MATH_WRAP
#
#	include "../math/minmax.hpp"
#	include "../math/mod.hpp"
#	include "../trait/is_number.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto wrap(xte::is_number auto x, xte::is_number auto limit0, xte::is_number auto limit1) noexcept {
		using Common = std::common_type_t<decltype(x), decltype(limit0), decltype(limit1)>;
		auto [min, max] = xte::minmax(static_cast<Common>(limit0), static_cast<Common>(limit1));
		if constexpr (xte::is_float<Common>) {
			return xte::mod(static_cast<Common>(x) - min, max - min + 1) + min;
		} else {
			using Unsigned = std::make_unsigned_t<Common>;
			auto range = static_cast<Unsigned>(max) - static_cast<Unsigned>(min) + 1;
			if (!range) {
				return static_cast<Common>(x);
			}
			auto rem = (static_cast<Unsigned>(x) - static_cast<Unsigned>(min)) % range;
			if (x < min) {
				auto mod = (static_cast<Unsigned>(-1) % range + 1) % range;
				rem += (rem < mod) ? (range - mod) : -mod;
			}
			return static_cast<Common>(static_cast<Unsigned>(min) + rem);
		}
	}
}

#endif
