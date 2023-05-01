#pragma once

#include <string_view>

namespace xieite::terminal {
	constexpr std::string_view setTextBold(const bool value) noexcept {
		return value ? "\u001b[1m" : "\u001b[21m";
	}
}
