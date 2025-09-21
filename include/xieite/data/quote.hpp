#ifndef DETAIL_XIEITE_HEADER_DATA_QUOTE
#	define DETAIL_XIEITE_HEADER_DATA_QUOTE
#
#	include <cstddef>
#	include <memory>
#	include <string>
#	include <string_view>
#	include "../data/str_replace.hpp"
#	include "../meta/type.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> quote(const std::basic_string<Char, Traits, Alloc>& str, Char delim = '"', Char esc = '\\', const Alloc& alloc = {}) noexcept(false) {
		using Str = std::basic_string<Char, Traits, Alloc>;
		return (delim == esc)
			? (delim + xieite::str_replace(str, delim, Str(1, esc, alloc) + delim, alloc) + delim, alloc)
			: (delim + xieite::str_replace(xieite::str_replace(str, esc, Str(2, esc, alloc), alloc), delim, Str(1, esc, alloc) + delim, alloc) + delim);
	}

	template<xieite::is_char Char, typename Traits, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> quote(std::basic_string_view<Char, Traits> strv, Char delim = '"', Char esc = '\\', const Alloc& alloc = {}) noexcept(false) {
		return xieite::quote(std::basic_string<Char, Traits, Alloc>(strv, alloc), delim, esc, alloc);
	}

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>, std::size_t length>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> pad(const xieite::type<Char[length]>& str, Char delim = '"', Char esc = '\\', const Alloc& alloc = {}) noexcept(false) {
		return xieite::quote(std::basic_string<Char, Traits, Alloc>(str, length, alloc), delim, esc, alloc);
	}
}

#endif
