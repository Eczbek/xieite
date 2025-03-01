#pragma once

#include <concepts>
#include <ranges>
#include <vector>
#include "../math/betw.hpp"
#include "../math/minmax.hpp"
#include "../math/intv.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T, std::ranges::input_range R>
	requires(std::convertible_to<std::ranges::range_value_t<R>, x4::intv<T>>)
	[[nodiscard]] constexpr std::vector<x4::intv<T>> mrgintv(R&& intervals) noexcept {
		std::vector<x4::intv<T>> result;
		for (x4::intv<T> interval0 : intervals) {
			const x4::intv<T> ordered = x4::minmax(interval0.start, interval0.end);
			const auto [lower, upper] = ordered;
			bool overlaps = false;
			for (x4::intv<T>& interval1 : result) {
				const auto [start, end] = interval1;
				if (x4::betw(lower, start, end) || x4::betw(upper, start, end)) {
					overlaps = true;
					interval1 = x4::minmax(lower, upper, start, end);
				}
			}
			if (!overlaps) {
				result.push_back(ordered);
			}
		}
		return result;
	}
}
