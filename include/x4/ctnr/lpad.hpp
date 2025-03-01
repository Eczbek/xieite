#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <string_view>
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"
#include "../trait/isch.hpp"

namespace x4 {
	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> lpad(const std::basic_string<Ch, Traits, Alloc>& str, std::size_t size, Ch c = ' ', Alloc&& alloc = {}) noexcept(false) {
		return (str.size() < size)
			? (std::basic_string<Ch, Traits, Alloc>(size - str.size(), c, X4FWD(alloc)) + str)
			: str;
	}

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto lpad(std::basic_string_view<Ch, Traits> strv, std::size_t size, Ch c = ' ', Alloc&& alloc = {})
		X4AR(x4::lpad(std::basic_string<Ch, Traits, Alloc>(strv, alloc), size, c, alloc))

	template<x4::isch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto lpad(const Ch(& str)[n], std::size_t size, Ch c = ' ', Alloc&& alloc = {})
		X4AR(x4::lpad(std::basic_string<Ch, Traits, Alloc>(str, n, alloc), size, c, alloc))
}
