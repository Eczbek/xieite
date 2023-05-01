#pragma once

#include <string_view>

namespace xieite::terminal {
	constexpr std::string_view setScreenAlternative(const bool value) noexcept {
		return value ? "\u001b[?47h" : "\u001b[?47l";
	}
}
