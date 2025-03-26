#ifndef DETAIL_XIEITE_HEADER_MATH_MEDIAN
#	define DETAIL_XIEITE_HEADER_MATH_MEDIAN
#
#	include <algorithm>
#	include <cstddef>
#	include <functional>
#	include <ranges>
#	include <type_traits>
#	include <vector>
#	include "../ctnr/iters.hpp"
#	include "../math/avg.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<std::ranges::forward_range R, typename T = std::common_type_t<std::ranges::range_value_t<R>, double>>
	requires(std::ranges::sized_range<R> && xieite::is_arith<std::ranges::range_value_t<R>>)
	[[nodiscard]] constexpr T median(R&& range) noexcept {
		std::vector<std::ranges::iterator_t<R>> its;
		const std::size_t size = std::ranges::size(range);
		its.reserve(size);
		for (auto iter : xieite::iters(range)) {
			its.push_back(iter);
		}
		std::ranges::sort(its, std::ranges::less());
		return (size % 2)
			? static_cast<T>(*its[size / 2])
			: static_cast<T>(xieite::avg(*its[size / 2 - 1], *its[size / 2]));
	}
}

#endif
