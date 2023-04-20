#pragma once

#include <string>
#include <xieite/graphics/Color.hpp>
#include <xieite/math/toBase.hpp>

namespace xieite::console {
	constexpr std::string setColorForeground(const xieite::graphics::Color& color) noexcept {
		return "\u001b[38;2;" + xieite::math::toBase(color.red, 10) + ';' + xieite::math::toBase(color.green, 10) + ';' + xieite::math::toBase(color.blue, 10) + 'm';
	}

	constexpr std::string setColorForeground() noexcept {
		return "\u001b[38m";
	}
}
