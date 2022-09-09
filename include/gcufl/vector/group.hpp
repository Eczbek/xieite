#pragma once

#include <concepts>
#include <cstddef>
#include <type_traits>
#include <unordered_map>
#include <vector>


namespace gcufl::vector {
	template <typename V, std::invocable<V> C>
	std::unordered_map<std::invoke_result_t<C(V)>, std::vector<V>> group(const std::vector<V>& values, const C& callback) noexcept {
		std::unordered_map<std::invoke_result_t<C(V)>, std::vector<V>> groups;
		for (const V& value : values)
			groups[callback(value)].push_back(value);
		return groups;
	}

	template <typename V, std::invocable<V, std::size_t> C>
	std::unordered_map<std::invoke_result_t<C(V, std::size_t)>, std::vector<V>> group(const std::vector<V>& values, const C& callback) noexcept {
		std::unordered_map<std::invoke_result_t<C(V, std::size_t)>, std::vector<V>> groups;
		for (std::size_t i = 0; i < values.size(); ++i)
			groups[callback(values[i], i)].push_back(values[i]);
		return groups;
	}
}
