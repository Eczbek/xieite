#ifndef DETAIL_XIEITE_HEADER_DATA_TRIM_FRONT
#	define DETAIL_XIEITE_HEADER_DATA_TRIM_FRONT
#
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../data/make_str_view.hpp"
#	include "../meta/type.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<xieite::is_char Char, typename Traits>
	[[nodiscard]] constexpr std::basic_string_view<Char, Traits> trim_front(std::basic_string_view<Char, Traits> strv, auto&& chars) noexcept {
		return strv.substr(strv.find_first_not_of(XIEITE_FWD(chars)));
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr std::basic_string_view<Char, Traits> trim_front(const std::basic_string<Char, Traits, Alloc>& str, auto&& chars) noexcept {
		return xieite::trim_front(xieite::make_str_view(str), XIEITE_FWD(chars));
	}

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, std::size_t length>
	[[nodiscard]] constexpr std::basic_string_view<Char, Traits> trim_front(const xieite::type<Char[length]>& str, auto&& chars) noexcept {
		return xieite::trim_front(xieite::make_str_view<Char, Traits>(str), XIEITE_FWD(chars));
	}
}

#endif
