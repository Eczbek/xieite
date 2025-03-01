#pragma once

#include <cstddef>
#include <string>
#include <string_view>
#include "../pp/ar.hpp"
#include "../trait/isch.hpp"

namespace x4 {
	template<typename Ch>
	[[nodiscard]] constexpr auto strv(std::basic_string_view<Ch> strv)
		X4AR(strv)

	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto strv(const std::basic_string<Ch, Traits>& str)
		X4AR(std::basic_string_view<Ch, Traits>(str))

	template<x4::isch Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto strv(const Ch* str, std::size_t n)
		X4AR(std::basic_string_view<Ch, Traits>(str, n))

	template<x4::isch Ch, typename Traits = std::char_traits<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto strv(const Ch(& str)[n])
		X4AR(std::basic_string_view<Ch, Traits>(str, n))

	template<x4::isch Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto strv(Ch&& c = {})
		X4AR(std::basic_string_view<Ch, Traits>(&c, 1))
}
