#ifndef DETAIL_XIEITE_HEADER_CTNR_ROTATED
#	define DETAIL_XIEITE_HEADER_CTNR_ROTATED
#
#	include <functional>
#	include <ranges>
#	include "../ctnr/iters.hpp"
#	include "../trait/is_invoc.hpp"
#	include "../trait/is_noex_invoc.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::ranges::input_range R0, std::ranges::input_range R1, xieite::is_invoc<bool(std::ranges::range_common_reference_t<R0>, std::ranges::range_common_reference_t<R1>)> F = std::ranges::equal_to>
	[[nodiscard]] constexpr bool rotated(R0&& range0, R1&& range1, F&& cmp = {})
	noexcept(xieite::is_noex_invoc<F, bool(std::ranges::range_common_reference_t<R0>, std::ranges::range_common_reference_t<R1>)> && xieite::is_noex_range<R0> && xieite::is_noex_range<R1>) {
		if (std::ranges::size(range0) == std::ranges::size(range1)) {
			for (auto iter : xieite::iters(range0)) {
				auto copy0 = iter;
				auto copy1 = std::ranges::begin(range1);
				while (copy1 != std::ranges::end(range1)) {
					if (copy0 == std::ranges::end(range0)) {
						copy0 = std::ranges::begin(range0);
					}
					if (!std::invoke_r<bool>(cmp, *copy0, *copy1)) {
						break;
					}
					++copy0;
					++copy1;
				}
				if (copy1 == std::ranges::end(range1)) {
					return true;
				}
			}
		}
		return false;
	}
}

#endif
