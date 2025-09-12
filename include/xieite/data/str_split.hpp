#ifndef DETAIL_XIEITE_HEADER_DATA_STR_SPLIT
#	define DETAIL_XIEITE_HEADER_DATA_STR_SPLIT
#
#	include <cstddef>
#	include <memory>
#	include <string>
#	include <string_view>
#	include <type_traits>
#	include <vector>
#	include "../data/make_str_view.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, typename VecAlloc = std::allocator<std::basic_string_view<Char, Traits>>>
	[[nodiscard]] constexpr std::vector<std::basic_string_view<Char, Traits>, VecAlloc> str_split(std::basic_string_view<Char, Traits> strv, std::type_identity_t<std::basic_string_view<Char, Traits>> delim, bool discard_empty = false, const VecAlloc& vec_alloc = {}) noexcept(false) {
		auto result = std::vector<std::basic_string_view<Char, Traits>, VecAlloc>(XIEITE_FWD(vec_alloc));
		std::size_t i = 0;
		while (true) {
			const std::size_t j = strv.find(delim, i);
			if (j == std::string::npos) {
				break;
			}
			if (!discard_empty || (j - i)) {
				result.push_back(strv.substr(i, j - i));
			}
			i = j + delim.size();
		}
		if (!discard_empty || (strv.size() - i)) {
			result.push_back(strv.substr(i));
		}
		return result;
	}

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, typename VecAlloc = std::allocator<std::basic_string_view<Char, Traits>>>
	[[nodiscard]] constexpr auto str_split(std::basic_string_view<Char, Traits> strv, Char delim, bool discard_empty = false, const VecAlloc& vec_alloc = {})
		XIEITE_ARROW(xieite::str_split(strv, xieite::make_str_view(delim), discard_empty, XIEITE_FWD(vec_alloc)))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, typename VecAlloc = std::allocator<std::basic_string_view<Char, Traits>>>
	[[nodiscard]] constexpr auto str_split(const std::basic_string<Char, Traits>& str, auto&& delim, bool discard_empty = false, const VecAlloc& vec_alloc = {})
		XIEITE_ARROW(xieite::str_split(xieite::make_str_view(str), XIEITE_FWD(delim), discard_empty, XIEITE_FWD(vec_alloc)))

	template<xieite::is_char Char, typename Traits = std::char_traits<Char>, typename VecAlloc = std::allocator<std::basic_string_view<Char, Traits>>, std::size_t length>
	[[nodiscard]] constexpr auto str_split(const xieite::paren<Char[length]>& str, auto&& delim, bool discard_empty = false, const VecAlloc& vec_alloc = {})
		XIEITE_ARROW(xieite::str_split(xieite::make_str_view<Char, Traits>(str), XIEITE_FWD(delim), discard_empty, XIEITE_FWD(vec_alloc)))
}

#endif
