#pragma once

#include <algorithm>
#include <iterator>
#include <ranges>
#include "../trait/isinvoc.hpp"
#include "../trait/isnoexinvoc.hpp"
#include "../trait/isnoexrange.hpp"

namespace x4 {
	template<std::ranges::bidirectional_range R, x4::isinvoc<bool(std::ranges::range_common_reference_t<R>)> F>
	requires(std::indirectly_swappable<std::ranges::iterator_t<R>>)
	constexpr void partrvs(R& range, F&& cond)
	noexcept(x4::isnoexinvoc<F, bool(std::ranges::range_common_reference_t<R>)> && x4::isnoexrange<R>) {
		auto first = std::ranges::begin(range);
		auto last = std::ranges::end(range);
		while (true) {
			first = std::ranges::find_if(first, last, cond);
			last = std::ranges::find_last_if(first, last, cond);
			if (first == last) {
				break;
			}
			std::ranges::iter_swap(first, last);
			++first;
			--last;
		}
	}
}
