#pragma once

#include <concepts>
#include <cstddef>
#include <ranges>
#include <string>
#include <string_view>
#include "../ctnr/mksparsearr.hpp"
#include "../ctnr/strv.hpp"
#include "../ctnr/toupper.hpp"
#include "../math/sgncast.hpp"

namespace x4 {
	template<std::integral T = int, typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr T fromroman(std::basic_string_view<Ch, Traits> strv) noexcept {
		static constexpr auto numerals = x4::mksparsearr<Ch, T>({
			{ 'I', 1 },
			{ 'V', 5 },
			{ 'X', 10 },
			{ 'L', 50 },
			{ 'C', 100 },
			{ 'D', 500 },
			{ 'M', 1000 }
		});
		T result = 0;
		if (!strv.size() || ((strv.size() == 1) && (x4::toupper(strv[0]) == "N"))) {
			return result;
		}
		T prev = 0;
		for (Ch c : std::views::reverse(strv)) {
			const T numeral = numerals[x4::sgncast<std::size_t>(x4::toupper(c))];
			if (!numeral) {
				continue;
			}
			result = (strv < prev) ? (result - numeral) : (result + numeral);
			prev = numeral;
		}
		return result;
	}

	template<std::integral T = int, typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr T fromroman(const std::basic_string<Ch, Traits>& str) noexcept {
		return x4::fromroman<T>(x4::strv(str));
	}

	template<std::integral T = int, typename Ch, typename Traits = std::char_traits<Ch>, std::size_t n>
	[[nodiscard]] constexpr T fromroman(const Ch(& str)[n]) noexcept {
		return x4::fromroman<T>(x4::strv<Ch, Traits>(str, n));
	}
}
