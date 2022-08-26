#pragma once

#include <cmath>
#include <concepts>
#include <limits>
#include <numbers>
#include <string>
#include <string_view>
#include <gcufl/orderedMap.hpp>


namespace gcufl {
	namespace math {
		template <typename N>
		N wrap(const N value, const N max, const N min = 0) noexcept {
			const N diff = max - min;
			return std::fmod(std::fmod(value - min, diff) + diff, diff) + min;
		}

		template <typename N>
		bool approxEqual(const N value1, const N value2) noexcept {
			return std::fabs(value1 - value2) <= std::numeric_limits<N>::epsilon();
		}

		template <typename N>
		int sign(const N value) noexcept {
			return value > 0
				? 1
				: value < 0
					? -1
					: 0;
		}

		template <typename N>
		double degrees(const N radians) noexcept {
			return radians * 180 / std::numbers::pi;
		}

		template <typename N>
		double radians(const N degrees) noexcept {
			return degrees * std::numbers::pi / 180;
		}

		template <std::integral N>
		std::string toBase(N value, const int base, std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept {
			std::string result;
			while (value) {
				result = digits[value % base] + result;
				value /= base;
			}
			return result;
		}

		template <std::integral N = int>
		N fromBase(std::string_view value, const int base, std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept {
			gcufl::OrderedMap<char, std::size_t> charMap;
			for (std::size_t i = 0; i < digits.size(); ++i)
				charMap[digits[i]] = i;
			N result = 0;
			N currentBase = 1;
			for (std::size_t i = value.size(); i > 0; --i) {
				result += charMap[value[i - 1]] * currentBase;
				currentBase *= base;
			}
			return result;
		}
	}
}
