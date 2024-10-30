export module xieite:maybe_copy_assignable;

export namespace xieite {
	template<bool>
	struct maybe_copy_assignable {};

	template<>
	struct maybe_copy_assignable<false> {
		maybe_copy_assignable() = default;
		maybe_copy_assignable(const xieite::maybe_copy_assignable<false>&) = default;
		maybe_copy_assignable(xieite::maybe_copy_assignable<false>&&) = default;
		auto operator=(const xieite::maybe_copy_assignable<false>&) = delete;
		xieite::maybe_copy_assignable<false>& operator=(xieite::maybe_copy_assignable<false>&&) = default;
	};
}
