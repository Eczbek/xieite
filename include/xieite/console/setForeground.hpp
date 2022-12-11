#pragma once
#include <string> // std::string
#include <xieite/graphics/Color.hpp>
#include <xieite/math/toBase.hpp>

namespace xieite::console {
	constexpr std::string setForeground(const xieite::graphics::Color color) noexcept {
		return "\x1b[38;2;" + xieite::math::toBase(color.red, 10) + ';' + xieite::math::toBase(color.green, 10) + ';' + xieite::math::toBase(color.blue, 10) + 'm';
	}
}
