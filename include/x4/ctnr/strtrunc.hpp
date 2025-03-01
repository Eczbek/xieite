#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <type_traits>
#include "../ctnr/strv.hpp"
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"
#include "../trait/isch.hpp"

namespace x4 {
	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> strtrunc(const std::basic_string<Ch, Traits, Alloc>& str, std::size_t size, std::type_identity_t<std::basic_string_view<Ch, Traits>> sfx, Alloc&& alloc = {}) noexcept(false) {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		return (str.size() <= size)
			? str
			: (sfx.size() > size)
				? Str(sfx.substr(0, size), X4FWD(alloc))
				: (str.substr(0, size - sfx.size()) + Str(sfx, X4FWD(alloc)));
	}

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto strtrunc(const std::basic_string<Ch, Traits, Alloc>& str, std::size_t size, Ch sfx, Alloc&& alloc = {})
		X4AR(x4::strtrunc(str, size, x4::strv(sfx), X4FWD(alloc)))

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto strtrunc(std::basic_string_view<Ch, Traits> strv, std::size_t size, auto&& sfx, Alloc&& alloc = {})
		X4AR(x4::strtrunc(std::basic_string<Ch, Traits, Alloc>(strv, alloc), size, X4FWD(sfx), alloc))

	template<x4::isch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto strtrunc(const Ch(& str)[n], std::size_t size, auto&& sfx, Alloc&& alloc = {})
		X4AR(x4::strtrunc(std::basic_string<Ch, Traits, Alloc>(str, n, alloc), size, X4FWD(sfx), alloc))
}
