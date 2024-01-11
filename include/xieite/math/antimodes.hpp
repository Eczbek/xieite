#ifndef XIEITE_HEADER_MATH_ANTIMODES
#	define XIEITE_HEADER_MATH_ANTIMODES

#	include <functional>
#	include <ranges>
#	include <vector>
#	include "../algorithms/modes.hpp"
#	include "../concepts/arithmetic.hpp"
#	include "../types/common_floating_point.hpp"
#	include "../ranges/convert.hpp"
#	include "../ranges/make_array.hpp"

namespace xieite::math {
	template<std::ranges::range Range>
	requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr std::vector<std::ranges::range_value_t<Range>> antimodes(const Range& range) noexcept {
		auto result = std::vector<xieite::types::CommonFloatingPoint<Numbers...>>(sizeof...(Numbers));
		xieite::ranges::convert(xieite::algorithms::modes(range, std::ranges::less()), result, [](const auto iterator) {
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
