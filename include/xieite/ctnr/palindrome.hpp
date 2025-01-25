#pragma once

#include <concepts>
#include <functional>
#include <ranges>
#include "../math/reverse_num.hpp"
#include "../trait/is_invoc.hpp"
#include "../trait/is_noex_invoc.hpp"
#include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::ranges::forward_range R, xieite::is_invoc<bool(std::ranges::range_common_reference_t<R>, std::ranges::range_common_reference_t<R>)> F = std::ranges::equal_to>
	requires(std::ranges::sized_range<R>)
	[[nodiscard]] constexpr bool palindrome(R&& range, F&& cmp = {})
	noexcept(xieite::is_noex_invoc<F, bool(std::ranges::range_common_reference_t<R>, std::ranges::range_common_reference_t<R>)> && xieite::is_noex_range<R>) {
		auto iter0 = std::ranges::begin(range);
		auto iter1 = std::ranges::end(range);
		for (std::size_t i = std::ranges::size(range) / 2; i--;) {
			--iter1;
			if (!std::invoke_r<bool>(cmp, *iter0, *iter1)) {
				return false;
			}
			++iter0;
		}
		return true;
	}

	template<std::integral T>
	[[nodiscard]] constexpr bool palindrome(T x, T radix = 10) noexcept {
		return x == xieite::reverse_num(x, radix);
	}
}
