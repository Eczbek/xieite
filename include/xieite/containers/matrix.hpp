#ifndef XIEITE_HEADER_CONTAINERS_MATRIX
#	define XIEITE_HEADER_CONTAINERS_MATRIX

#	include <algorithm>
#	include <array>
#	include <concepts>
#	include <cstddef>
#	include <expected>
#	include <initializer_list>
#	include <ranges>
#	include <utility>
#	include <vector>
#	include "../concepts/range_of.hpp"
#	include "../errors/type.hpp"
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
		[[nodiscard]] constexpr std::expected<auto&&, xieite::errors::Type> operator[](this Self&& self, Range&& indices) noexcept {
			if (std::ranges::size(indices) != self.dimensions.size()) {
				return std::unexpected(xieite::errors::Type::DimensionsMismatch);
			}
			return self.index(XIEITE_FORWARD(indices)).and_then([&self](const std::pair<std::size_t, std::size_t> index) {
				return XIEITE_FORWARD(self).values[index.first];
			});
		}

		template<typename Self, std::convertible_to<std::size_t>... Sizes>
		[[nodiscard]] constexpr std::expected<auto&&, xieite::errors::Type> operator[](this Self&& self, const Sizes... indices) noexcept {
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
		constexpr std::expected<void, xieite::errors::Type> resize(Range&& dimensions) noexcept {
			std::size_t totalSize = 1;
			for (const std::size_t dimension : dimensions) {
				totalSize *= dimension;
			}
			if (totalSize > this->values.size()) {
				return std::unexpected(xieite::errors::Type::DimensionsMismatch);
			}
			this->totalSize = totalSize;
			this->dimensions = std::vector<std::size_t>(std::ranges::begin(dimensions), std::ranges::end(dimensions));
		}

		template<std::convertible_to<std::size_t>... Sizes>
		constexpr std::expected<void, xieite::errors::Type> resize(const Sizes... dimensions) noexcept {
			return this->resize(std::array<std::size_t, sizeof...(Sizes)> {
				static_cast<std::size_t>(dimensions)...
			});
		}

		template<xieite::concepts::RangeOf<std::size_t> Range>
		constexpr std::expected<void, xieite::errors::Type> reverse(Range&& indices) noexcept {
			const std::size_t indicesSize = std::ranges::size(indices);
			if (this->dimensions.size() < (indicesSize + 1)) {
				return std::unexpected(xieite::errors::Type::DimensionsMismatch);
				ret
			}
			return this->index(indices, 1).and_then([this, indicesSize](const std::pair<std::size_t, std::size_t> index) {
				const std::size_t dimension = this->dimensions[indicesSize];
				for (std::size_t x = 0; x < (dimension / 2); ++x) {
					for (std::size_t y = 0; y < index.second; ++y) {
						std::ranges::swap(this->values[index.first + x * index.second + y], this->values[index.first + (dimension - x - 1) * index.second + y]);
					}
				}
				return std::expected<void, xieite::errors::Type>();
			});
		}

		template<std::convertible_to<std::size_t>... Sizes>
		constexpr std::expected<void, xieite::errors::Type> reverse(const Sizes... indices) noexcept {
			return this->reverse(std::array<std::size_t, sizeof...(Sizes)> {
				static_cast<std::size_t>(indices)...
			});
		}

		template<std::integral Integral, xieite::concepts::RangeOf<std::size_t> Range>
		constexpr std::expected<void, xieite::errors::Type> rotate(const Integral rotations, Range&& indices) noexcept {
			const std::size_t indicesSize = std::ranges::size(indices);
			if (this->dimensions.size() < (indicesSize + 2)) {
				return std::unexpected(xieite::errors::Type::DimensionsMismatch);
			}
			this->index(indices, 2).and_then([this, indicesSize](const std::pair<std::size_t, std::size_t> index) {
				const std::size_t outerDimension = this->dimensions[indicesSize];
				const std::size_t innerDimension = this->dimensions[indicesSize + 1];
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
				return std::expected<void, xieite::errors::Type>();
			});
		}

		template<std::integral Integral, std::convertible_to<std::size_t>... Sizes>
		constexpr std::expected<void, xieite::errors::Type> rotate(const Integral rotations, const Sizes... indices) {
			return this->rotate(rotations, std::array<std::size_t, sizeof...(Sizes)> {
				static_cast<std::size_t>(indices)...
			});
		}

	private:
		std::vector<Value> values;
		std::size_t totalSize;
		std::vector<std::size_t> dimensions;

		template<xieite::concepts::RangeOf<std::size_t> Range>
		[[nodiscard]] constexpr std::expected<std::pair<std::size_t, std::size_t>, xieite::errors::Type> index(Range&& indices, const std::size_t extra = 0) const {
			std::pair<std::size_t, std::size_t> result = std::make_pair(0, this->totalSize);
			auto indicesIterator = std::ranges::begin(indices);
			const std::size_t indicesSize = std::ranges::size(indices);
			for (std::size_t i = 0; i < (indicesSize + extra); ++i) {
				result.first *= this->dimensions[i];
				result.second /= this->dimensions[i];
				if (i < indicesSize) {
					if (*indicesIterator >= this->dimensions[i]) {
						return std::unexpected(xieite::errors::Type::IndexOutOfRange);
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
