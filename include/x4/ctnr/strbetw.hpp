#pragma once

#include <cstddef>
#include <string>
#include <string_view>
#include "../ctnr/strafter.hpp"
#include "../ctnr/strbef.hpp"
#include "../ctnr/strv.hpp"
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"
#include "../trait/isch.hpp"

namespace x4 {
	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto strbetw(std::basic_string_view<Ch, Traits> strv, auto&& a, auto&& b)
		X4AR(x4::strafter(x4::strbef(strv, X4FWD(b)), X4FWD(a)))

	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto strbetw(const std::basic_string<Ch, Traits>& str, auto&& a, auto&& b)
		X4AR(x4::strbetw(x4::strv(str), X4FWD(a), X4FWD(b)))

	template<x4::isch Ch, typename Traits = std::char_traits<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto strbetw(const Ch(& str)[n], auto&& a, auto&& b)
		X4AR(x4::strbetw(x4::strv<Ch, Traits>(str), X4FWD(a), X4FWD(b)))
}
