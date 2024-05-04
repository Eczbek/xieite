#ifndef XIEITE_HEADER_MATH_MEDIAN
#	define XIEITE_HEADER_MATH_MEDIAN

#	include <algorithm>
#	include <array>
#	include <cstddef>
#	include <iterator>
#	include <ranges>
#	include <type_traits>
#	include <vector>
#	include "../concepts/arithmetic.hpp"
#	include "../math/mean.hpp"

namespace xieite::math {
	template<std::ranges::range Range_>
	requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range_>>)
	[[nodiscard]] constexpr std::common_type_t<double, std::ranges::range_value_t<Range_>> median(Range_&& range) noexcept {
		using Iterator = std::ranges::iterator_t<Range_>;
		std::vector<Iterator> iterators;
		iterators.reserve(std::ranges::size(range));
		const Iterator end = std::ranges::end(range);
		for (Iterator iterator = std::ranges::begin(range); iterator != end; ++iterator) {
			iterators.push_back(iterator);
		}
		std::ranges::sort(iterators, [comparator = std::ranges::less()](const Iterator left, const Iterator right) {
			return comparator(left, right);
		});
		const std::size_t rangeSize = std::ranges::size(range);
		return (rangeSize % 2) ? *iterators[(rangeSize - 1) / 2] : xieite::math::mean(*iterators[rangeSize / 2 - 1], *iterators[rangeSize / 2]);
	}

	template<xieite::concepts::Arithmetic... Arithmetics_>
	requires(sizeof...(Arithmetics_) > 0)
	[[nodiscard]] constexpr std::common_type_t<double, Arithmetics_...> median(const Arithmetics_... values) noexcept {
		using Result = std::common_type_t<double, Arithmetics_...>;
		return xieite::math::median(std::array<Result, sizeof...(Arithmetics_)> {
			static_cast<Result>(values)...
		});
	}
}

#endif
