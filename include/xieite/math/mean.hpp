#ifndef XIEITE_HEADER_MATH_MEAN
#	define XIEITE_HEADER_MATH_MEAN

#	include <iterator>
#	include <ranges>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<std::ranges::range Range>
	requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr std::common_type_t<double, std::ranges::range_value_t<Range>> mean(Range&& range) noexcept {
		using Result = std::common_type_t<double, std::ranges::range_value_t<Range>>;
		const std::size_t rangeSize = std::ranges::size(range);
		Result result = 0;
		const auto end = std::ranges::end(range);
		for (auto iterator = std::ranges::begin(range); iterator != end; ++iterator) {
			result += static_cast<Result>(*iterator);
		}
		return result / std::ranges::size(range);
	}

	template<xieite::concepts::Arithmetic... Numbers>
	requires(sizeof...(Numbers) > 0)
	[[nodiscard]] constexpr std::common_type_t<double, Numbers...> mean(const Numbers... values) noexcept {
		return (... + (static_cast<std::common_type_t<double, Numbers...>>(values) / sizeof...(Numbers)));
	}
}

#endif
