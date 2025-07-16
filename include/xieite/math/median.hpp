#ifndef DETAIL_XIEITE_HEADER_MATH_MEDIAN
#	define DETAIL_XIEITE_HEADER_MATH_MEDIAN
#
#	include <algorithm>
#	include <cstddef>
#	include <functional>
#	include <ranges>
#	include <type_traits>
#	include <vector>
#	include "../data/iters.hpp"
#	include "../math/avg.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<std::ranges::forward_range Range, typename Result = std::common_type_t<std::ranges::range_value_t<Range>, double>>
	requires(std::ranges::sized_range<Range> && xieite::is_arith<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr Result median(Range&& range) noexcept {
		std::vector<std::ranges::iterator_t<Range>> its;
		const std::size_t size = std::ranges::size(range);
		its.reserve(size);
		for (auto iter : xieite::iters(range)) {
			its.push_back(iter);
		}
		std::ranges::sort(its, std::less());
		return (size % 2)
			? static_cast<Result>(*its[size / 2])
			: static_cast<Result>(xieite::avg(*its[size / 2 - 1], *its[size / 2]));
	}
}

#endif
