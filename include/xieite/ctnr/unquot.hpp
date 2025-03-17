#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <string_view>
#include "../ctnr/str_replace.hpp"
#include "../ctnr/str_view.hpp"
#include "../meta/group.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"
#include "../trait/is_ch.hpp"

namespace xieite {
	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> unquot(std::basic_string_view<Ch, Traits> strv, Ch delim = '"', Ch esc = '\\', Alloc&& alloc = {}) noexcept(false) {
		if (strv.size() < 2) {
			return "";
		}
		strv.remove_prefix(strv[0] == delim);
		strv.remove_suffix(strv.back() == delim);
		using Str = std::basic_string<Ch, Traits, Alloc>;
		return (delim == esc)
			? xieite::str_replace(strv, Str(1, esc, alloc) + delim, delim, alloc)
			: xieite::str_replace(xieite::str_replace(strv, Str(2, esc, alloc), esc, alloc), Str(1, esc, alloc) + delim, delim, alloc);
	}

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto unquot(const std::basic_string<Ch, Traits, Alloc>& str, Ch delim = '"', Ch esc = '\\', Alloc&& alloc = {})
		XIEITE_ARROW(xieite::unquot(xieite::str_view(str), delim, esc, XIEITE_FWD(alloc)))

	template<xieite::is_ch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto unquot(const xieite::group<Ch[n]>& str, Ch delim = '"', Ch esc = '\\', Alloc&& alloc = {})
		XIEITE_ARROW(xieite::unquot(xieite::str_view<Ch, Traits>(str), delim, esc, XIEITE_FWD(alloc)))
}
