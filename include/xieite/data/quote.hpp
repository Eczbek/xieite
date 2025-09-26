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
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> quote(
		const std::basic_string<Char, Traits, Alloc>& str,
		Char delim = '"',
		Char esc = '\\',
		const Alloc& alloc = {}
	) noexcept(false) {
		using String = std::basic_string<Char, Traits, Alloc>;
		const auto& esc_del = String(1, esc, alloc) + delim;
		if (delim == esc) {
			// TODO(Hurubon): Better naming.
			const auto& out = xieite::str_replace(str, delim, esc_del, alloc);
			return delim + out + delim;
		}
		else {
			// TODO(Hurubon): Better naming.
			const auto& esc_esc = String(2, esc, alloc);
			const auto& inn = xieite::str_replace(str, esc  , esc_esc, alloc);
			const auto& out = xieite::str_replace(inn, delim, esc_del, alloc);
			return delim + out + delim;
		}
	}

	template<
		xieite::is_char Char,
		typename Traits,
		typename Alloc = std::allocator<Char>
	> [[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> quote(
		std::basic_string_view<Char, Traits> strv,
		Char delim = '"',
		Char esc = '\\',
		const Alloc& alloc = {}
	) noexcept(false) {
		using String = std::basic_string<Char, Traits, Alloc>;
		return xieite::quote(String(strv, alloc), delim, esc, alloc);
	}

	template<
		xieite::is_char Char,
		typename Traits = std::char_traits<Char>,
		typename Alloc = std::allocator<Char>,
		std::size_t length
	> [[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> pad(
		const xieite::type<Char[length]>& str,
		Char delim = '"',
		Char esc = '\\',
		const Alloc& alloc = {}
	) noexcept(false) {
		using String = std::basic_string<Char, Traits, Alloc>;
		return xieite::quote(String(str, length, alloc), delim, esc, alloc);
	}
}

#endif
