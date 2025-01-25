#pragma once

#include <memory>
#include <string>
#include "../ctnr/str_replace.hpp"
#include "../ctnr/substr.hpp"

namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> unquot(std::basic_string_view<Ch, Traits> strv, Ch delim = '"', Ch esc = '\\') noexcept {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		strv.remove_prefix(strv[0] == delim);
		strv.remove_suffix(strv.back() == delim);
		return (delim == esc)
			? xieite::str_replace(strv, Str(1, esc) + delim, delim)
			: xieite::str_replace(xieite::str_replace(strv, Str(2, esc), esc), Str(1, esc) + delim, delim);
	}
}
