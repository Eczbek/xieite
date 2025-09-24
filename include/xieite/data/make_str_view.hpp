#ifndef DETAIL_XIEITE_HEADER_DATA_MAKE_STR_VIEW
#	define DETAIL_XIEITE_HEADER_DATA_MAKE_STR_VIEW
#
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../meta/type.hpp"
#	include "../trait/is_char.hpp"
#	include "../trait/rm_ref.hpp"

namespace xieite {
	template<xieite::is_char Char, typename Traits>
	[[nodiscard]] constexpr std::basic_string_view<Char, Traits> make_str_view(std::basic_string_view<Char, Traits> strv) noexcept {
		return strv;
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr std::basic_string_view<Char, Traits> make_str_view(const std::basic_string<Char, Traits, Alloc>& str) noexcept {
		return std::basic_string_view<Char, Traits>(str);
	}

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>>
	[[nodiscard]] constexpr std::basic_string_view<Char, Traits> make_str_view(const Char* str, std::size_t length) noexcept {
		return std::basic_string_view<Char, Traits>(str, length - (length && !str[length - 1]));
	}

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, std::size_t length>
	[[nodiscard]] constexpr std::basic_string_view<Char, Traits> make_str_view(const xieite::type<Char[length]>& str) noexcept {
		return xieite::make_str_view<Char, Traits>(*&str, length);
	}

	template<typename Char, typename Traits = std::char_traits<xieite::rm_ref<Char>>>
	requires(xieite::is_char<xieite::rm_ref<Char>>)
	[[nodiscard]] constexpr std::basic_string_view<xieite::rm_ref<Char>, Traits> make_str_view(Char&& c = {}) noexcept {
		return std::basic_string_view<xieite::rm_ref<Char>, Traits>(&c, 1);
	}
}

#endif
