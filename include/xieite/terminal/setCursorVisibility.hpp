#pragma once

#include <string_view>

namespace xieite::terminal {
	constexpr std::string_view setCursorVisibility(const bool value) noexcept {
		return value ? "\u001b[?25h" : "\u001b[?25l";
	}
}
