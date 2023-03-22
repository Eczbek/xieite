#pragma once

#include <string>
#include <xieite/math/toBase.hpp>

namespace xieite::console {
	constexpr std::string moveCursor(const char control, const int value) noexcept {
		return "\x1b[" + xieite::math::toBase(value, 10) + control;
	}
}
