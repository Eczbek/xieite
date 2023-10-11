#ifndef XIEITE_HEADER_ALGORITHMS_MEAN
#	define XIEITE_HEADER_ALGORITHMS_MEAN

#	include <cstddef>
#	include <iterator>
#	include <ranges>
#	include "../concepts/numeric.hpp"
#	include "../math/result.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range>
	requires(xieite::concepts::Numeric<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr xieite::math::Result<std::ranges::range_value_t<Range>> mean(const Range& range) noexcept {
		xieite::math::Result<std::ranges::range_value_t<Range>> result = 0;
		const auto end = std::ranges::end(range);
		for (auto iterator = std::ranges::begin(range); iterator != end; iterator = std::ranges::next(iterator)) {
			result += static_cast<xieite::math::Result<std::ranges::range_value_t<Range>>>(*iterator);
		}
		return result / std::ranges::size(range);
	}
}

#endif
