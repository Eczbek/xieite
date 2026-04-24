#ifndef DETAIL_XTE_HEADER_MATH_AVG
#	define DETAIL_XTE_HEADER_MATH_AVG
#
#	include "../trait/is_int.hpp"
#	include "../trait/is_number.hpp"
#	include "../util/numbers.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto avg(xte::is_number auto x, xte::is_number auto... ys) noexcept {
		using common_type = std::common_type_t<xte::uz, decltype(x), decltype(ys)...>;
		static constexpr auto size = static_cast<common_type>(sizeof...(ys) + 1);
		auto result = ((static_cast<common_type>(x) / size) + ... + (static_cast<common_type>(ys) / size));
		if constexpr (xte::is_int<common_type>) {
			result = static_cast<common_type>(result + ((static_cast<common_type>(x) % size) + ... + (static_cast<common_type>(ys) % size)) / size);
		}
		return static_cast<std::common_type_t<decltype(x), decltype(ys)...>>(result);
	}
}

#endif
