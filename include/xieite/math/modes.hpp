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
	template<std::ranges::range Range_>
	requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range_>>)
	[[nodiscard]] constexpr std::vector<std::ranges::range_value_t<Range_>> modes(const Range_& range) noexcept {
		using Value = std::ranges::range_value_t<Range_>;
		const auto iterators = xieite::algorithms::modes(range, std::ranges::greater());
		std::vector<Value> result = std::vector<Value>(iterators.size());
		std::ranges::transform(iterators, result.begin(), [](const auto iterator) {
			return *iterator;
		});
		return result;
	}

	template<xieite::concepts::Arithmetic... Arithmetics_>
	requires(sizeof...(Arithmetics_) > 0)
	[[nodiscard]] constexpr std::vector<std::common_type_t<Arithmetics_...>> modes(const Arithmetics_... values) noexcept {
		return xieite::math::modes(std::array<std::common_type_t<Arithmetics_...>, sizeof...(Arithmetics_)> {
			static_cast<std::common_type_t<Arithmetics_...>>(values)...
		});
	}
}

#endif
