#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <string_view>
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"
#include "../trait/is_ch.hpp"

namespace xieite {
	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_repeat(std::size_t n, const std::basic_string<Ch, Traits, Alloc>& str, Alloc&& alloc = {}) noexcept {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		Str result = Str(XIEITE_FWD(alloc));
		result.reserve(str.size() * n);
		while (n--) {
			result += str;
		}
		return result;
	}

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto str_repeat(std::size_t n, std::basic_string_view<Ch, Traits> strv, Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_repeat(n, std::basic_string<Ch, Traits, Alloc>(strv, alloc), alloc))

	template<xieite::is_ch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t m>
	[[nodiscard]] constexpr auto str_repeat(std::size_t n, const Ch(& str)[m], Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_repeat(n, std::basic_string<Ch, Traits, Alloc>(str, m, alloc), alloc))
}
