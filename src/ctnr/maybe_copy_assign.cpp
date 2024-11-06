export module xieite:maybe_copy_assign;

export namespace xieite {
	template<bool>
	struct maybe_copy_assign {};

	template<>
	struct maybe_copy_assign<false> {
		maybe_copy_assign() = default;
		maybe_copy_assign(const xieite::maybe_copy_assign<false>&) = default;
		maybe_copy_assign(xieite::maybe_copy_assign<false>&&) = default;
		auto operator=(const xieite::maybe_copy_assign<false>&) = delete;
		xieite::maybe_copy_assign<false>& operator=(xieite::maybe_copy_assign<false>&&) = default;
	};
}
