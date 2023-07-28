#ifndef XIEITE_HEADER_SYSTEM_BUFFERPOSITION
#	define XIEITE_HEADER_SYSTEM_BUFFERPOSITION

namespace xieite::system {
	struct BufferPosition {
		int row;
		int column;

		constexpr BufferPosition(const int row = 0, const int column = 0) noexcept
		: row(row), column(column) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::system::BufferPosition& position) noexcept {
			return ((this->row == position.row) && (this->column == position.column));
		}
	};
}

#endif
