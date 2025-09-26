#ifndef DETAIL_XIEITE_HEADER_DATA_STR_BEFORE
#	define DETAIL_XIEITE_HEADER_DATA_STR_BEFORE
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
	[[nodiscard]] constexpr std::basic_string_view<Char, Traits>
	str_before(
		std::basic_string_view<Char, Traits> strv,
		auto&& delim
	) noexcept {
		return strv.substr(0, strv.find(XIEITE_FWD(delim)));
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr std::basic_string_view<Char, Traits>
	str_before(
		const std::basic_string<Char, Traits, Alloc>& str,
		auto&& delim
	) noexcept {
		return xieite::str_before(
			xieite::make_str_view(str),
			XIEITE_FWD(delim)
		);
	}

	template<
		xieite::is_char Char,
		typename Traits = std::char_traits<Char>,
		std::size_t length
	> [[nodiscard]] constexpr std::basic_string_view<Char, Traits>
	str_before(
		const xieite::type<Char[length]>& str,
		auto&& delim
	) noexcept {
		return xieite::str_before(
			xieite::make_str_view<Char, Traits>(str),
			XIEITE_FWD(delim)
		);
	}
}

#endif
