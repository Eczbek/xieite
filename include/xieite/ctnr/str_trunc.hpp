#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <type_traits>
#include "../ctnr/str_view.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"
#include "../trait/is_ch.hpp"

namespace xieite {
	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_trunc(const std::basic_string<Ch, Traits, Alloc>& str, std::size_t size, std::type_identity_t<std::basic_string_view<Ch, Traits>> sfx, Alloc&& alloc = {}) noexcept(false) {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		return (str.size() <= size)
			? str
			: (sfx.size() > size)
				? Str(sfx.substr(0, size), XIEITE_FWD(alloc))
				: (str.substr(0, size - sfx.size()) + Str(sfx, XIEITE_FWD(alloc)));
	}

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto str_trunc(const std::basic_string<Ch, Traits, Alloc>& str, std::size_t size, Ch sfx, Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_trunc(str, size, xieite::str_view(sfx), XIEITE_FWD(alloc)))

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto str_trunc(std::basic_string_view<Ch, Traits> strv, std::size_t size, auto&& sfx, Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_trunc(std::basic_string<Ch, Traits, Alloc>(strv, alloc), size, XIEITE_FWD(sfx), alloc))

	template<xieite::is_ch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto str_trunc(const Ch(& str)[n], std::size_t size, auto&& sfx, Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_trunc(std::basic_string<Ch, Traits, Alloc>(str, n, alloc), size, XIEITE_FWD(sfx), alloc))
}
