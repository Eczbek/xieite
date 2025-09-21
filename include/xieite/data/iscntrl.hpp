#ifndef DETAIL_XIEITE_HEADER_DATA_ISCNTRL
#	define DETAIL_XIEITE_HEADER_DATA_ISCNTRL
#
#	include <string>
#	include <string_view>
#	include "../data/isprint.hpp"
#	include "../data/make_str_view.hpp"
#	include "../meta/type.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	[[nodiscard]] constexpr bool iscntrl(xieite::is_char auto c) noexcept {
		return !xieite::isprint(c);
	}

	template<xieite::is_char Char, typename Traits>
	[[nodiscard]] constexpr bool iscntrl(std::basic_string_view<Char, Traits> strv) noexcept {
		for (Char c : strv) {
			if (!xieite::iscntrl(c)) {
				return false;
			}
		}
		return true;
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr bool iscntrl(const std::basic_string<Char, Traits, Alloc>& str) {
		return xieite::iscntrl(xieite::make_str_view(str));
	}

	template<xieite::is_char Char, std::size_t length>
	[[nodiscard]] constexpr bool iscntrl(const xieite::type<Char[length]>& str) {
		return xieite::iscntrl(xieite::make_str_view(str));
	}
}

#endif
