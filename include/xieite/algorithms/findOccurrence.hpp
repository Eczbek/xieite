#pragma once

#include <concepts>
#include <cstddef>
#include <functional>
#include <iterator>
#include <ranges>
#include <xieite/concepts/Function.hpp>

namespace xieite::algorithms {
	template<std::forward_iterator Iterator, xieite::concepts::Function<bool(std::iter_value_t<Iterator>, std::iter_value_t<Iterator>)> Callback = std::ranges::equal_to>
	[[nodiscard]]
	constexpr Iterator findOccurrence(Iterator begin, const std::sentinel_for<Iterator> auto end, const std::convertible_to<std::iter_value_t<Iterator>> auto& value, std::size_t count, const Callback& comparator = Callback()) {
		for (; begin != end; ++begin) {
			if (comparator(*begin, value) && !--count) {
				return begin;
			}
		}
		return end;
	}
}
