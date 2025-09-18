#ifndef DETAIL_XIEITE_HEADER_DATA_PALINDROME
#	define DETAIL_XIEITE_HEADER_DATA_PALINDROME
#
#	include <concepts>
#	include <functional>
#	include <ranges>
#	include "../math/reverse_number.hpp"
#	include "../trait/is_lref_invoc.hpp"
#	include "../trait/is_noex_lref_invoc.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::ranges::forward_range Range, xieite::is_lref_invoc<bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)> Pred = std::equal_to<>>
	requires(std::ranges::sized_range<Range>)
	[[nodiscard]] constexpr bool palindrome(Range&& range, Pred&& pred = {})
	noexcept(xieite::is_noex_range<Range> && xieite::is_noex_lref_invoc<Pred, bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)>) {
		auto iter0 = std::ranges::begin(range);
		auto iter1 = std::ranges::end(range);
		for (std::size_t i = std::ranges::size(range) / 2; i--;) {
			--iter1;
			if (!std::invoke_r<bool>(pred, *iter0, *iter1)) {
				return false;
			}
			++iter0;
		}
		return true;
	}

	template<std::integral Int>
	[[nodiscard]] constexpr bool palindrome(Int x, Int radix = 10) noexcept {
		return x == xieite::reverse_number(x, radix);
	}
}

#endif
