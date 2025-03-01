#pragma once

#include <string>
#include <string_view>
#include "../ctnr/fstr.hpp"

namespace x4 {
	template<x4::fstr fstr, typename Traits = std::char_traits<typename decltype(fstr)::value_type>>
	constexpr auto sstr = std::basic_string_view<typename decltype(fstr)::value_type, Traits>(fstr.data.begin(), fstr.data.end());
}
