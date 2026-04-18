#ifndef DETAIL_XTE_HEADER_MATH_DIV
#	define DETAIL_XTE_HEADER_MATH_DIV
#
#	include "../trait/is_number.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto div(xte::is_number auto x, xte::is_number auto... ys) noexcept {
		using Common = std::common_type_t<decltype(x), decltype(ys)...>;
		return (static_cast<Common>(x) / ... / static_cast<Common>(ys));
	};
}

#endif
