#pragma once

#include <cstddef>
#include <functional>
#include <ranges>
#include <vector>
#include "../trait/isarith.hpp"
#include "../trait/isinvoc.hpp"
#include "../trait/isnoexinvoc.hpp"
#include "../trait/isnoexrange.hpp"

namespace x4 {
	template<std::ranges::forward_range R, x4::isinvoc<bool(std::ranges::range_common_reference_t<R>, std::ranges::range_common_reference_t<R>)> F = std::ranges::greater>
	requires(std::ranges::sized_range<R> && x4::isarith<std::ranges::range_value_t<R>>)
	[[nodiscard]] constexpr std::vector<std::ranges::iterator_t<R>> modes(R& range, F&& cmp = {})
	noexcept(x4::isnoexinvoc<F, bool(std::ranges::range_common_reference_t<R>, std::ranges::range_common_reference_t<R>)> && x4::isnoexrange<R>) {
		std::vector<std::ranges::iterator_t<R>> its;
		const std::size_t size = std::ranges::size(range);
		if (size == 1) {
			its.push_back(std::ranges::begin(range));
		}
		if (size <= 1) {
			return its;
		}
		auto prev = std::ranges::begin(range);
		auto curr = std::ranges::next(prev);
		for (std::size_t i = 1; i < (size - 1); ++i) {
			if (std::invoke(cmp, *curr, *prev)) {
				const auto next = std::ranges::next(curr);
				if (std::invoke(cmp, *curr, *next)) {
					its.push_back(curr);
				} else if (i == (size - 2)) {
					its.push_back(next);
				}
			} else if (i == 1) {
				its.push_back(prev);
			}
			prev = curr++;
		}
		if (std::ranges::size(range) && !its.size()) {
			its.push_back(std::ranges::begin(range));
		}
		return its;
	}
}
