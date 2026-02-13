#ifndef DETAIL_XTE_HEADER_MATH_MAX
#	define DETAIL_XTE_HEADER_MATH_MAX
#
#	include "../trait/is_number.hpp"
#	include <type_traits>

namespace xte {
	inline constexpr auto max = [][[nodiscard]](xte::is_number auto x, xte::is_number auto... ys) static noexcept {
		using Common = std::common_type_t<decltype(x), decltype(ys)...>;
		auto max = static_cast<Common>(x);
		return (..., (max = (max < static_cast<Common>(ys)) ? static_cast<Common>(ys) : max));
	};
}

#endif
