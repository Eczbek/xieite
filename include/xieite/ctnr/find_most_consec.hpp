#pragma once

#include <functional>
#include <ranges>
#include "../ctnr/find_most_consec_if.hpp"
#include "../pp/fn.hpp"
#include "../trait/is_invoc.hpp"
#include "../trait/is_noex_invoc.hpp"
#include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::ranges::forward_range R, xieite::is_invoc<bool(std::ranges::range_common_reference_t<R>, std::ranges::range_common_reference_t<R>)> F = std::ranges::equal_to>
	requires(std::ranges::sized_range<R>)
	[[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<R>> find_most_consec(R& range, std::ranges::range_common_reference_t<R> value, F&& cmp = {})
	noexcept(xieite::is_noex_invoc<F, bool(std::ranges::range_common_reference_t<R>, std::ranges::range_common_reference_t<R>)> && xieite::is_noex_range<R>) {
		return xieite::find_most_consec_if(range, XIEITE_FN_LOCAL(std::invoke_r<bool>(cmp, value, $0)));
	}
}
