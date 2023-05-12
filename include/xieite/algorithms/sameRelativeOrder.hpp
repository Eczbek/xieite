#pragma once

#include <concepts>
#include <functional>
#include <iterator>
#include <ranges>
#include <xieite/concepts/Function.hpp>

namespace xieite::algorithms {
	template<std::forward_iterator Iterator1, std::forward_iterator Iterator2, xieite::concepts::Function<bool(std::iter_value_t<Iterator1>, std::iter_value_t<Iterator2>)> Callback = std::ranges::equal_to>
	[[nodiscard]]
	constexpr bool sameRelativeOrder(const Iterator1 begin1, const std::sentinel_for<Iterator1> auto end1, const Iterator2 begin2, const std::sentinel_for<Iterator2> auto end2, const Callback& comparator = Callback()) {
		if (std::distance(begin1, end1) == std::distance(begin2, end2)) {
			for (Iterator1 i = begin1; i != end1; ++i) {
				Iterator1 copy1 = i;
				Iterator2 copy2 = begin2;
				while (copy2 != end2) {
					if (copy1 == end1) {
						copy1 = begin1;
					}
					if (!comparator(*copy1, *copy2)) {
						break;
					}
					++copy1;
					++copy2;
				}
				if (copy2 == end2) {
					return true;
				}
			}
		}
		return false;
	}
}
