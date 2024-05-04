#ifndef XIEITE_HEADER_CONTAINERS_MATRIX
#	define XIEITE_HEADER_CONTAINERS_MATRIX

#	include <algorithm>
#	include <array>
#	include <concepts>
#	include <cstddef>
#	include <initializer_list>
#	include <optional>
#	include <ranges>
#	include <type_traits>
#	include <utility>
#	include <variant>
#	include <vector>
#	include "../concepts/range_of.hpp"
#	include "../macros/forward.hpp"
#	include "../math/wrap.hpp"
#	include "../types/maybe_constant.hpp"

namespace xieite::containers {
	template<typename Value_>
	struct Matrix {
	public:
		constexpr Matrix() noexcept
		: totalSize(0) {}

		template<xieite::concepts::RangeOf<Value_> Range_>
		constexpr Matrix(Range_&& range) noexcept
		: values(std::ranges::begin(range), std::ranges::end(range)), totalSize(std::ranges::size(range)), dimensions(1, this->totalSize) {}

		constexpr Matrix(const std::initializer_list<Value_> list) noexcept
		: xieite::containers::Matrix<Value_>(std::ranges::ref_view(list)) {}

		template<typename Self_, xieite::concepts::RangeOf<std::size_t> Range_>
		[[nodiscard]] constexpr std::optional<std::reference_wrapper<xieite::types::MaybeConstant<Value_, std::is_const_v<Self_>>>> operator[](this Self_&& self, Range_&& indices) noexcept {
			if (std::ranges::size(indices) != self.dimensions.size()) {
				return std::nullopt;
			}
			return self.index(XIEITE_FORWARD(indices)).and_then([&self](const std::pair<std::size_t, std::size_t> index) {
				return XIEITE_FORWARD(self).values[index.first];
			});
		}

		template<typename Self_, std::convertible_to<std::size_t>... Sizes_>
		[[nodiscard]] constexpr std::optional<std::reference_wrapper<xieite::types::MaybeConstant<Value_, std::is_const_v<Self_>>>> operator[](this Self_&& self, const Sizes_... indices) noexcept {
			return XIEITE_FORWARD(self)[std::array<std::size_t, sizeof...(Sizes_)> {
				static_cast<std::size_t>(indices)...
			}];
		}

		[[nodiscard]] constexpr const std::vector<Value_>& data() const noexcept {
			return this->values;
		}

		[[nodiscard]] constexpr const std::vector<std::size_t>& size() const noexcept {
			return this->dimensions;
		}

		template<xieite::concepts::RangeOf<std::size_t> Range_>
		constexpr std::optional<std::monostate> resize(Range_&& dimensions) noexcept {
			std::size_t totalSize = 1;
			for (const std::size_t dimension : dimensions) {
				totalSize *= dimension;
			}
			if (totalSize > this->values.size()) {
				return std::nullopt;
			}
			this->totalSize = totalSize;
			this->dimensions = std::vector<std::size_t>(std::ranges::begin(dimensions), std::ranges::end(dimensions));
			return std::monostate();
		}

		template<std::convertible_to<std::size_t>... Sizes_>
		constexpr std::optional<std::monostate> resize(const Sizes_... dimensions) noexcept {
			return this->resize(std::array<std::size_t, sizeof...(Sizes_)> {
				static_cast<std::size_t>(dimensions)...
			});
		}

		template<xieite::concepts::RangeOf<std::size_t> Range_>
		constexpr std::optional<std::monostate> reverse(Range_&& indices) noexcept {
			const std::size_t indicesSize = std::ranges::size(indices);
			if (this->dimensions.size() < (indicesSize + 1)) {
				return std::nullopt;
				ret
			}
			return this->index(indices, 1).and_then([this, indicesSize](const std::pair<std::size_t, std::size_t> index) {
				const std::size_t dimension = this->dimensions[indicesSize];
				for (std::size_t x = 0; x < (dimension / 2); ++x) {
					for (std::size_t y = 0; y < index.second; ++y) {
						std::ranges::swap(this->values[index.first + x * index.second + y], this->values[index.first + (dimension - x - 1) * index.second + y]);
					}
				}
				return std::monostate();
			});
		}

		template<std::convertible_to<std::size_t>... Sizes_>
		constexpr std::optional<std::monostate> reverse(const Sizes_... indices) noexcept {
			return this->reverse(std::array<std::size_t, sizeof...(Sizes_)> {
				static_cast<std::size_t>(indices)...
			});
		}

		template<std::integral Integral_, xieite::concepts::RangeOf<std::size_t> Range_>
		constexpr std::optional<std::monostate> rotate(const Integral_ rotations, Range_&& indices) noexcept {
			const std::size_t indicesSize = std::ranges::size(indices);
			if (this->dimensions.size() < (indicesSize + 2)) {
				return std::nullopt;
			}
			return this->index(indices, 2).and_then([this, indicesSize](const std::pair<std::size_t, std::size_t> index) {
				const std::size_t outerDimension = this->dimensions[indicesSize];
				const std::size_t innerDimension = this->dimensions[indicesSize + 1];
				const std::size_t rotatingSize = outerDimension * innerDimension * index.second;
				auto buffer = std::vector<Value_>(rotatingSize);
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
				return std::monostate();
			});
		}

		template<std::integral Integral_, std::convertible_to<std::size_t>... Sizes_>
		constexpr std::optional<std::monostate> rotate(const Integral_ rotations, const Sizes_... indices) noexcept {
			return this->rotate(rotations, std::array<std::size_t, sizeof...(Sizes_)> {
				static_cast<std::size_t>(indices)...
			});
		}

	private:
		std::vector<Value_> values;
		std::size_t totalSize;
		std::vector<std::size_t> dimensions;

		template<xieite::concepts::RangeOf<std::size_t> Range_>
		[[nodiscard]] constexpr std::optional<std::pair<std::size_t, std::size_t>> index(Range_&& indices, const std::size_t extra = 0) const noexcept {
			std::pair<std::size_t, std::size_t> result = std::make_pair(0, this->totalSize);
			auto indicesIterator = std::ranges::begin(indices);
			const std::size_t indicesSize = std::ranges::size(indices);
			for (std::size_t i = 0; i < (indicesSize + extra); ++i) {
				result.first *= this->dimensions[i];
				result.second /= this->dimensions[i];
				if (i < indicesSize) {
					if (*indicesIterator >= this->dimensions[i]) {
						return std::nullopt;
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
