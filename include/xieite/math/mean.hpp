#ifndef DETAIL_XIEITE_HEADER_MATH_MEAN
#	define DETAIL_XIEITE_HEADER_MATH_MEAN
#
#	include <ranges>
#	include <type_traits>
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<std::ranges::forward_range Range, typename Result = std::common_type_t<std::ranges::range_value_t<Range>, double>>
	requires(std::ranges::sized_range<Range> && xieite::is_arith<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr Result mean(Range&& range) noexcept {
		Result result = 0;
		for (auto&& n : range) {
			result += static_cast<Result>(n);
		}
		return result / std::ranges::size(range);
	}
}

#endif
