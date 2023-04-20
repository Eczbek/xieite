#pragma once

#include <string>

namespace xieite::console {
	constexpr std::string clearScreen() noexcept {
		return "\u001b[2J";
	}
}
