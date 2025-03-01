#pragma once

#include <concepts>
#include <functional>
#include <ranges>
#include "../math/rvsn.hpp"
#include "../trait/isinvoc.hpp"
#include "../trait/isnoexinvoc.hpp"
#include "../trait/isnoexrange.hpp"

namespace x4 {
	template<std::ranges::forward_range R, x4::isinvoc<bool(std::ranges::range_common_reference_t<R>, std::ranges::range_common_reference_t<R>)> F = std::ranges::equal_to>
	requires(std::ranges::sized_range<R>)
	[[nodiscard]] constexpr bool palindrome(R&& range, F&& cmp = {})
	noexcept(x4::isnoexinvoc<F, bool(std::ranges::range_common_reference_t<R>, std::ranges::range_common_reference_t<R>)> && x4::isnoexrange<R>) {
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
		return x == x4::rvsn(x, radix);
	}
}
