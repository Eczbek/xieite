#pragma once

#include <cstddef>
#include <string>
#include <string_view>
#include "../ctnr/strv.hpp"
#include "../ctnr/strlen.hpp"
#include "../ctnr/substr.hpp"
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"
#include "../trait/isch.hpp"

namespace x4 {
	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto strafter(std::basic_string_view<Ch, Traits> strv, auto&& delim)
		X4AR(x4::substr(strv, strv.find(delim), std::string::npos, x4::strlen(delim)))

	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto strafter(const std::basic_string<Ch, Traits>& str, auto&& delim)
		X4AR(x4::strafter(x4::strv(str), X4FWD(delim)))

	template<x4::isch Ch, typename Traits = std::char_traits<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto strafter(const Ch(& str)[n], auto&& delim)
		X4AR(x4::strafter(x4::strv<Ch, Traits>(str), X4FWD(delim)))
}
