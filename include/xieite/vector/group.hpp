#pragma once
#include <concepts> // std::invocable
#include <cstddef> // std::size_t
#include <type_traits> // std::invoke_result_t
#include <unordered_map> // std::unordered_map
#include <vector> // std::vector

namespace xieite::vector {
	template<typename T, std::invocable<T> C>
	[[nodiscard]]
	std::unordered_map<std::invoke_result_t<C(T)>, std::vector<T>> group(const std::vector<T>& values, C&& callback) noexcept {
		std::unordered_map<std::invoke_result_t<C(T)>, std::vector<T>> groups;
		for (const T& value : values)
			groups[callback(value)].push_back(value);
		return groups;
	}

	template<typename T, std::invocable<T, std::size_t> C>
	[[nodiscard]]
	std::unordered_map<std::invoke_result_t<C(T, std::size_t)>, std::vector<T>> group(const std::vector<T>& values, C&& callback) noexcept {
		std::unordered_map<std::invoke_result_t<C(T, std::size_t)>, std::vector<T>> groups;
		const std::size_t valuesSize = values.size();
		for (std::size_t i = 0; i < valuesSize; ++i)
			groups[callback(values[i], i)].push_back(values[i]);
		return groups;
	}
}
