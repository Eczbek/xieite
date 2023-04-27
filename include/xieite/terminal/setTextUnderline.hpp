#pragma once

#include <string>

namespace xieite::terminal {
	constexpr std::string setTextUnderline(const bool value) noexcept {
		return value ? "\u001b[4m" : "\u001b[24m";
	}
}
