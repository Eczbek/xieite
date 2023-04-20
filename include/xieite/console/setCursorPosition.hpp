#pragma once

#include <string>
#include <xieite/console/Position.hpp>
#include <xieite/math/toBase.hpp>

namespace xieite::console {
	constexpr std::string setCursorPosition(const xieite::console::Position position) noexcept {
		return "\u001b[" + xieite::math::toBase(position.row + 1, 10) + ';' + xieite::math::toBase(position.column + 1, 10) + 'H';
	}
}
