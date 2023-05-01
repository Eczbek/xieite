#pragma once

#include <string_view>

namespace xieite::terminal {
	constexpr std::string_view setTextStrikethrough(const bool value) noexcept {
		return value ? "\u001b[9m" : "\u001b[29m";
	}
}
