#pragma once
#include <concepts>
#include <cstddef>
#include <type_traits>
#include <unordered_map>
#include <vector>

namespace xieite::vector {
	template<typename V, std::invocable<V> C>
	[[nodiscard]]
	std::unordered_map<std::invoke_result_t<C(V)>, std::vector<V>> group(const std::vector<V>& values, const C& callback) noexcept {
		std::unordered_map<std::invoke_result_t<C(V)>, std::vector<V>> groups;
		for (const V& value : values)
			groups[callback(value)].push_back(value);
		return groups;
	}

	template<typename V, std::invocable<V, std::size_t> C>
	[[nodiscard]]
	std::unordered_map<std::invoke_result_t<C(V, std::size_t)>, std::vector<V>> group(const std::vector<V>& values, const C& callback) noexcept {
		std::unordered_map<std::invoke_result_t<C(V, std::size_t)>, std::vector<V>> groups;
		const std::size_t valuesSize = values.size();
		for (std::size_t i = 0; i < valuesSize; ++i)
			groups[callback(values[i], i)].push_back(values[i]);
		return groups;
	}
}
