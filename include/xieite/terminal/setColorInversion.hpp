#pragma once

#include <string>

namespace xieite::terminal {
	constexpr std::string setColorInversion(const bool value) noexcept {
		return value ? "\u001b[7m" : "\u001b[27m";
	}
}
