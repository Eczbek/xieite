#ifndef XIEITE_HEADER__ALGORITHMS__ANY
#	define XIEITE_HEADER__ALGORITHMS__ANY

#	include <algorithm>
#	include <concepts>
#	include <ranges>
#	include "../concepts/NoThrowConvertibleToAllOf.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range>
	requires(std::convertible_to<bool, std::ranges::range_value_t<Range>>)
	constexpr bool any(const Range& range)
	noexcept(noexcept(xieite::concepts::NoThrowConvertibleTo<bool, std::ranges::range_value_t<Range>)) {
		return !std::ranges::none_of(range, [](const std::ranges::range_const_reference_t<const Range&> value) -> bool {
			return static_cast<bool>(value);
		});
	}

	template<std::convertible_to<bool>... Values>
	constexpr bool any(const Values&... values)
	noexcept(noexcept(xieite::concepts::NoThrowConvertibleToAllOf<bool, Values...>)) {
		return (... || static_cast<bool>(values));
	}
}

#endif
