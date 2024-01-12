#ifndef XIEITE_HEADER_MATH_MAXIMUM
#	define XIEITE_HEADER_MATH_MAXIMUM

#	include <algorithm>
#	include <array>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic... Numbers>
	requires(sizeof...(Numbers) > 0)
	[[nodiscard]] constexpr std::common_type_t<Numbers...> maximum(const Numbers... values) noexcept {
		return std::ranges::max(std::array<std::common_type_t<Numbers...>, sizeof...(Numbers)> {
			static_cast<std::common_type_t<Numbers...>>(values)...
		});
	}
}

#endif
