#ifndef DETAIL_XIEITE_HEADER_MATH_AVG
#	define DETAIL_XIEITE_HEADER_MATH_AVG
#
#	include <concepts>
#	include <type_traits>
#	include "../trait/is_arith.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto avg(xieite::is_arith auto first, xieite::is_arith auto... rest) noexcept {
		using Common = std::common_type_t<decltype(first), decltype(rest)...>;
		static constexpr Common size = static_cast<Common>(sizeof...(rest) + 1);
		Common result = static_cast<Common>(first) / size + (... + (static_cast<Common>(rest) / size));
		if constexpr (std::integral<Common>) {
			result = static_cast<Common>(result + (static_cast<Common>(first) % size + (... + (static_cast<Common>(rest) % size))) / size);
		}
		return result;
	}
}

#endif
