#pragma once

#include <string_view>

namespace xieite::terminal {
	constexpr std::string_view setColorInversion(const bool value) noexcept {
		return value ? "\u001b[7m" : "\u001b[27m";
	}
}