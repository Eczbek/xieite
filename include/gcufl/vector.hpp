#pragma once

#include <cmath>
#include <string>
#include <unordered_map>
#include <vector>


namespace gcufl::vector {
	template <typename K = std::string, typename V, typename C>
	std::unordered_map<K, std::vector<V>> group(const std::vector<V>& values, const C& getGroup) noexcept {
		std::unordered_map<K, std::vector<V>> groups;
		for (std::size_t i = 0; i < values.size(); ++i)
			groups[getGroup(values[i], i)].push_back(values[i]);
		return groups;
	}

	template <typename V>
	std::vector<std::vector<V>> rotateCW(const std::vector<std::vector<V>>& values) noexcept {
		std::vector<std::vector<V>> rotated;
		for (std::size_t y = 0; y < values[0].size(); ++y) {
			std::vector<V> row;
			for (std::size_t x = values.size(); x > 0; --x)
				row.push_back(values[x - 1][y]);
			rotated.push_back(row);
		}
		return rotated;
	}

	template <typename V>
	std::vector<std::vector<V>> rotateCCW(const std::vector<std::vector<V>>& values) noexcept {
		std::vector<std::vector<V>> rotated;
		for (std::size_t y = values[0].size(); y > 0; --y) {
			std::vector<V> row;
			for (std::size_t x = 0; x < values.size(); ++x)
				row.push_back(values[x][y - 1]);
			rotated.push_back(row);
		}
		return rotated;
	}
}
