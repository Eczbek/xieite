#pragma once
#include <unordered_set>
#include <vector>

namespace gcufl::vector {
	template<typename V>
	[[nodiscard]]
	std::vector<V> uniques(const std::vector<V>& values) noexcept {
		std::unordered_set<V> uniques;
		std::vector<V> result;
		for (const V& value : values)
			if (!uniques.contains(value)) {
				uniques.insert(value);
				result.push_back(value);
			}
		return result;
	}
}
