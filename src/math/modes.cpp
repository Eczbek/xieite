module;

#include "../macros/lift.hpp"

export module xieite:math.modes;

import std;
import :algorithms.modes;
import :concepts.Arithmetic;
import :concepts.NoThrowOperableRange;

export namespace xieite::math {
	template<std::ranges::forward_range Range>
	requires(std::ranges::sized_range<Range> && xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr std::vector<std::ranges::range_value_t<Range>> modes(Range&& range)
	noexcept(xieite::concepts::NoThrowOperableRange<Range>) {
		using Value = std::ranges::range_value_t<Range>;
		const auto iterators = xieite::algorithms::modes(range, std::ranges::greater());
		std::vector<Value> result = std::vector<Value>(iterators.size());
		std::ranges::transform(iterators, result.begin(), XIEITE_LIFT_UNARY(*));
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
