#pragma once
#include <concepts> // std::invocable
#include <cstddef> // std::size_t
#include <type_traits> // std::invoke_result_t
#include <unordered_map> // std::unordered_map
#include <vector> // std::vector

namespace xieite::vector {
	template<typename Value, std::invocable<Value> Invocable>
	[[nodiscard]]
	std::unordered_map<std::invoke_result_t<Invocable(Value)>, std::vector<Value>> group(const std::vector<Value>& values, Invocable&& callback) noexcept {
		std::unordered_map<std::invoke_result_t<Invocable(Value)>, std::vector<Value>> groups;
		for (const Value& value : values)
			groups[callback(value)].push_back(value);
		return groups;
	}

	template<typename Value, std::invocable<Value, std::size_t> Invocable>
	[[nodiscard]]
	std::unordered_map<std::invoke_result_t<Invocable(Value, std::size_t)>, std::vector<Value>> group(const std::vector<Value>& values, Invocable&& callback) noexcept {
		std::unordered_map<std::invoke_result_t<Invocable(Value, std::size_t)>, std::vector<Value>> groups;
		const std::size_t valuesSize = values.size();
		for (std::size_t i = 0; i < valuesSize; ++i)
			groups[callback(values[i], i)].push_back(values[i]);
		return groups;
	}
}
