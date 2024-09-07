module;

#include <xieite/lift.hpp>

export module xieite:math.antimodes;

import std;
import :algorithms.modes;
import :concepts.Arithmetic;

export namespace xieite::math {
	template<std::ranges::forward_range Range>
	requires(std::ranges::sized_range<Range> && xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr std::vector<std::ranges::range_value_t<Range>> antimodes(Range&& range) noexcept {
		using Value = std::ranges::range_value_t<Range>;
		const auto iterators = xieite::algorithms::modes(range, std::ranges::less());
		std::vector<Value> result = std::vector<Value>(iterators.size());
		std::ranges::transform(iterators, result.begin(), XIEITE_LIFT_UNARY(*));
		return result;
	}

	template<xieite::concepts::Arithmetic... Arithmetics>
	[[nodiscard]] constexpr std::vector<std::common_type_t<Arithmetics...>> antimodes(const Arithmetics... values) noexcept {
		return xieite::math::antimodes(std::array<std::common_type_t<Arithmetics...>, sizeof...(Arithmetics)> {
			static_cast<std::common_type_t<Arithmetics...>>(values)...
		});
	}
}
