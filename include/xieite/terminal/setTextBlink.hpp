#pragma once

#include <string_view>

namespace xieite::terminal {
	constexpr std::string_view setTextBlink(const bool value) noexcept {
		return value ? "\u001b[5m" : "\u001b[25m";
	}
}
