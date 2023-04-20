#pragma once

#include <string>

namespace xieite::console {
	constexpr std::string setTextItalic(const bool value) noexcept {
		return value ? "\u001b[3m" : "\u001b[23m";
	}
}
