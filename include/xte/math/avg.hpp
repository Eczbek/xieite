#ifndef DETAIL_XTE_HEADER_MATH_AVG
#	define DETAIL_XTE_HEADER_MATH_AVG
#
#	include "../math/div.hpp"
#	include "../math/rem.hpp"
#	include "../trait/is_int.hpp"
#	include "../trait/is_number.hpp"
#	include "../util/numbers.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto avg(xte::is_number auto first, xte::is_number auto... rest) noexcept {
		using common_type = std::common_type_t<decltype(first), decltype(rest)...>;
		static constexpr auto size = sizeof...(rest) + 1;
		auto result = (static_cast<common_type>(xte::div(first, size)) + ... + static_cast<common_type>(xte::div(rest, size)));
		if constexpr (xte::is_int<common_type>) {
			result += static_cast<common_type>(xte::div((static_cast<common_type>(xte::rem(first, size)) + ... + static_cast<common_type>(xte::rem(rest, size))), size));
		}
		return result;
	}
}

#endif
