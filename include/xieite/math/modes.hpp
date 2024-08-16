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
	template<std::ranges::input_range Range>
	requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr std::vector<std::ranges::range_value_t<Range>> modes(Range&& range) noexcept {
		using Value = std::ranges::range_value_t<Range>;
		const auto iterators = xieite::algorithms::modes(range, std::ranges::greater());
		std::vector<Value> result = std::vector<Value>(iterators.size());
		std::ranges::transform(iterators, result.begin(), [](const std::ranges::const_iterator_t<Range> iterator) -> std::ranges::range_value_t<Range> {
			return *iterator;
		});
		return result;
	}

	template<xieite::concepts::Arithmetic... Arithmetics>
	requires(sizeof...(Arithmetics) > 0)
	[[nodiscard]] constexpr std::vector<std::common_type_t<Arithmetics...>> modes(const Arithmetics... values) noexcept {
		return xieite::math::modes(std::array<std::common_type_t<Arithmetics...>, sizeof...(Arithmetics)> {
			static_cast<std::common_type_t<Arithmetics...>>(values)...
		});
	}
}

#endif
