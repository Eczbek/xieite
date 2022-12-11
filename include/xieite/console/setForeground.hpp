#pragma once
#include <string> // std::string
#include <xieite/graphics/Color.hpp>

namespace xieite::console {
	constexpr std::string setForeground(const xieite::graphics::Color color) noexcept {
		return "\x1b[38;2;" + color.red + ';' + color.green + ';' + color.blue + 'm';
	}
}
