#pragma once

#include <string>

namespace xieite::console {
	constexpr std::string setColorDim(const bool value) noexcept {
		return value ? "\u001b[2m" : "\u001b[22m";
	}
}
