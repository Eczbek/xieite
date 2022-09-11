#pragma once


namespace gcufl::io::cursor {
	struct Position {
		int row;
		int column;

		Position(const int row, const int column) noexcept
		: row(row), column(column) {}
	};
}
