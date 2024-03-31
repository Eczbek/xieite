#ifndef XIEITE_HEADER_MATH_MODES
#	define XIEITE_HEADER_MATH_MODES

#	include <algorithm>
#	include <array>
#	include <functional>
#	include <ranges>
#	include <type_traits>
#	include <vector>
#	include "../algorithms/modes.hpp"
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<std::ranges::range Range>
	requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr std::vector<std::ranges::range_value_t<Range>> modes(const Range& range) noexcept {
		using Value = std::ranges::range_value_t<Range>;
		const auto iterators = xieite::algorithms::modes(range, std::ranges::greater());
		std::vector<Value> result = std::vector<Value>(iterators.size());
		std::ranges::transform(iterators, result.begin(), [](const auto iterator) {
			return *iterator;
		});
		return result;
	}

	template<xieite::concepts::Arithmetic... Numbers>
	requires(sizeof...(Numbers) > 0)
	[[nodiscard]] constexpr std::vector<std::common_type_t<Numbers...>> modes(const Numbers... values) noexcept {
		return xieite::math::modes(std::array<std::common_type_t<Numbers...>, sizeof...(Numbers)> {
			static_cast<std::common_type_t<Numbers...>>(values)...
		});
	}
}

#endif
