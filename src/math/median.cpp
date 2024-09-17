export module xieite:math.median;

import std;
import :concepts.Arithmetic;
import :math.mean;

export namespace xieite::math {
	template<std::ranges::input_range Range>
	requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr std::common_type_t<double, std::ranges::range_value_t<Range>> median(Range&& range) noexcept {
		using Iterator = std::ranges::iterator_t<Range>;
		std::vector<Iterator> iterators;
		iterators.reserve(std::ranges::size(range));
		const Iterator end = std::ranges::end(range);
		for (Iterator iterator = std::ranges::begin(range); iterator != end; ++iterator) {
			iterators.push_back(iterator);
		}
		std::ranges::sort(iterators, std::ranges::less());
		const std::size_t rangeSize = std::ranges::size(range);
		return (rangeSize % 2) ? *iterators[(rangeSize - 1) / 2] : xieite::math::mean(*iterators[rangeSize / 2 - 1], *iterators[rangeSize / 2]);
	}

	template<xieite::concepts::Arithmetic... Arithmetics>
	requires(!!sizeof...(Arithmetics))
	[[nodiscard]] constexpr std::common_type_t<double, Arithmetics...> median(const Arithmetics... values) noexcept {
		using Result = std::common_type_t<double, Arithmetics...>;
		return xieite::math::median(std::array<Result, sizeof...(Arithmetics)> {
			static_cast<Result>(values)...
		});
	}
}
