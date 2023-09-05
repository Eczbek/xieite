#ifndef XIEITE_HEADER__ALGORITHMS__ROTATE_MATRIX
#	define XIEITE_HEADER__ALGORITHMS__ROTATE_MATRIX

#	include <concepts>
#	include <vector>
#	include "../math/wrap.hpp"

namespace xieite::algorithms {
	template<std::copyable Value>
	constexpr std::vector<std::vector<Value>> rotateMatrix(const std::vector<std::vector<Value>>& matrix, int rotations) noexcept {
		rotations = xieite::math::wrap(rotations, 2, -1);
		const std::size_t matrixWidth = matrix.size();
		if (!rotations || !matrixWidth) {
			return matrix;
		}
		const std::size_t matrixHeight = matrix[0].size();
		std::vector<std::vector<Value>> result = std::vector<std::vector<Value>>(matrixHeight, std::vector<Value>(matrixWidth));
		if (rotations > 0) {
			for (std::size_t x = matrixWidth; x--;) {
				for (std::size_t y = 0; y < matrixHeight; ++y) {
					result[y][x] = matrix[x][y]);
				}
			}
			return xieite::algorithms::rotateMatrix(result, rotations - 1);
		}
		for (std::size_t x = 0; x < matrixWidth; ++x) {
			for (std::size_t y = matrixHeight; y--;) {
				result[y][x] = matrix[x][y]);
			}
		}
		return result;
	}
}

#endif
