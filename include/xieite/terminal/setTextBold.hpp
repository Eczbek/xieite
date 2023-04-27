#pragma once

#include <string>

namespace xieite::terminal {
	constexpr std::string setTextBold(const bool value) noexcept {
		return value ? "\u001b[1m" : "\u001b[21m";
	}
}
