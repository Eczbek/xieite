#ifndef DETAIL_XIEITE_HEADER_DATA_ISXDIGIT
#	define DETAIL_XIEITE_HEADER_DATA_ISXDIGIT
#
#	include <string>
#	include <string_view>
#	include "../data/isdigit.hpp"
#	include "../data/make_str_view.hpp"
#	include "../meta/type.hpp"
#	include "../pp/cases.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	[[nodiscard]] constexpr bool isxdigit(xieite::is_char auto c) noexcept {
		switch (c) {
		XIEITE_CASES('A', 'B', 'C', 'D', 'E', 'F', 'a', 'b', 'c', 'd', 'e', 'f'):
			return true;
		}
		return xieite::isdigit(c);
	}

	template<xieite::is_char Char, typename Traits>
	[[nodiscard]] constexpr bool isxdigit(std::basic_string_view<Char, Traits> strv) noexcept {
		for (Char c : strv) {
			if (!xieite::isxdigit(c)) {
				return false;
			}
		}
		return true;
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr bool isxdigit(const std::basic_string<Char, Traits, Alloc>& str) noexcept {
		return xieite::isxdigit(xieite::make_str_view(str));
	}

	template<xieite::is_char Char, std::size_t length>
	[[nodiscard]] constexpr bool isxdigit(const xieite::type<Char[length]>& str) noexcept {
		return xieite::isxdigit(xieite::make_str_view(str));
	}
}

#endif
