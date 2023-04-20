#pragma once

#include <string>

namespace xieite::console {
	constexpr std::string setScreenAlternative(const bool value) noexcept {
		return value ? "\u001b[?47h" : "\u001b[?47l";
	}
}
