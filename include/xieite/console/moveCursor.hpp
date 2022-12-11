#pragma once
#include <string> // std::string

namespace xieite::console {
	constexpr std::string moveCursor(const char control, const int value) noexcept {
		return "\x1b[" + value + control;
	}
}
