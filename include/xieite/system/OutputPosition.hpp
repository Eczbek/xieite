#ifndef XIEITE_HEADER_SYSTEM_OUTPUTPOSITION
#	define XIEITE_HEADER_SYSTEM_OUTPUTPOSITION

namespace xieite::system {
	struct OutputPosition {
		int row;
		int column;

		constexpr OutputPosition(const int row, const int column) noexcept
		: row(row), column(column) {}
	};
}

#endif
