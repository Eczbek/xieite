#ifndef DETAIL_XIEITE_HEADER_DATA_ISSPACE
#	define DETAIL_XIEITE_HEADER_DATA_ISSPACE
#
#	include <string>
#	include <string_view>
#	include "../data/isblank.hpp"
#	include "../data/make_str_view.hpp"
#	include "../meta/type.hpp"
#	include "../pp/cases.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	[[nodiscard]] constexpr bool isspace(xieite::is_char auto c) noexcept {
		switch (c) {
		XIEITE_CASES('\f', '\n', '\r', '\v'):
			return true;
		}
		return xieite::isblank(c);
	}

	template<xieite::is_char Char, typename Traits>
	[[nodiscard]] constexpr bool isspace(
		std::basic_string_view<Char, Traits> strv
	) noexcept {
		for (Char c : strv) {
			if (!xieite::isspace(c)) {
				return false;
			}
		}
		return true;
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr bool isspace(
		const std::basic_string<Char, Traits, Alloc>& str
	) noexcept {
		return xieite::isspace(xieite::make_str_view(str));
	}

	template<xieite::is_char Char, std::size_t length>
	[[nodiscard]] constexpr bool isspace(
		const xieite::type<Char[length]>& str
	) noexcept {
		return xieite::isspace(xieite::make_str_view(str));
	}
}

#endif
