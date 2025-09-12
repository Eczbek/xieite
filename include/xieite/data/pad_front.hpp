#ifndef DETAIL_XIEITE_HEADER_DATA_PAD_FRONT
#	define DETAIL_XIEITE_HEADER_DATA_PAD_FRONT
#
#	include <cstddef>
#	include <memory>
#	include <string>
#	include <string_view>
#	include "../meta/paren.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> pad_front(const std::basic_string<Char, Traits, Alloc>& str, std::size_t target_length, Char c = ' ', const Alloc& alloc = {}) noexcept(false) {
		return (str.size() < target_length)
			? (std::basic_string<Char, Traits, Alloc>(target_length - str.size(), c, alloc) + str)
			: str;
	}

	template<xieite::is_char Char, typename Traits, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> pad_front(std::basic_string_view<Char, Traits> strv, std::size_t target_length, Char c = ' ', const Alloc& alloc = {}) noexcept(false) {
		return xieite::pad_front(std::basic_string<Char, Traits, Alloc>(strv, alloc), target_length, c, alloc);
	}

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>, std::size_t length>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> pad_front(const xieite::paren<Char[length]>& str, std::size_t target_length, Char c = ' ', const Alloc& alloc = {}) noexcept(false) {
		return xieite::pad_front(std::basic_string<Char, Traits, Alloc>(str, length, alloc), target_length, c, alloc);
	}
}

#endif
