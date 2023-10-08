#ifndef XIEITE_HEADER__ALGORITHMS__ANY
#	define XIEITE_HEADER__ALGORITHMS__ANY

#	include <algorithm>
#	include <concepts>
#	include <ranges>
#	include "../concepts/NoThrowConvertibleTo.hpp"
#	include "../concepts/RangeOf.hpp"

namespace xieite::algorithms {
	template<xieite::concepts::RangeOf<bool> Range>
	[[nodiscard]] constexpr bool any(const Range& range)
	noexcept(noexcept(xieite::concepts::NoThrowConvertibleTo<std::ranges::range_value_t<Range>, bool>)) {
		return !std::ranges::none_of(range, [](const auto value) {
			return static_cast<bool>(value);
		});
	}

	template<std::convertible_to<bool>... Values>
	[[nodiscard]] constexpr bool any(const Values&... values)
	noexcept(noexcept((... && xieite::concepts::NoThrowConvertibleTo<Values, bool>))) {
		return (... || static_cast<bool>(values));
	}
}

#endif
