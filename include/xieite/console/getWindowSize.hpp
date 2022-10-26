#pragma once
#include <xieite/console/cursor/Position.hpp>

namespace xieite::console {
	[[nodiscard]]
	xieite::console::cursor::Position getWindowSize() noexcept;
}
