export module xieite:maybe_move_constructible;

export namespace xieite {
	template<bool>
	struct maybe_move_constructible {};

	template<>
	struct maybe_move_constructible<false> {
		maybe_move_constructible() = default;
		maybe_move_constructible(const xieite::maybe_move_constructible<false>&) = default;
		maybe_move_constructible(xieite::maybe_move_constructible<false>&&) = delete;
		xieite::maybe_move_constructible<false>& operator=(const xieite::maybe_move_constructible<false>&) = default;
		xieite::maybe_move_constructible<false>& operator=(xieite::maybe_move_constructible<false>&&) = default;
	};
}
