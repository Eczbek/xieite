#ifndef XIEITE_HEADER_STREAMS_POSITION
#	define XIEITE_HEADER_STREAMS_POSITION

namespace xieite::streams {
	struct Position {
		int row = 0;
		int column = 0;

		[[nodiscard]] friend constexpr bool operator==(const xieite::streams::Position position1, const xieite::streams::Position position2) noexcept {
			return (position1.row == position2.row) && (position1.column == position2.column);
		}
	};
}

#endif
