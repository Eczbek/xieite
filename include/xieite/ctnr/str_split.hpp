#ifndef DETAIL_XIEITE_HEADER_CTNR_STR_SPLIT
#	define DETAIL_XIEITE_HEADER_CTNR_STR_SPLIT
#
#	include <cstddef>
#	include <memory>
#	include <string>
#	include <string_view>
#	include <type_traits>
#	include <vector>
#	include "../ctnr/str_view.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_ch.hpp"

namespace xieite {
	template<typename Ch, typename Traits = std::char_traits<Ch>, typename VecAlloc = std::allocator<std::basic_string_view<Ch, Traits>>>
	[[nodiscard]] constexpr std::vector<std::basic_string_view<Ch, Traits>, VecAlloc> str_split(std::basic_string_view<Ch, Traits> strv, std::type_identity_t<std::basic_string_view<Ch, Traits>> delim, bool discard_empty = false, VecAlloc&& vec_alloc = {}) noexcept(false) {
		auto result = std::vector<std::basic_string_view<Ch, Traits>, VecAlloc>(XIEITE_FWD(vec_alloc));
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

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename VecAlloc = std::allocator<std::basic_string_view<Ch, Traits>>>
	[[nodiscard]] constexpr auto str_split(std::basic_string_view<Ch, Traits> strv, Ch delim, bool discard_empty = false, VecAlloc&& vec_alloc = {})
		XIEITE_ARROW(xieite::str_split(strv, xieite::str_view(delim), discard_empty, XIEITE_FWD(vec_alloc)))

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename VecAlloc = std::allocator<std::basic_string_view<Ch, Traits>>>
	[[nodiscard]] constexpr auto str_split(const std::basic_string<Ch, Traits>& str, auto&& delim, bool discard_empty = false, VecAlloc&& vec_alloc = {})
		XIEITE_ARROW(xieite::str_split(xieite::str_view(str), XIEITE_FWD(delim), discard_empty, XIEITE_FWD(vec_alloc)))

	template<xieite::is_ch Ch, typename Traits = std::char_traits<Ch>, typename VecAlloc = std::allocator<std::basic_string_view<Ch, Traits>>, std::size_t n>
	[[nodiscard]] constexpr auto str_split(const xieite::paren<Ch[n]>& str, auto&& delim, bool discard_empty = false, VecAlloc&& vec_alloc = {})
		XIEITE_ARROW(xieite::str_split(xieite::str_view<Ch, Traits>(str), XIEITE_FWD(delim), discard_empty, XIEITE_FWD(vec_alloc)))
}

#endif
