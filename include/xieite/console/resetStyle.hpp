#pragma once

#include <string>

namespace xieite::console {
	constexpr std::string resetStyle() noexcept {
		return "\u001b[0m";
	}
}
