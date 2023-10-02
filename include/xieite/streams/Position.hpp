#ifndef XIEITE_HEADER__STREAMS__POSITION
#	define XIEITE_HEADER__STREAMS__POSITION

namespace xieite::streams {
	struct Position {
		int row;
		int column;

		constexpr Position(const int row = 0, const int column = 0) noexcept
		: row(row), column(column) {}

		constexpr bool operator==(const xieite::streams::Position& position) noexcept {
			return (this->row == position.row) && (this->column == position.column);
		}
	};
}

#endif
