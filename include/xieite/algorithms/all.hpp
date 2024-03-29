#ifndef XIEITE_HEADER_ALGORITHMS_ALL
#	define XIEITE_HEADER_ALGORITHMS_ALL

#	include <algorithm>
#	include <concepts>
#	include <ranges>
#	include "../concepts/no_throw_convertible_to.hpp"
#	include "../concepts/range_of.hpp"
#	include "../macros/forward.hpp"

namespace xieite::algorithms {
	template<std::convertible_to<bool>... Values>
	[[nodiscard]] constexpr bool all(Values&&... values)
	noexcept((... && xieite::concepts::NoThrowConvertibleTo<Values, bool>)) {
		return (... && static_cast<bool>(XIEITE_FORWARD(values)));
	}

	template<xieite::concepts::RangeOf<bool> Range>
	[[nodiscard]] constexpr bool all(Range&& range)
	noexcept(xieite::concepts::NoThrowConvertibleTo<std::ranges::range_reference_t<Range>, bool>) {
		return std::ranges::all_of(XIEITE_FORWARD(range), [](const std::ranges::range_const_reference_t<Range> value) -> bool {
			return static_cast<bool>(value);
		});
	}
}

#endif
