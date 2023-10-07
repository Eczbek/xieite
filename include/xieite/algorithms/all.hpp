#ifndef XIEITE_HEADER__ALGORITHMS__ALL
#	define XIEITE_HEADER__ALGORITHMS__ALL

#	include <algorithm>
#	include <concepts>
#	include <ranges>
#	include "../concepts/NoThrowConvertibleTo.hpp"
#	include "../concepts/RangeOf.hpp"

namespace xieite::algorithms {
	template<xieite::concepts::RangeOf<bool> Range>
	[[nodiscard]] constexpr bool all(const Range& range)
	noexcept(noexcept(xieite::concepts::NoThrowConvertibleTo<std::ranges::range_value_t<Range>, bool>)) {
		return std::ranges::all_of(range, [](const std::ranges::range_const_reference_t<const Range&> value) -> bool {
			return static_cast<bool>(value);
		});
	}

	template<std::convertible_to<bool>... Values>
	[[nodiscard]] constexpr bool all(const Values&... values)
	noexcept(noexcept((... && xieite::concepts::NoThrowConvertibleTo<Values, bool>))) {
		return (... && static_cast<bool>(values));
	}
}

#endif
