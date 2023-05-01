#pragma once

#include <string_view>

namespace xieite::terminal {
	constexpr std::string_view resetStyle() noexcept {
		return "\u001b[0m";
	}
}
