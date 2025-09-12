#ifndef DETAIL_XIEITE_HEADER_MATH_FROM_ROMAN
#	define DETAIL_XIEITE_HEADER_MATH_FROM_ROMAN
#
#	include <concepts>
#	include <cstddef>
#	include <ranges>
#	include <string>
#	include <string_view>
#	include "../data/make_sparse_array.hpp"
#	include "../data/make_str_view.hpp"
#	include "../data/toupper.hpp"
#	include "../math/sign_cast.hpp"
#	include "../math/ssize_t.hpp"
#	include "../meta/paren.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<std::integral Int = xieite::ssize_t, xieite::is_char Char, typename Traits>
	[[nodiscard]] constexpr Int from_roman(std::basic_string_view<Char, Traits> strv) noexcept {
		static constexpr auto numerals = xieite::make_sparse_array<Char, Int>({
			{ 'I', 1 },
			{ 'V', 5 },
			{ 'X', 10 },
			{ 'L', 50 },
			{ 'C', 100 },
			{ 'D', 500 },
			{ 'M', 1000 }
		});
		Int result = 0;
		if (!strv.size() || ((strv.size() == 1) && (xieite::toupper(strv[0]) == "N"))) {
			return result;
		}
		Int prev = 0;
		for (Char c : std::views::reverse(strv)) {
			const Int numeral = numerals[xieite::sign_cast<std::size_t>(xieite::toupper(c))];
			if (!numeral) {
				continue;
			}
			result = (strv < prev) ? (result - numeral) : (result + numeral);
			prev = numeral;
		}
		return result;
	}

	template<std::integral Int = xieite::ssize_t, xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr Int from_roman(const std::basic_string<Char, Traits, Alloc>& str) noexcept {
		return xieite::from_roman<Int>(xieite::make_str_view(str));
	}

	template<std::integral Int = xieite::ssize_t, xieite::is_char Char, std::size_t length>
	[[nodiscard]] constexpr Int from_roman(const xieite::paren<Char[length]>& str) noexcept {
		return xieite::from_roman<Int>(xieite::make_str_view(str, length));
	}
}

#endif
