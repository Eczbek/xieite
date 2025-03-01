#pragma once

#include <algorithm>
#include <ranges>
#include "../trait/isfwdirange.hpp"
#include "../trait/isnoexrange.hpp"

namespace x4 {
	template<x4::isfwdirange R0, x4::isfwdirange R1>
	[[nodiscard]] constexpr auto vbef(R0&& range, R1&& subrange)
	noexcept(x4::isnoexrange<R0> && x4::isnoexrange<R1>) {
		return std::ranges::subrange(std::ranges::begin(range), std::ranges::search(range, subrange).begin());
	}

	template<std::ranges::input_range R>
	[[nodiscard]] constexpr auto vbef(R&& range, std::ranges::range_common_reference_t<R> x)
	noexcept(x4::isnoexrange<R>) {
		return std::ranges::subrange(std::ranges::begin(range), std::ranges::find(range, x));
	}
}
