#pragma once

#include <unordered_set>
#include <vector>

namespace xieite::vector {
	template<typename Value>
	[[nodiscard]]
	std::vector<Value> uniques(const std::vector<Value>& values) noexcept {
		std::unordered_set<Value> uniques;
		std::vector<Value> result;
		for (const Value& value : values)
			if (!uniques.contains(value)) {
				uniques.insert(value);
				result.push_back(value);
			}
		return result;
	}
}
