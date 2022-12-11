#pragma once
#include <string> // std::string
#include <xieite/graphics/Color.hpp>

namespace xieite::console {
	constexpr std::string setBackground(const xieite::graphics::Color color) noexcept {
		return "\x1b[48;2;" + color.red + ';' + color.green + ';' + color.blue + 'm';
	}
}
