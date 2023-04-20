#pragma once

#include <string>

namespace xieite::console {
	constexpr std::string setTextBlink(const bool value) noexcept {
		return value ? "\u001b[5m" : "\u001b[25m";
	}
}
