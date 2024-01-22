#ifndef XIEITE_HEADER_MATH_ANTIMODES
#	define XIEITE_HEADER_MATH_ANTIMODES

#	include <algorithm>
#	include <functional>
#	include <ranges>
#	include <vector>
#	include <utility>
#	include "../algorithms/modes.hpp"
#	include "../concepts/arithmetic.hpp"
#	include "../containers/make_array.hpp"
#	include "../types/common_floating_point.hpp"

namespace xieite::math {
	template<std::ranges::range Range>
	requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr std::vector<std::ranges::range_value_t<Range>> antimodes(Range&& range) noexcept {
		auto result = std::vector<xieite::types::CommonFloatingPoint<Numbers...>>(sizeof...(Numbers));
		std::ranges::transform(xieite::algorithms::modes(std::forward<Range>(range), std::ranges::less()), result.begin(), [](const std::ranges::const_iterator_t<Range> iterator) -> std::ranges::range_const_reference_t<Range> {
			return *iterator;
		});
		return result;
	}

	template<xieite::concepts::Arithmetic... Numbers>
	[[nodiscard]] constexpr std::vector<xieite::types::CommonFloatingPoint<Numbers...>> antimodes(const Numbers... values) noexcept {
		return xieite::math::antimodes(xieite::ranges::makeArray<xieite::types::CommonFloatingPoint<Numbers...>>(values...));
	}
}

#endif
