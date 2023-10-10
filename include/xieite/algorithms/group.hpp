#pragma once

#include <concepts>
#include <cstddef>
#include <funtional>
#include <ranges>
#include <type_traits>
#include <unordered_map>
#include <vector>

namespace xieite::algorithms {
	template<std::ranges::range Range, std::invocable<std::ranges::range_value_t<Range>> Functor>
	[[nodiscard]] inline std::unordered_map<std::invoke_result_t<Functor(std::ranges::range_value_t<Range>)>, std::vector<std::ranges::range_value_t<Range>>> group(const Range& range, const Functor& callback) {
		return xieite::algorithms::group(range, [&callback](auto value, std::size_t) {
			return std::invoke(callback, value);
		});
	}

	template<std::ranges::range Range, std::invocable<std::ranges::range_value_t<Range>, std::size_t> Functor>
	[[nodiscard]] inline std::unordered_map<std::invoke_result_t<Functor(std::ranges::range_value_t<Range>, std::size_t)>, std::vector<std::ranges::range_value_t<Range>>> group(const Range& range, const Functor& callback) {
		std::unordered_map<std::invoke_result_t<Functor(std::ranges::range_value_t<Range>, std::size_t)>, std::vector<std::ranges::range_value_t<Range>>> groups;
		auto begin = std::ranges::begin(range);
		const auto end = std::ranges::end(range);
		for (std::size_t i = 0; begin != end; ++begin, ++i) {
			groups[std::invoke(callback, *begin, i)].push_back(*begin);
		}
		return groups;
	}
}
