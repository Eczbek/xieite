#ifndef XIEITE_HEADER_CONCEPTS_RANGEOF
#	define XIEITE_HEADER_CONCEPTS_RANGEOF

#	include <concepts>
#	include <ranges>

namespace xieite::concepts {
	template<typename Range, typename Value>
	concept RangeOf = std::ranges::range<Range> && std::same_as<std::ranges::range_value_t<Range>, Value>;
}

#endif
