#ifndef DETAIL_XIEITE_HEADER_DATA_STR_BETWEEN
#	define DETAIL_XIEITE_HEADER_DATA_STR_BETWEEN
#
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../data/make_str_view.hpp"
#	include "../data/str_after.hpp"
#	include "../data/str_before_last.hpp"
#	include "../meta/type.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<xieite::is_char Char, typename Traits>
	[[nodiscard]] constexpr std::basic_string_view<Char, Traits> str_between(std::basic_string_view<Char, Traits> strv, auto&& after, auto&& before) noexcept {
		return xieite::str_before_last(xieite::str_after(strv, XIEITE_FWD(after)), XIEITE_FWD(before));
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr std::basic_string_view<Char, Traits> str_between(const std::basic_string<Char, Traits, Alloc>& str, auto&& after, auto&& before) noexcept {
		return xieite::str_between(xieite::make_str_view(str), XIEITE_FWD(after), XIEITE_FWD(before));
	}

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, std::size_t length>
	[[nodiscard]] constexpr std::basic_string_view<Char, Traits> str_between(const xieite::type<Char[length]>& str, auto&& after, auto&& before) noexcept {
		return xieite::str_between(xieite::make_str_view<Char, Traits>(str), XIEITE_FWD(after), XIEITE_FWD(before));
	}
}

#endif
