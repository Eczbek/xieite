#pragma once

#include <string>
#include <xieite/terminal/Position.hpp>
#include <xieite/math/toBase.hpp>

namespace xieite::terminal {
	constexpr std::string setCursorPosition(const xieite::terminal::Position position) noexcept {
		return "\u001b[" + xieite::math::toBase(position.row + 1, 10) + ';' + xieite::math::toBase(position.column + 1, 10) + 'H';
	}
}
