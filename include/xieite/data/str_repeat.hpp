#ifndef DETAIL_XIEITE_HEADER_DATA_STR_REPEAT
#	define DETAIL_XIEITE_HEADER_DATA_STR_REPEAT
#
#	include <cstddef>
#	include <memory>
#	include <string>
#	include <string_view>
#	include "../meta/type.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> str_repeat(
		std::size_t count,
		const std::basic_string<Char, Traits, Alloc>& str,
		const Alloc& alloc = {}
	) noexcept(false) {
		using String = std::basic_string<Char, Traits, Alloc>;
		auto result = String(alloc);
		result.reserve(str.size() * count);
		while (count--) {
			result += str;
		}
		return result;
	}

	template<
		xieite::is_char Char,
		typename Traits,
		typename Alloc = std::allocator<Char>
	> [[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> str_repeat(
		std::size_t count,
		std::basic_string_view<Char, Traits> strv,
		const Alloc& alloc = {}
	) noexcept(false) {
		using String = std::basic_string<Char, Traits, Alloc>;
		return xieite::str_repeat(count, String(strv, alloc), alloc);
	}

	template<
		xieite::is_char Char,
		typename Traits = std::char_traits<Char>,
		typename Alloc = std::allocator<Char>,
		std::size_t length
	> [[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> str_repeat(
		std::size_t count,
		const xieite::type<Char[length]>& str,
		const Alloc& alloc = {}
	) noexcept(false) {
		using String = std::basic_string<Char, Traits, Alloc>;
		return xieite::str_repeat(count, String(str, length, alloc), alloc);
	}
}

#endif
