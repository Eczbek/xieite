#ifndef DETAIL_XIEITE_HEADER_DATA_UNQUOTE
#	define DETAIL_XIEITE_HEADER_DATA_UNQUOTE
#
#	include <cstddef>
#	include <memory>
#	include <string>
#	include <string_view>
#	include "../data/str_replace.hpp"
#	include "../data/str_view.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<typename Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> unquote(std::basic_string_view<Char, Traits> strv, Char delim = '"', Char esc = '\\', const Alloc& alloc = {}) noexcept(false) {
		if (strv.size() < 2) {
			return "";
		}
		strv.remove_prefix(strv[0] == delim);
		strv.remove_suffix(strv.back() == delim);
		using Str = std::basic_string<Char, Traits, Alloc>;
		return (delim == esc)
			? xieite::str_replace(strv, Str(1, esc, alloc) + delim, delim, alloc)
			: xieite::str_replace(xieite::str_replace(strv, Str(2, esc, alloc), esc, alloc), Str(1, esc, alloc) + delim, delim, alloc);
	}

	template<typename Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr auto unquote(const std::basic_string<Char, Traits, Alloc>& str, Char delim = '"', Char esc = '\\', const Alloc& alloc = {})
		XIEITE_ARROW(xieite::unquote(xieite::str_view(str), delim, esc, alloc))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>, std::size_t length>
	[[nodiscard]] constexpr auto unquote(const xieite::paren<Char[length]>& str, Char delim = '"', Char esc = '\\', const Alloc& alloc = {})
		XIEITE_ARROW(xieite::unquote(xieite::str_view<Char, Traits>(str), delim, esc, alloc))
}

#endif
