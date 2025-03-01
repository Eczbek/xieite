#pragma once

#include <cstddef>
#include <string>
#include <string_view>
#include "../ctnr/strv.hpp"
#include "../ctnr/substr.hpp"
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"
#include "../trait/isch.hpp"

namespace x4 {
	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto rtrim(std::basic_string_view<Ch, Traits> strv, auto&& chars)
		X4AR(x4::substr(strv, 0, strv.find_last_not_of(X4FWD(chars)), 0, 1))

	template<typename Ch, typename Traits = std::char_traits<Ch>>
	[[nodiscard]] constexpr auto rtrim(const std::basic_string<Ch, Traits>& str, auto&& chars)
		X4AR(x4::rtrim(x4::strv(str), X4FWD(chars)))

	template<x4::isch Ch, typename Traits = std::char_traits<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto rtrim(const Ch(& str)[n], auto&& chars)
		X4AR(x4::rtrim(x4::strv<Ch, Traits>(str), X4FWD(chars)))
}
