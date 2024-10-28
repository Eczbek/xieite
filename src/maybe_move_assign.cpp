export module xieite:maybe_move_assignable;

export namespace xieite {
	template<bool>
	struct maybe_move_assignable {};

	template<>
	struct maybe_move_assignable<false> {
		maybe_move_assignable() = default;
		maybe_move_assignable(const xieite::maybe_move_assignable<false>&) = default;
		maybe_move_assignable(xieite::maybe_move_assignable<false>&&) = default;
		xieite::maybe_move_assignable<false>& operator=(const xieite::maybe_move_assignable<false>&) = default;
		auto operator=(xieite::maybe_move_assignable<false>&&) = delete;
	};
}
