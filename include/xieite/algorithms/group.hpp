#pragma once

#include <concepts>
#include <cstddef>
#include <iterator>
#include <type_traits>
#include <unordered_map>
#include <vector>

namespace xieite::algorithms {
	template<std::forward_iterator Iterator, std::invocable<std::iter_value_t<Iterator>> Callback>
	[[nodiscard]]
	std::unordered_map<std::invoke_result_t<Callback(std::iter_value_t<Iterator>)>, std::vector<std::iter_value_t<Iterator>>> group(const Iterator begin, const std::sentinel_for<Iterator> auto end, const Callback& callback) {
		return xieite::algorithms::group(begin, end, [&callback](std::iter_reference_t value, std::size_t) -> std::invoke_result_t<Callback(std::iter_value_t<Iterator>)> {
			return callback(value);
		});
	}

	template<std::forward_iterator Iterator, std::invocable<std::iter_value_t<Iterator>, std::size_t> Callback>
	[[nodiscard]]
	std::unordered_map<std::invoke_result_t<Callback(std::iter_value_t<Iterator>, std::size_t)>, std::vector<std::iter_value_t<Iterator>>> group(Iterator begin, const std::sentinel_for<Iterator> auto end, const Callback& callback) {
		std::unordered_map<std::invoke_result_t<Callback(std::iter_value_t<Iterator>, std::size_t)>, std::vector<std::iter_value_t<Iterator>>> groups;
		for (std::size_t i = 0; begin != end; ++begin, ++i) {
			groups[callback(*begin, i)].push_back(*begin);
		}
		return groups;
	}
}
