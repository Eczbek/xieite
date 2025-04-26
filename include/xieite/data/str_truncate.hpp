#ifndef DETAIL_XIEITE_HEADER_DATA_STR_TRUNCATE
#	define DETAIL_XIEITE_HEADER_DATA_STR_TRUNCATE
#
#	include <cstddef>
#	include <memory>
#	include <string>
#	include <type_traits>
#	include "../data/str_view.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<typename Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> str_truncate(const std::basic_string<Char, Traits, Alloc>& str, std::size_t target_length, std::type_identity_t<std::basic_string_view<Char, Traits>> sfx, const Alloc& alloc = {}) noexcept(false) {
		using Str = std::basic_string<Char, Traits, Alloc>;
		return (str.size() <= target_length)
			? str
			: (sfx.size() > target_length)
				? Str(sfx.substr(0, target_length), alloc)
				: (str.substr(0, target_length - sfx.size()) + Str(sfx, alloc));
	}

	template<typename Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr auto str_truncate(const std::basic_string<Char, Traits, Alloc>& str, std::size_t target_length, Char sfx, const Alloc& alloc = {})
		XIEITE_ARROW(xieite::str_truncate(str, target_length, xieite::str_view(sfx), alloc))

	template<typename Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr auto str_truncate(std::basic_string_view<Char, Traits> strv, std::size_t target_length, auto&& sfx, const Alloc& alloc = {})
		XIEITE_ARROW(xieite::str_truncate(std::basic_string<Char, Traits, Alloc>(strv, alloc), target_length, XIEITE_FWD(sfx), alloc))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>, std::size_t length>
	[[nodiscard]] constexpr auto str_truncate(const xieite::paren<Char[length]>& str, std::size_t target_length, auto&& sfx, const Alloc& alloc = {})
		XIEITE_ARROW(xieite::str_truncate(std::basic_string<Char, Traits, Alloc>(str, length, alloc), target_length, XIEITE_FWD(sfx), alloc))
}

#endif
