#pragma once

namespace gcufl::console::cursor {
	struct Position {
		int row;
		int column;

		[[nodiscard]]
		Position(const int row = 0, const int column = 0) noexcept
		: row(row), column(column) {}
	};
}
