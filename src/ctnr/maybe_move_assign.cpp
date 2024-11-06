export module xieite:maybe_move_assign;

export namespace xieite {
	template<bool>
	struct maybe_move_assign {};

	template<>
	struct maybe_move_assign<false> {
		maybe_move_assign() = default;
		maybe_move_assign(const xieite::maybe_move_assign<false>&) = default;
		maybe_move_assign(xieite::maybe_move_assign<false>&&) = default;
		xieite::maybe_move_assign<false>& operator=(const xieite::maybe_move_assign<false>&) = default;
		auto operator=(xieite::maybe_move_assign<false>&&) = delete;
	};
}
