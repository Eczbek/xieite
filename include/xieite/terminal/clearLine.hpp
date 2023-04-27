#pragma once

#include <string>

namespace xieite::terminal {
	constexpr std::string clearLine() noexcept {
		return "\u001b[2K";
	}
}
