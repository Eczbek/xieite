#pragma once

#include <string_view>
#include <xieite/math/toBase.hpp>

namespace xieite::terminal {
	constexpr std::string_view setCursorAlternative(const bool value) noexcept {
		return value ? "\u001b[s" : "\u001b[u";
	}
}
