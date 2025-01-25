#pragma once

#include <cstddef>
#include <memory>
#include <string>

namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> pad_front(const std::basic_string<Ch, Traits, Alloc>& str, std::size_t size, Ch c = ' ') noexcept {
		return (str.size() < size)
			? (std::basic_string<Ch, Traits, Alloc>(size - str.size(), c) + str)
			: str;
	}

	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> pad_front(std::basic_string_view<Ch, Traits> strv, std::size_t size, Ch c = ' ') noexcept {
		return xieite::pad_front(std::basic_string<Ch, Traits, Alloc>(strv), size, c);
	}
}
