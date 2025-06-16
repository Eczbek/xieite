#ifndef DETAIL_XIEITE_HEADER_MATH_TO_UNDERLYING
#	define DETAIL_XIEITE_HEADER_MATH_TO_UNDERLYING
#
#	include <concepts>
#	include <utility>
#	include "../trait/is_enum.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto to_underlying(xieite::is_enum auto x) noexcept {
		return std::to_underlying(x);
	}

	[[nodiscard]] constexpr auto to_underlying(std::integral auto x) noexcept {
		return x;
	}
}

#endif
