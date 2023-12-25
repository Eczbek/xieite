#ifndef XIEITE_HEADER_STRINGS_VALID_NUMBER
#	define XIEITE_HEADER_STINGS_VALID_NUMBER

#	include <concepts>
#	include <cstddef>
#	include <string_view>
#	include "../concepts/arithmetic.hpp"
#	include "../strings/digit.hpp"
#	include "../strings/trim.hpp"
#	include "../strings/whitespaces.hpp"

namespace xieite::strings {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr Number validNumber(std::string_view value) noexcept {
		value = xieite::strings::trim(value, xieite::strings::whitespaces);
		if (!xieite::strings::digit(value[0]) && (value[0] != '+') && (value[0] != '-')) {
			return false;
		}
		const std::size_t valueSize = value.size();
		if constexpr (std::integral<Number>) {
			for (std::size_t i = 1; i < valueSize; ++i) {
				if (!xieite::strings::digit(value[i])) {
					return false;
				}
			}
		} else {
			bool point = false;
			for (std::size_t i = 1; i < valueSize; ++i) {
				if (xieite::strings::digit(value[i])) {
					continue;
				} else if (!point && (value[i] == '.')) {
					point = true;
				} else if ((value[i] == 'E') || (value[i] == 'e')) {
					return xieite::strings::validNumber<int>(value.substr(i));
				} else {
					return false;
				}
			}
		}
		return true;
	}
}

#endif
