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
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> strrpt(std::size_t n, const std::basic_string<Ch, Traits, Alloc>& str, Alloc&& alloc = {}) noexcept {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		Str result = Str(X4FWD(alloc));
		result.reserve(str.size() * n);
		while (n--) {
			result += str;
		}
		return result;
	}

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto strrpt(std::size_t n, std::basic_string_view<Ch, Traits> strv, Alloc&& alloc = {})
		X4AR(x4::strrpt(n, std::basic_string<Ch, Traits, Alloc>(strv, alloc), alloc))

	template<x4::isch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t m>
	[[nodiscard]] constexpr auto strrpt(std::size_t n, const Ch(& str)[m], Alloc&& alloc = {})
		X4AR(x4::strrpt(n, std::basic_string<Ch, Traits, Alloc>(str, m, alloc), alloc))
}
