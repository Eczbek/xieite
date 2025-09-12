#ifndef DETAIL_XIEITE_HEADER_DATA_TRIM_BACK
#	define DETAIL_XIEITE_HEADER_DATA_TRIM_BACK
#
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../data/make_str_view.hpp"
#	include "../data/substr.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<xieite::is_char Char, typename Traits>
	[[nodiscard]] constexpr std::basic_string_view<Char, Traits> trim_back(std::basic_string_view<Char, Traits> strv, auto&& chars) noexcept {
		return xieite::substr(strv, 0, strv.find_last_not_of(XIEITE_FWD(chars)), 0, 1);
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr std::basic_string_view<Char, Traits> trim_back(const std::basic_string<Char, Traits, Alloc>& str, auto&& chars) noexcept {
		return xieite::trim_back(xieite::make_str_view(str), XIEITE_FWD(chars));
	}

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, std::size_t length>
	[[nodiscard]] constexpr std::basic_string_view<Char, Traits> trim_back(const xieite::paren<Char[length]>& str, auto&& chars) noexcept {
		return xieite::trim_back(xieite::make_str_view<Char, Traits>(str), XIEITE_FWD(chars));
	}
}

#endif
