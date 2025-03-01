#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <string_view>
#include "../ctnr/strrplc.hpp"
#include "../ctnr/strv.hpp"
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"
#include "../trait/isch.hpp"

namespace x4 {
	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> unquot(std::basic_string_view<Ch, Traits> strv, Ch delim = '"', Ch esc = '\\', Alloc&& alloc = {}) noexcept(false) {
		if (strv.size() < 2) {
			return "";
		}
		strv.remove_prefix(strv[0] == delim);
		strv.remove_suffix(strv.back() == delim);
		using Str = std::basic_string<Ch, Traits, Alloc>;
		return (delim == esc)
			? x4::strrplc(strv, Str(1, esc, alloc) + delim, delim, alloc)
			: x4::strrplc(x4::strrplc(strv, Str(2, esc, alloc), esc, alloc), Str(1, esc, alloc) + delim, delim, alloc);
	}

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto unquot(const std::basic_string<Ch, Traits, Alloc>& str, Ch delim = '"', Ch esc = '\\', Alloc&& alloc = {})
		X4AR(x4::unquot(x4::strv(str), delim, esc, X4FWD(alloc)))

	template<x4::isch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto unquot(const Ch(& str)[n], Ch delim = '"', Ch esc = '\\', Alloc&& alloc = {})
		X4AR(x4::unquot(x4::strv<Ch, Traits>(str), delim, esc, X4FWD(alloc)))
}
