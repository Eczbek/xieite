#ifndef XIEITE_HEADER__SYSTEM__BUFFER_POSITION
#	define XIEITE_HEADER__SYSTEM__BUFFER_POSITION

namespace xieite::system {
	struct BufferPosition {
		int row;
		int column;

		constexpr BufferPosition(const int row = 0, const int column = 0) noexcept
		: row(row), column(column) {}

		constexpr bool operator==(const xieite::system::BufferPosition& position) noexcept {
			return ((this->row == position.row) && (this->column == position.column));
		}
	};
}

#endif
