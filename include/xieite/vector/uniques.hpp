#pragma once
#include <unordered_set> // std::unordered_set
#include <vector> // std::vector

namespace xieite::vector {
	template<typename T>
	[[nodiscard]]
	std::vector<T> uniques(const std::vector<T>& values) noexcept {
		std::unordered_set<T> uniques;
		std::vector<T> result;
		for (const T& value : values)
			if (!uniques.contains(value)) {
				uniques.insert(value);
				result.push_back(value);
			}
		return result;
	}
}
