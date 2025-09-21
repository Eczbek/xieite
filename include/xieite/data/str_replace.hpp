#ifndef DETAIL_XIEITE_HEADER_DATA_STR_REPLACE
#	define DETAIL_XIEITE_HEADER_DATA_STR_REPLACE
#
#	include <cstddef>
#	include <memory>
#	include <string>
#	include <string_view>
#	include <type_traits>
#	include "../data/make_str_view.hpp"
#	include "../meta/type.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<xieite::is_char Char, typename Traits, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> str_replace(std::basic_string_view<Char, Traits> strv, std::type_identity_t<std::basic_string_view<Char, Traits>> orig, std::type_identity_t<std::basic_string_view<Char, Traits>> with, const Alloc& alloc = {}) noexcept(false) {
		auto result = std::basic_string<Char, Traits, Alloc>(strv, alloc);
		std::size_t i = 0;
		while (true) {
			i = result.find(orig, i);
			if (i == std::string::npos) {
				break;
			}
			result.replace(i, orig.size(), with);
			++i;
		}
		return result;
	}

	template<xieite::is_char Char, typename Traits, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> str_replace(std::basic_string_view<Char, Traits> strv, Char orig, std::type_identity_t<std::basic_string_view<Char, Traits>> with, const Alloc& alloc = {}) noexcept(false) {
		return xieite::str_replace(strv, xieite::make_str_view(orig), with, alloc);
	}

	template<xieite::is_char Char, typename Traits, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> str_replace(std::basic_string_view<Char, Traits> strv, std::type_identity_t<std::basic_string_view<Char, Traits>> orig, Char with, const Alloc& alloc = {}) noexcept(false) {
		return xieite::str_replace(strv, orig, xieite::make_str_view(with), alloc);
	}

	template<xieite::is_char Char, typename Traits, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> str_replace(std::basic_string_view<Char, Traits> strv, Char orig, Char with, const Alloc& alloc = {}) noexcept(false) {
		return xieite::str_replace(strv, xieite::make_str_view(orig), xieite::make_str_view(with), alloc);
	}

	template<xieite::is_char Char, typename Traits, typename Alloc>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> str_replace(const std::basic_string<Char, Traits, Alloc>& str, auto&& orig, auto&& with, const Alloc& alloc = {}) noexcept(false) {
		return xieite::str_replace(xieite::make_str_view(str), XIEITE_FWD(orig), XIEITE_FWD(with), alloc);
	}

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>, std::size_t length>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> str_replace(const xieite::type<Char[length]>& str, auto&& orig, auto&& with, const Alloc& alloc = {}) noexcept(false) {
		return xieite::str_replace(xieite::make_str_view<Char, Traits>(str), XIEITE_FWD(orig), XIEITE_FWD(with), alloc);
	}
}

#endif
