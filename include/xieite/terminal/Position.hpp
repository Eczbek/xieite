#pragma once

namespace xieite::terminal {
	struct Position {
		int row;
		int column;

		constexpr Position() noexcept
		: row(0), column(0) {}

		constexpr Position(const int row, const int column) noexcept
		: row(row), column(column) {}
	};
}
