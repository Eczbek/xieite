#ifndef DETAIL_XTE_HEADER_MATH_MIN
#	define DETAIL_XTE_HEADER_MATH_MIN
#
#	include "../trait/is_number.hpp"
#	include <type_traits>

namespace xte {
	inline constexpr auto min = [][[nodiscard]](xte::is_number auto x, xte::is_number auto... ys) static noexcept {
		using Common = std::common_type_t<decltype(x), decltype(ys)...>;
		auto min = static_cast<Common>(x);
		return (..., (min = (static_cast<Common>(ys) < min) ? static_cast<Common>(ys) : min));
	};
}

#endif
