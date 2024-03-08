#ifndef XIEITE_HEADER_STRINGS_FROM_ROMAN_NUMERALS
#	define XIEITE_HEADER_STRINGS_FROM_ROMAN_NUMERALS

#	include <concepts>
#	include <cmath>
#	include <cstddef>
#	include <ranges>
#	include <string_view>
#	include "../concepts/string_view.hpp"
#	include "../strings/to_uppercase.hpp"

namespace xieite::strings {
	template<std::integral Integer = int, xieite::concepts::StringView StringView = std::string_view>
	[[nodiscard]] constexpr Integer fromRomanNumerals(const StringView value) noexcept {
		static constexpr StringView numerals = "IVXLCDM";
		Integer result = 0;
		if (!value.size() || (value == "N")) {
			return result;
		}
		Integer previous = 0;
		for (const StringView::value_type digit : std::views::reverse(value)) {
			const std::size_t index = numerals.find(xieite::strings::toUppercase(digit));
			if (index == StringView::npos) {
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
