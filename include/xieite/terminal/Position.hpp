#pragma once

namespace xieite::terminal {
	struct Position final {
		int row;
		int column;

		constexpr Position(const int row, const int column) noexcept
		: row(row), column(column) {}
	};
}
