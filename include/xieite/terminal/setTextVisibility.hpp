#pragma once

#include <string>

namespace xieite::terminal {
	constexpr std::string setTextVisibility(const bool value) noexcept {
		return value ? "\u001b[8m" : "\u001b[28m";
	}
}
