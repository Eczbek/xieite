#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <string_view>
#include "../ctnr/strrplc.hpp"
#include "../pp/ar.hpp"
#include "../trait/isch.hpp"

namespace x4 {
	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> quot(const std::basic_string<Ch, Traits, Alloc>& str, Ch delim = '"', Ch esc = '\\', Alloc&& alloc = {}) noexcept(false) {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		return (delim == esc)
			? (delim + x4::strrplc(str, delim, Str(1, esc, alloc) + delim, alloc) + delim, alloc)
			: (delim + x4::strrplc(x4::strrplc(str, esc, Str(2, esc, alloc), alloc), delim, Str(1, esc, alloc) + delim, alloc) + delim);
	}

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto quot(std::basic_string_view<Ch, Traits> strv, Ch delim = '"', Ch esc = '\\', Alloc&& alloc = {})
		X4AR(x4::quot(std::basic_string<Ch, Traits, Alloc>(strv, alloc), delim, esc, alloc))

	template<x4::isch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto pad(const Ch(& str)[n], Ch delim = '"', Ch esc = '\\', Alloc&& alloc = {})
		X4AR(x4::quot(std::basic_string<Ch, Traits, Alloc>(str, n, alloc), delim, esc, alloc))
}
