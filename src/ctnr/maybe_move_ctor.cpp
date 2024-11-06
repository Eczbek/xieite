export module xieite:maybe_move_ctor;

export namespace xieite {
	template<bool>
	struct maybe_move_ctor {};

	template<>
	struct maybe_move_ctor<false> {
		maybe_move_ctor() = default;
		maybe_move_ctor(const xieite::maybe_move_ctor<false>&) = default;
		maybe_move_ctor(xieite::maybe_move_ctor<false>&&) = delete;
		xieite::maybe_move_ctor<false>& operator=(const xieite::maybe_move_ctor<false>&) = default;
		xieite::maybe_move_ctor<false>& operator=(xieite::maybe_move_ctor<false>&&) = default;
	};
}
