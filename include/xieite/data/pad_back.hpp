#ifndef DETAIL_XIEITE_HEADER_DATA_PAD_BACK
#	define DETAIL_XIEITE_HEADER_DATA_PAD_BACK
#
#	include <cstddef>
#	include <memory>
#	include <string>
#	include <string_view>
#	include "../meta/type.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<
		xieite::is_char Char,
		typename Traits,
		typename Alloc
	> [[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> pad_back(
		const std::basic_string<Char, Traits, Alloc>& str,
		std::size_t target_length,
		Char c = ' ',
		const Alloc& alloc = {}
	) noexcept(false) {
		using String = std::basic_string<Char, Traits, Alloc>;
		return (str.size() < target_length)
			? (str + String(target_length - str.size(), c, alloc))
			: str;
	}

	template<
		xieite::is_char Char,
		typename Traits,
		typename Alloc = std::allocator<Char>
	> [[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> pad_back(
		std::basic_string_view<Char, Traits> strv,
		std::size_t target_length,
		Char c = ' ',
		const Alloc& alloc = {}
	) noexcept(false) {
		using String = std::basic_string<Char, Traits, Alloc>;
		return xieite::pad_back(String(strv, alloc), target_length, c, alloc);
	}

	template<
		xieite::is_char Char,
		typename Traits = std::char_traits<Char>,
		typename Alloc = std::allocator<Char>,
		std::size_t length
	> [[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> pad_back(
		const xieite::type<Char[length]>& str,
		std::size_t target_length,
		Char c = ' ',
		const Alloc& alloc = {}
	) noexcept(false) {
		using String = std::basic_string<Char, Traits, Alloc>;
		return xieite::pad_back(
			String(str, length, alloc), target_length, c, alloc
		);
	}
}

#endif
