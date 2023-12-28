#ifndef XIEITE_HEADER_MATH_MEAN
#	define XIEITE_HEADER_MATH_MEAN

#	include <iterator>
#	include <ranges>
#	include "../concepts/arithmetic.hpp"
#	include "../math/result.hpp"

namespace xieite::math {
	template<std::ranges::range Range>
	requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr xieite::math::Result<std::ranges::range_value_t<Range>> mean(const Range& range) noexcept {
		xieite::math::Result<std::ranges::range_value_t<Range>> result = 0;
		const auto end = std::ranges::end(range);
		for (auto iterator = std::ranges::begin(range); iterator != end; iterator = std::ranges::next(iterator)) {
			result += static_cast<xieite::math::Result<std::ranges::range_value_t<Range>>>(*iterator);
		}
		return result / std::ranges::size(range);
	}

	template<xieite::concepts::Arithmetic... Numbers>
	[[nodiscard]] constexpr xieite::math::Result<Numbers...> mean(const Numbers... values) noexcept {
		if constexpr (sizeof...(Numbers)) {
			return (... + (static_cast<xieite::math::Result<Numbers...>>(values) / sizeof...(Numbers)));
		}
		return 0;
	}
}

#endif
