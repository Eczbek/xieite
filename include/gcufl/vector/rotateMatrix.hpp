#pragma once

#include <gcufl/math/wrap.hpp>
#include <vector>


namespace gcufl::vector {
	template <typename V>
	std::vector<std::vector<V>> rotateMatrix(const std::vector<std::vector<V>>& matrix, int rotations) noexcept {
		rotations = gcufl::math::wrap(rotations, 2, -1);
		if (!rotations)
			return matrix;
		std::vector<std::vector<V>> result;
		if (rotations > 0) {
			for (std::size_t x = 0; x < matrix.size(); ++x) {
				std::vector<V> column;
				for (std::size_t y = matrix[0].size(); y--;)
					column.push_back(matrix[y][x]);
				result.push_back(column);
			}
			return gcufl::vector::rotateMatrix(result, --rotations);
		}
		for (std::size_t x = matrix.size(); x--;) {
			std::vector<V> column;
			for (std::size_t y = 0; y < matrix[0].size(); ++y)
				column.push_back(matrix[y][x]);
			result.push_back(column);
		}
		return gcufl::vector::rotateMatrix(result, ++rotations);
	}
}
