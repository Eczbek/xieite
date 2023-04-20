#pragma once

#include <string>

namespace xieite::console {
	constexpr std::string setCursorVisibility(const bool value) noexcept {
		return value ? "\u001b[?25h" : "\u001b[?25l";
	}
}
