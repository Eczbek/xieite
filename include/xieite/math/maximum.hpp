#ifndef XIEITE_HEADER_MATH_MAXIMUM
#	define XIEITE_HEADER_MATH_MAXIMUM

#	include <algorithm>
#	include <array>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic... Arithmetics_>
	requires(sizeof...(Arithmetics_) > 0)
	[[nodiscard]] constexpr std::common_type_t<Arithmetics_...> maximum(const Arithmetics_... values) noexcept {
		return std::ranges::max(std::array<std::common_type_t<Arithmetics_...>, sizeof...(Arithmetics_)> {
			static_cast<std::common_type_t<Arithmetics_...>>(values)...
		});
	}
}

#endif
