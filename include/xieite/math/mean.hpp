#ifndef DETAIL_XIEITE_HEADER_MATH_MEAN
#	define DETAIL_XIEITE_HEADER_MATH_MEAN
#
#	include <ranges>
#	include <type_traits>
#	include "../trait/is_arith.hpp"
#	include "../trait/is_fwd_sized_range.hpp"

namespace xieite {
	template<xieite::is_fwd_sized_range Range, typename Result = std::common_type_t<std::ranges::range_value_t<Range>, double>>
	requires(xieite::is_arith<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr Result mean(Range&& range) noexcept {
		const Result size = static_cast<Result>(std::ranges::size(range));
		Result result = 0;
		Result offset = 0;
		for (auto n : range) {
			result += static_cast<Result>(n) / size;
			if constexpr (std::integral<Result>) {
				offset += static_cast<Result>(n) % size;
			}
		}
		return result + offset / size;
	}
}

#endif
