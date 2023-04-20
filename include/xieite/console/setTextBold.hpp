#pragma once

#include <string>

namespace xieite::console {
	constexpr std::string setTextBold(const bool value) noexcept {
		return value ? "\u001b[1m" : "\u001b[21m";
	}
}
