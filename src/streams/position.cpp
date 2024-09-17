export module xieite:streams.Position;

export namespace xieite::streams {
	struct Position {
		int row = 0;
		int column = 0;

		[[nodiscard]] friend bool operator==(xieite::streams::Position, xieite::streams::Position) = default;
	};
}
