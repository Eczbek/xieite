#pragma once

#include <string>

namespace xieite::terminal {
	constexpr std::string resetStyle() noexcept {
		return "\u001b[0m";
	}
}
