#ifndef DETAIL_XTE_HEADER_MATH_REM
#	define DETAIL_XTE_HEADER_MATH_REM
#
#	include "../trait/is_number.hpp"
#	include "../trait/is_float.hpp"
#	include <cmath>
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto rem(xte::is_number auto x, xte::is_number auto... ys) noexcept {
		using Common = std::common_type_t<decltype(x), decltype(ys)...>;
		if constexpr (xte::is_float<Common>) {
			auto result = static_cast<Common>(x);
			return (..., (result = std::fmod(result, static_cast<Common>(ys))));
		} else {
			return (static_cast<Common>(x) % ... % static_cast<Common>(ys));
		}
	};
}

#endif
