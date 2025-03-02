#pragma once

#include <string>
#include <string_view>
#include "../ctnr/fixed_str.hpp"

namespace xieite {
	template<xieite::fixed_str fstr, typename Traits = std::char_traits<typename decltype(fstr)::value_type>>
	constexpr auto static_str = fstr.template view<Traits>();
}
