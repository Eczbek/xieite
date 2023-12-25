#ifndef XIEITE_HEADER_STRINGS_PARSE_NUMBER
#	define XIEITE_HEADER_STRINGS_PARSE_NUMBER

#	include <cmath>
#	include <concepts>
#	include <cstddef>
#	include <string_view>
#	include "../concepts/arithmetic.hpp"
#	include "../strings/digit.hpp"
#	include "../strings/trim.hpp"
#	include "../strings/whitespaces.hpp"

namespace xieite::strings {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr Number parseNumber(std::string_view value) noexcept {
		value = xieite::strings::trim(value, xieite::strings::whitespaces);
		const bool negative = value[0] == '-';
		const std::size_t valueSize = value.size();
		if constexpr (std::integral<Number>) {
			Number result = 0;
			for (std::size_t i = negative || (value[0] == '+'); (i < valueSize) && xieite::strings::digit(value[i]); ++i) {
				result = result * 10 + (value[i] - '0');
			}
			return negative ? -result : result;
		} else {
			bool point = false;
			Number integer = 0;
			Number decimal = 0;
			int power = 0;
			for (std::size_t i = negative || (value[0] == '+'); i < valueSize; ++i) {
				if (xieite::strings::digit(value[i])) {
					Number& part = (point ? decimal : integer);
					part = part * 10 + (value[i] - '0');
				} else if ((value[i] == '.')) {
					point = true;
				} else {
					if ((value[i] == 'E') || (value[i] == 'e')){
						power = xieite::strings::parseNumber<int>(value.substr(i + 1));
					}
					break;
				}
			}
			return (!negative * 2 - 1) * (integer + decimal / std::pow(10, std::floor(std::log10(decimal + !decimal)) + 1)) * std::pow(10, power);
		}
	}
}

#endif
