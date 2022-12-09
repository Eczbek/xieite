#pragma once
#include <xieite/console/CursorPosition.hpp> // xieite::console::CursorPosition

namespace xieite::console {
	[[nodiscard]]
	xieite::console::CursorPosition getWindowSize() noexcept;
}
