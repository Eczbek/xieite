#pragma once

#include <cstddef>
#include <string>
#include <string_view>
#include "../ctnr/strv.hpp"
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"
#include "../trait/isch.hpp"

namespace x4 {
	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto strbef(std::basic_string_view<Ch, Traits> strv, auto&& delim)
		X4AR(strv.substr(0, strv.find(X4FWD(delim))))

	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto strbef(const std::basic_string<Ch, Traits>& str, auto&& delim)
		X4AR(x4::strbef(x4::strv(str), X4FWD(delim)))

	template<x4::isch Ch, typename Traits = std::char_traits<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto strbef(const Ch(& str)[n], auto&& delim)
		X4AR(x4::strbef(x4::strv<Ch, Traits>(str), X4FWD(delim)))
}
