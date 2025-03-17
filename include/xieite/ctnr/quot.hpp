#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <string_view>
#include "../ctnr/str_replace.hpp"
#include "../meta/group.hpp"
#include "../pp/arrow.hpp"
#include "../trait/is_ch.hpp"

namespace xieite {
	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> quot(const std::basic_string<Ch, Traits, Alloc>& str, Ch delim = '"', Ch esc = '\\', Alloc&& alloc = {}) noexcept(false) {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		return (delim == esc)
			? (delim + xieite::str_replace(str, delim, Str(1, esc, alloc) + delim, alloc) + delim, alloc)
			: (delim + xieite::str_replace(xieite::str_replace(str, esc, Str(2, esc, alloc), alloc), delim, Str(1, esc, alloc) + delim, alloc) + delim);
	}

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto quot(std::basic_string_view<Ch, Traits> strv, Ch delim = '"', Ch esc = '\\', Alloc&& alloc = {})
		XIEITE_ARROW(xieite::quot(std::basic_string<Ch, Traits, Alloc>(strv, alloc), delim, esc, alloc))

	template<xieite::is_ch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto pad(const xieite::group<Ch[n]>& str, Ch delim = '"', Ch esc = '\\', Alloc&& alloc = {})
		XIEITE_ARROW(xieite::quot(std::basic_string<Ch, Traits, Alloc>(str, n, alloc), delim, esc, alloc))
}
