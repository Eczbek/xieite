#ifndef DETAIL_XIEITE_HEADER_DATA_STRLEN
#	define DETAIL_XIEITE_HEADER_DATA_STRLEN
#
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include <type_traits>
#	include "../meta/paren.hpp"
#	include "../trait/is_char.hpp"
#	include "../trait/is_ptr.hpp"

namespace xieite {
	template<typename Char>
	[[nodiscard]] constexpr std::size_t strlen(std::basic_string_view<Char> strv) noexcept {
		return strv.size();
	}

	template<typename Char>
	[[nodiscard]] constexpr std::size_t strlen(const std::basic_string<Char>& str) noexcept {
		return str.size();
	}

	template<xieite::is_char Char, std::size_t length>
	[[nodiscard]] constexpr std::size_t strlen(const xieite::paren<Char[length]>&) noexcept {
		return length - !!length;
	}

	template<typename Str>
	requires(xieite::is_ptr<Str> && xieite::is_char<std::remove_pointer_t<Str>>)
	[[nodiscard]] constexpr std::size_t strlen(Str str) noexcept {
		std::size_t i = 0;
		while (str && str[i]) {
			++i;
		}
		return i;
	}

	template<xieite::is_char Char>
	[[nodiscard]] constexpr std::size_t strlen(Char) noexcept {
		return 1;
	}
}

#endif
