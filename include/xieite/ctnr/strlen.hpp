#ifndef DETAIL_XIEITE_HEADER_CTNR_STRLEN
#	define DETAIL_XIEITE_HEADER_CTNR_STRLEN
#
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include <type_traits>
#	include "../meta/group.hpp"
#	include "../trait/is_ch.hpp"

namespace xieite {
	template<typename Ch>
	[[nodiscard]] constexpr std::size_t strlen(std::basic_string_view<Ch> strv) noexcept {
		return strv.size();
	}

	template<typename Ch>
	[[nodiscard]] constexpr std::size_t strlen(const std::basic_string<Ch>& str) noexcept {
		return str.size();
	}

	template<xieite::is_ch Ch, std::size_t n>
	[[nodiscard]] constexpr std::size_t strlen(const xieite::group<Ch[n]>&) noexcept {
		return n - !!n;
	}

	template<typename Str>
	requires(xieite::is_ch<std::remove_pointer_t<Str>>)
	[[nodiscard]] constexpr std::size_t strlen(Str str) noexcept {
		std::size_t i = 0;
		while (str && str[i]) {
			++i;
		}
		return i;
	}

	template<xieite::is_ch Ch>
	[[nodiscard]] constexpr std::size_t strlen(Ch) noexcept {
		return 1;
	}
}

#endif
