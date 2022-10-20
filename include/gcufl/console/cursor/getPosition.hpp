#pragma once
#include <gcufl/console/cursor/Position.hpp>

namespace gcufl::console::cursor {
	[[nodiscard]]
	gcufl::console::cursor::Position getPosition() noexcept;
}
