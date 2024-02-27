#ifndef XIEITE_HEADER_CONTAINERS_MATRIX
#	define XIEITE_HEADER_CONTAINERS_MATRIX

#	include <algorithm>
#	include <array>
#	include <concepts>
#	include <cstddef>
#	include <initializer_list>
#	include <ranges>
#	include <stdexcept>
#	include <utility>
#	include <vector>
#	include "../concepts/range_of.hpp"
#	include "../macros/forward.hpp"
#	include "../math/wrap.hpp"

namespace xieite::containers {
	template<typename Value>
	struct Matrix {
	public:
		constexpr Matrix() noexcept
		: totalSize(0) {}

		template<xieite::concepts::RangeOf<Value> Range>
		constexpr Matrix(Range&& range) noexcept
		: values(std::ranges::begin(range), std::ranges::end(range)), totalSize(std::ranges::size(range)), dimensions(1, this->totalSize) {}

		constexpr Matrix(const std::initializer_list<Value> list) noexcept
		: xieite::containers::Matrix<Value>(std::ranges::ref_view(list)) {}

		template<typename Self, xieite::concepts::RangeOf<std::size_t> Range>
		[[nodiscard]] constexpr std::convertible_to<Value> auto&& operator[](this Self&& self, Range&& indices) {
			if (std::ranges::size(indices) != self.dimensions.size()) {
				throw std::out_of_range("Cannot access value by indices unfit for dimensions");
			}
			return XIEITE_FORWARD(self).values[self.index(XIEITE_FORWARD(indices)).first];
		}

		template<typename Self, std::convertible_to<std::size_t>... Sizes>
		[[nodiscard]] constexpr std::convertible_to<Value> auto&& operator[](this Self&& self, const Sizes... indices) {
			return XIEITE_FORWARD(self)[std::array<std::size_t, sizeof...(Sizes)> {
				static_cast<std::size_t>(indices)...
			}];
		}

		[[nodiscard]] constexpr const std::vector<Value>& data() const noexcept {
			return this->values;
		}

		[[nodiscard]] constexpr const std::vector<std::size_t>& size() const noexcept {
			return this->dimensions;
		}

		template<xieite::concepts::RangeOf<std::size_t> Range>
		constexpr void resize(Range&& dimensions) {
			std::size_t totalSize = 1;
			for (const std::size_t dimension : dimensions) {
				totalSize *= dimension;
			}
			if (totalSize > this->values.size()) {
				throw std::out_of_range("Cannot resize view to dimensions outside range");
			}
			this->totalSize = totalSize;
			this->dimensions = std::vector<std::size_t>(std::ranges::begin(dimensions), std::ranges::end(dimensions));
		}

		template<std::convertible_to<std::size_t>... Sizes>
		constexpr void resize(const Sizes... dimensions) {
			this->resize(std::array<std::size_t, sizeof...(Sizes)> {
				static_cast<std::size_t>(dimensions)...
			});
		}

		template<xieite::concepts::RangeOf<std::size_t> Range>
		constexpr void reverse(Range&& indices) {
			const std::size_t indicesSize = std::ranges::size(indices);
			if (this->dimensions.size() < (indicesSize + 1)) {
				throw std::out_of_range("Cannot reverse range of less than one dimension");
			}
			const std::size_t dimension = this->dimensions[indicesSize];
			const std::pair<std::size_t, std::size_t> index = this->index(indices, 1);
			for (std::size_t x = 0; x < (dimension / 2); ++x) {
				for (std::size_t y = 0; y < index.second; ++y) {
					std::ranges::swap(this->values[index.first + x * index.second + y], this->values[index.first + (dimension - x - 1) * index.second + y]);
				}
			}
		}

		template<std::convertible_to<std::size_t>... Sizes>
		constexpr void reverse(const Sizes... indices) {
			this->reverse(std::array<std::size_t, sizeof...(Sizes)> {
				static_cast<std::size_t>(indices)...
			});
		}

		template<std::integral Integer, xieite::concepts::RangeOf<std::size_t> Range>
		constexpr void rotate(const Integer rotations, Range&& indices) {
			const std::size_t indicesSize = std::ranges::size(indices);
			if (this->dimensions.size() < (indicesSize + 2)) {
				throw std::out_of_range("Cannot rotate range of less than two dimensions");
			}
			const std::size_t outerDimension = this->dimensions[indicesSize];
			const std::size_t innerDimension = this->dimensions[indicesSize + 1];
			const std::pair<std::size_t, std::size_t> index = this->index(indices, 2);
			const std::size_t rotatingSize = outerDimension * innerDimension * index.second;
			auto buffer = std::vector<Value>(rotatingSize);
			switch (xieite::math::wrap(rotations, 0, 3)) {
			case 1:
				for (std::size_t x = 0; x < outerDimension; ++x) {
					for (std::size_t y = 0; y < innerDimension; ++y) {
						for (std::size_t z = 0; z < index.second; ++z) {
							buffer[(y * outerDimension + x) * index.second + z] = std::move(this->values[index.first + ((outerDimension - x - 1) * innerDimension + y) * index.second + z]);
						}
					}
				}
				for (std::size_t i = 0; i < rotatingSize; ++i) {
					this->values[index.first + i] = std::move(buffer[i]);
				}
				std::ranges::swap(this->dimensions[indicesSize], this->dimensions[indicesSize + 1]);
				break;
			case 2:
				for (std::size_t x = 0; x < (outerDimension / 2); ++x) {
					for (std::size_t y = 0; y < innerDimension; ++y) {
						for (std::size_t z = 0; z < index.second; ++z) {
							std::ranges::swap(this->values[index.first + (x * innerDimension + y) * index.second + z], this->values[index.first + ((outerDimension - x) * innerDimension - y - 1) * index.second + z]);
						}
					}
				}
				break;
			case 3:
				for (std::size_t x = 0; x < outerDimension; ++x) {
					for (std::size_t y = 0; y < innerDimension; ++y) {
						for (std::size_t z = 0; z < index.second; ++z) {
							buffer[((innerDimension - y - 1) * outerDimension + x) * index.second + z] = std::move(this->values[index.first + (x * innerDimension + y) * index.second + z]);
						}
					}
				}
				for (std::size_t i = 0; i < rotatingSize; ++i) {
					this->values[index.first + i] = std::move(buffer[i]);
				}
				std::ranges::swap(this->dimensions[indicesSize], this->dimensions[indicesSize + 1]);
				break;
			}
		}

		template<std::integral Integer, std::convertible_to<std::size_t>... Sizes>
		constexpr void rotate(const Integer rotations, const Sizes... indices) {
			this->rotate(rotations, std::array<std::size_t, sizeof...(Sizes)> {
				static_cast<std::size_t>(indices)...
			});
		}

	private:
		std::vector<Value> values;
		std::size_t totalSize;
		std::vector<std::size_t> dimensions;

		template<xieite::concepts::RangeOf<std::size_t> Range>
		[[nodiscard]] constexpr std::pair<std::size_t, std::size_t> index(Range&& indices, const std::size_t extra = 0) const {
			std::pair<std::size_t, std::size_t> result = std::make_pair(0, this->totalSize);
			auto indicesIterator = std::ranges::begin(indices);
			const std::size_t indicesSize = std::ranges::size(indices);
			for (std::size_t i = 0; i < (indicesSize + extra); ++i) {
				result.first *= this->dimensions[i];
				result.second /= this->dimensions[i];
				if (i < indicesSize) {
					if (*indicesIterator >= this->dimensions[i]) {
						throw std::range_error("Cannot access value by index outside dimension");
					}
					result.first += *indicesIterator;
					++indicesIterator;
				}
			}

			return result;
		}
	};
}

#endif
