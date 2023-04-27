#pragma once

#include <string>

namespace xieite::terminal {
	constexpr std::string setTextStrikethrough(const bool value) noexcept {
		return value ? "\u001b[9m" : "\u001b[29m";
	}
}
