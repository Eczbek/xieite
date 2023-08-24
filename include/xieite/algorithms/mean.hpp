#ifndef XIEITE_HEADER__MATH__MEAN
#	define XIEITE_HEADER__MATH__MEAN

#	include <iterator>
#	include <ranges>
#	include "../concepts/Arithmetic.hpp"
#	include "../math/Result.hpp"
#	include "../types/count.hpp"

namespace xieite::math {
	template<std::ranges::range Range>
	requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
	constexpr xieite::math::Result<std::ranges::range_value_t<Range>> mean(const Range& range) noexcept {
		const std::size_t rangeSize = std::ranges::size(range);
		std::ranges::range_value_t<Range> result = 0;
		const std::ranges::const_iterator_t<const Range&> rangeEnd = std::ranges::end(range);
		for (std::ranges::iterator_t<const Range&> iterator = std::ranges::begin(range); iterator != rangeEnd; iterator = std::ranges::next(iterator)) {
			result += static_cast<xieite::math::Result<std::ranges::range_value_t<Range>>>(*iterator) / rangeSize;
		}
		return result;
	}

	template<xieite::concepts::Arithmetic... Arithmetics>
	constexpr xieite::math::Result<Arithmetics...> mean(const Arithmetics... values) noexcept {
		return (... + (static_cast<xieite::math::Result<Arithmetics...>>(values) / xieite::types::count<Arithmetics...>));
	}
}

#endif
