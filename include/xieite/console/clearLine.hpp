#pragma once

#include <string>

namespace xieite::console {
	constexpr std::string clearLine() noexcept {
		return "\u001b[2K";
	}
}
