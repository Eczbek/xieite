#pragma once

#include <cstddef>
#include <functional>
#include <ranges>
#include "../ctnr/find_occur_if.hpp"
#include "../pp/arrow.hpp"
#include "../trait/is_invoc.hpp"
#include "../trait/is_noex_invoc.hpp"
#include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::ranges::forward_range R, xieite::is_invoc<bool(std::ranges::range_common_reference_t<R>, std::ranges::range_common_reference_t<R>)> F = std::ranges::equal_to>
	[[nodiscard]] constexpr std::ranges::iterator_t<R> find_occur(R& range, std::size_t n, std::ranges::range_reference_t<R> value, F&& cmp = {})
	noexcept(xieite::is_noex_invoc<F, bool(std::ranges::range_common_reference_t<R>, std::ranges::range_common_reference_t<R>)> && xieite::is_noex_range<R>) {
		return xieite::find_occur_if(range, n, [&](auto& other) XIEITE_ARROW(std::invoke_r<bool>(cmp, value, other)));
	}
}
