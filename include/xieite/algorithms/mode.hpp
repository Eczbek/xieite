#ifndef XIEITE_HEADER__MATH__MODE
#	define XIEITE_HEADER__MATH__MODE

#	include <algorithm>
#	include <array>
#	include <ranges>
#	include "../concepts/Arithmetic.hpp"
#	include "../math/Result.hpp"
#	include "../types/count.hpp"

namespace xieite::math {
	template<std::ranges::range Range>
	requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
	constexpr xieite::math::Result<std::ranges::range_value_t<Range>> mode(const Range& range) noexcept {
		return std::ranges::size(range) ? *std::ranges::max_element(range) : 0;
	}

	template<xieite::concepts::Arithmetic... Arithmetics>
	constexpr xieite::math::Result<Arithmetics...> mode(const Arithmetics... values) noexcept {
		return xieite::math::mode(std::array<xieite::math::Result<Arithmetics...>, xieite::types::count<Arithmetics...>> {
			static_cast<xieite::math::Result<Arithmetics...>>(values)...
		});
	}
}

#endif
