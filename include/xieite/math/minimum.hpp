#ifndef XIEITE_HEADER_MATH_MINIMUM
#	define XIEITE_HEADER_MATH_MINIMUM

#	include <algorithm>
#	include <array>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic... Arithmetics>
	requires(sizeof...(Arithmetics) > 0)
	[[nodiscard]] constexpr std::common_type_t<Arithmetics...> minimum(const Arithmetics... values) noexcept {
		return std::ranges::min(std::array<std::common_type_t<Arithmetics...>, sizeof...(Arithmetics)> {
			static_cast<std::common_type_t<Arithmetics...>>(values)...
		});
	}
}

#endif
