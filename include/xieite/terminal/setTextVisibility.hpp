#pragma once

#include <string_view>

namespace xieite::terminal {
	constexpr std::string_view setTextVisibility(const bool value) noexcept {
		return value ? "\u001b[8m" : "\u001b[28m";
	}
}
