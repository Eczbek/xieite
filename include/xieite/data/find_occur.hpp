#ifndef DETAIL_XIEITE_HEADER_DATA_FIND_OCCUR
#	define DETAIL_XIEITE_HEADER_DATA_FIND_OCCUR
#
#	include <cstddef>
#	include <functional>
#	include <ranges>
#	include "../data/find_occur_if.hpp"
#	include "../pp/arrow.hpp"
#	include "../trait/is_invoc.hpp"
#	include "../trait/is_noex_invoc.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::ranges::forward_range Range, xieite::is_invoc<bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)> Fn = std::ranges::equal_to>
	[[nodiscard]] constexpr std::ranges::iterator_t<Range> find_occur(Range& range, std::size_t idx, std::ranges::range_reference_t<Range> value, Fn&& cmp = {})
	noexcept(xieite::is_noex_invoc<Fn, bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)> && xieite::is_noex_range<Range>) {
		return xieite::find_occur_if(range, idx, [&](auto& other) XIEITE_ARROW(std::invoke_r<bool>(cmp, value, other)));
	}
}

#endif
