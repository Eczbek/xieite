#pragma once

#include <cstddef>
#include <string>
#include <string_view>
#include "../ctnr/strv.hpp"
#include "../pp/ar.hpp"
#include "../trait/isch.hpp"

namespace x4 {
	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> substr(std::basic_string_view<Ch, Traits> strv, std::size_t start, std::size_t end = std::string::npos, std::size_t start_offset = 0, std::size_t end_offset = 0) noexcept {
		if (start == std::string::npos) {
			return "";
		}
		if (end == std::string::npos) {
			return strv.substr(start + start_offset);
		}
		return strv.substr(start + start_offset, end - start + end_offset);
	}

	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto substr(const std::basic_string<Ch, Traits>& str, std::size_t start, std::size_t end = std::string::npos, std::size_t start_offset = 0, std::size_t end_offset = 0)
		X4AR(x4::substr(x4::strv(str), start, end, start_offset, end_offset))

	template<x4::isch Ch, typename Traits = std::char_traits<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto substr(const Ch(& str)[n], std::size_t start, std::size_t end = std::string::npos, std::size_t start_offset = 0, std::size_t end_offset = 0)
		X4AR(x4::substr(x4::strv<Ch, Traits>(str), start, end, start_offset, end_offset))
}
