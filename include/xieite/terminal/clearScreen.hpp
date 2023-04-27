#pragma once

#include <string>

namespace xieite::terminal {
	constexpr std::string clearScreen() noexcept {
		return "\u001b[2J";
	}
}
