#ifndef XIEITE_HEADER_CONCEPTS_RANGE_OF
#	define XIEITE_HEADER_CONCEPTS_RANGE_OF

#	include <concepts>
#	include <ranges>

namespace xieite::concepts {
	template<typename Range_, typename Value_>
	concept RangeOf = std::ranges::range<Range_> && (std::same_as<std::ranges::range_reference_t<Range_>, Value_> || std::convertible_to<std::ranges::range_reference_t<Range_>, Value_>);
}

#endif
