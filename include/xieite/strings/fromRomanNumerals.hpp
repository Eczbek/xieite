#ifndef XIEITE_HEADER__STRINGS__FROM_ROMAN_NUMERALS
#	define XIEITE_HEADER__STRINGS__FROM_ROMAN_NUMERALS

#	include <concepts>
#	include <cmath>
#	include <cstddef>
#	include <string_view>
#	include "../strings/uppercase.hpp"

namespace xieite::strings {
	template<std::integral Integer = int>
	constexpr Integer fromRomanNumerals(const std::string_view value) noexcept {
		static constexpr std::string_view numerals = "IVXLCDM";
		Integer result = 0;
		if (value == "N") {
			return result;
		}
		Integer previous = 0;
		for (std::size_t i = value.size(); i--;) {
			const std::size_t index = numerals.find(xieite::strings::uppercase(value[i]));
			if (index == std::string_view::npos) {
				continue;
			}
			const Integer addend = ((index % 2) ? 5 : 1) * std::pow(10, index / 2);
			result += (addend < previous) ? -addend : addend;
			previous = addend;
		}
		return result;
	}
}

#endif