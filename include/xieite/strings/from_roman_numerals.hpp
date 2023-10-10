#pragma once

#include <concepts>
#include <cmath>
#include <cstddef>
#include <ranges>
#include <string_view>
#include "../strings/uppercase.hpp"

namespace xieite::strings {
	template<std::integral Integer = int>
	[[nodiscard]] constexpr Integer fromRomanNumerals(const std::string_view value) noexcept {
		static constexpr std::string_view numerals = "IVXLCDM";
		Integer result = 0;
		if (!value.size() || (value == "N")) {
			return result;
		}
		Integer previous = 0;
		for (const char digit : std::views::reverse(value)) {
			const std::size_t index = numerals.find(xieite::strings::uppercase(digit));
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
