#pragma once
#include <gcufl/console/cursor/Position.hpp>

namespace gcufl::console {
	[[nodiscard]]
	gcufl::console::cursor::Position getWindowSize() noexcept;
}
