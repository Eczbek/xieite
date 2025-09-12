#ifndef DETAIL_XIEITE_HEADER_DATA_PAD_BACK
#	define DETAIL_XIEITE_HEADER_DATA_PAD_BACK
#
#	include <cstddef>
#	include <memory>
#	include <string>
#	include <string_view>
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> pad_back(const std::basic_string<Char, Traits, Alloc>& str, std::size_t target_length, Char c = ' ', const Alloc& alloc = {}) noexcept(false) {
		return (str.size() < target_length)
			? (str + std::basic_string<Char, Traits, Alloc>(target_length - str.size(), c, alloc))
			: str;
	}

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr auto pad_back(std::basic_string_view<Char, Traits> strv, std::size_t target_length, Char c = ' ', const Alloc& alloc = {})
		XIEITE_ARROW(xieite::pad_back(std::basic_string<Char, Traits, Alloc>(strv, alloc), target_length, c, alloc))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>, std::size_t length>
	[[nodiscard]] constexpr auto pad_back(const xieite::paren<Char[length]>& str, std::size_t target_length, Char c = ' ', const Alloc& alloc = {})
		XIEITE_ARROW(xieite::pad_back(std::basic_string<Char, Traits, Alloc>(str, length, alloc), target_length, c, alloc))
}

#endif
