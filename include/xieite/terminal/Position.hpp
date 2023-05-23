#ifndef XIEITE_HEADER_TERMINAL_POSITION
#	define XIEITE_HEADER_TERMINAL_POSITION

namespace xieite::terminal {
	struct Position final {
		int row;
		int column;

		constexpr Position(const int row, const int column) noexcept
		: row(row), column(column) {}
	};
}

#endif
