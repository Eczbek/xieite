export module xieite:streams.Position;

export namespace xieite::streams {
	struct Position {
		int row = 0;
		int column = 0;

		[[nodiscard]] friend constexpr bool operator==(xieite::streams::Position, xieite::streams::Position) noexcept = default;
	};
}
