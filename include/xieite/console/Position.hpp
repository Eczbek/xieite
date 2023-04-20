#pragma once

namespace xieite::console {
	struct Position {
		int row;
		int column;

		constexpr Position(const int row = 0, const int column = 0) noexcept
		: row(row), column(column) {}
	};
}
