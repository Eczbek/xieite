#pragma once

#include <string>

namespace xieite::console {
	constexpr std::string setTextStrikethrough(const bool value) noexcept {
		return value ? "\u001b[9m" : "\u001b[29m";
	}
}
