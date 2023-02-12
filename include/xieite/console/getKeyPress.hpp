#pragma once
#include <iostream> // std::cin
#include <xieite/console/RawLock.hpp>

namespace xieite::console {
	inline char getKeyPress(const bool echo = false) noexcept {
		xieite::console::RawLock RawLock(echo);
		return std::cin.get();
	}
}
