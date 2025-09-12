#ifndef DETAIL_XIEITE_HEADER_DATA_PAD
#	define DETAIL_XIEITE_HEADER_DATA_PAD
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
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> pad(const std::basic_string<Char, Traits, Alloc>& str, std::size_t target_length, Char c = ' ', bool align_front = true, const Alloc& alloc = {}) noexcept(false) {
		using Str = std::basic_string<Char, Traits, Alloc>;
		return (str.size() < target_length)
			? Str((target_length - str.size() + !align_front) / 2, c, alloc) + str + Str((target_length - str.size() + align_front) / 2, c, alloc)
			: str;
	}

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr auto pad(std::basic_string_view<Char, Traits> strv, std::size_t target_length, Char c = ' ', bool align_front = true, const Alloc& alloc = {})
		XIEITE_ARROW(xieite::pad(std::basic_string<Char, Traits, Alloc>(strv, alloc), target_length, c, align_front, alloc))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>, std::size_t length>
	[[nodiscard]] constexpr auto pad(const xieite::paren<Char[length]>& str, std::size_t target_length, Char c = ' ', bool align_front = true, const Alloc& alloc = {})
		XIEITE_ARROW(xieite::pad(std::basic_string<Char, Traits, Alloc>(str, length, alloc), target_length, c, align_front, alloc))
}

#endif
