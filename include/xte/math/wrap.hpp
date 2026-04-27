#ifndef DETAIL_XTE_HEADER_MATH_WRAP
#	define DETAIL_XTE_HEADER_MATH_WRAP
#
#	include "../math/minmax.hpp"
#	include "../math/mod.hpp"
#	include "../trait/is_number.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto wrap(xte::is_number auto x, xte::is_number auto limit0, xte::is_number auto limit1) noexcept {
		using common_type = std::common_type_t<decltype(x), decltype(limit0), decltype(limit1)>;
		auto [min, max] = xte::minmax(static_cast<common_type>(limit0), static_cast<common_type>(limit1));
		if constexpr (xte::is_float<common_type>) {
			return xte::mod(static_cast<common_type>(x) - min, max - min + 1) + min;
		} else {
			using unsigned_type = std::make_unsigned_t<common_type>;
			auto range = static_cast<unsigned_type>(max) - static_cast<unsigned_type>(min) + 1;
			if (!range) {
				return static_cast<common_type>(x);
			}
			auto rem = (static_cast<unsigned_type>(x) - static_cast<unsigned_type>(min)) % range;
			if (x < min) {
				auto mod = (static_cast<unsigned_type>(-1) % range + 1) % range;
				rem += (rem < mod) ? (range - mod) : -mod;
			}
			return static_cast<common_type>(static_cast<unsigned_type>(min) + rem);
		}
	}
}

#endif
