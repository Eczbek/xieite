#ifndef DETAIL_XIEITE_HEADER_DATA_STR_REPEAT
#	define DETAIL_XIEITE_HEADER_DATA_STR_REPEAT
#
#	include <cstddef>
#	include <memory>
#	include <string>
#	include <string_view>
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<typename Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> str_repeat(std::size_t count, const std::basic_string<Char, Traits, Alloc>& str, const Alloc& alloc = {}) noexcept {
		using Str = std::basic_string<Char, Traits, Alloc>;
		Str result = Str(alloc);
		result.reserve(str.size() * count);
		while (count--) {
			result += str;
		}
		return result;
	}

	template<typename Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr auto str_repeat(std::size_t count, std::basic_string_view<Char, Traits> strv, const Alloc& alloc = {})
		XIEITE_ARROW(xieite::str_repeat(count, std::basic_string<Char, Traits, Alloc>(strv, alloc), alloc))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>, std::size_t length>
	[[nodiscard]] constexpr auto str_repeat(std::size_t count, const xieite::paren<Char[length]>& str, const Alloc& alloc = {})
		XIEITE_ARROW(xieite::str_repeat(count, std::basic_string<Char, Traits, Alloc>(str, length, alloc), alloc))
}

#endif
