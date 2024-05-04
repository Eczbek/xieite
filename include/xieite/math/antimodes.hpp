#ifndef XIEITE_HEADER_MATH_ANTIMODES
#	define XIEITE_HEADER_MATH_ANTIMODES

#	include <algorithm>
#	include <array>
#	include <functional>
#	include <ranges>
#	include <type_traits>
#	include <vector>
#	include "../algorithms/modes.hpp"
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<std::ranges::range Range_>
	requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range_>>)
	[[nodiscard]] constexpr std::vector<std::ranges::range_value_t<Range_>> antimodes(const Range_& range) noexcept {
		using Value = std::ranges::range_value_t<Range_>;
		const auto iterators = xieite::algorithms::modes(range, std::ranges::less());
		std::vector<Value> result = std::vector<Value>(iterators.size());
		std::ranges::transform(iterators, result.begin(), [](const auto iterator) {
			return *iterator;
		});
		return result;
	}

	template<xieite::concepts::Arithmetic... Arithmetics_>
	[[nodiscard]] constexpr std::vector<std::common_type_t<Arithmetics_...>> antimodes(const Arithmetics_... values) noexcept {
		return xieite::math::antimodes(std::array<std::common_type_t<Arithmetics_...>, sizeof...(Arithmetics_)> {
			static_cast<std::common_type_t<Arithmetics_...>>(values)...
		});
	}
}

#endif
