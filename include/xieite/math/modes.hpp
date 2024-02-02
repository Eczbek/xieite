#ifndef XIEITE_HEADER_MATH_MODES
#	define XIEITE_HEADER_MATH_MODES

#	include <algorithm>
#	include <array>
#	include <functional>
#	include <ranges>
#	include <type_traits>
#	include <utility>
#	include <vector>
#	include "../algorithms/modes.hpp"
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<std::ranges::range Range>
	requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr std::vector<std::ranges::range_value_t<Range>> modes(Range&& range) noexcept {
		auto result = std::vector<std::common_type_t<double, Numbers...>>(sizeof...(Numbers));
		std::ranges::transform(xieite::algorithms::modes(std::forward<Range>(range), std::ranges::greater()), result.begin(), [](const std::ranges::const_iterator_t<Range> iterator) -> std::ranges::range_const_reference_t<Range> {
			return *iterator;
		});
		return result;
	}

	template<xieite::concepts::Arithmetic... Numbers>
	[[nodiscard]] constexpr std::vector<std::common_type_t<double, Numbers...>> modes(const Numbers... values) noexcept {
		return xieite::math::modes(std::array<std::common_type_t<double, Numbers...>, sizeof...(Numbers)> {
			static_cast<std::common_type_t<double, Numbers...>>(values)...
		});
	}
}

#endif
