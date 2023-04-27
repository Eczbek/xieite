#pragma once

#include <string>
#include <xieite/math/toBase.hpp>

namespace xieite::terminal {
	constexpr std::string setCursorAlternative(const bool value) noexcept {
		return value ? "\u001b[s" : "\u001b[u";
	}
}
