export module xieite:maybe_copy_constructible;

export namespace xieite {
	template<bool>
	struct maybe_copy_constructible {};

	template<>
	struct maybe_copy_constructible<false> {
		maybe_copy_constructible() = default;
		maybe_copy_constructible(const xieite::maybe_copy_constructible<false>&) = delete;
		maybe_copy_constructible(xieite::maybe_copy_constructible<false>&&) = default;
		xieite::maybe_copy_constructible<false>& operator=(const xieite::maybe_copy_constructible<false>&) = default;
		xieite::maybe_copy_constructible<false>& operator=(xieite::maybe_copy_constructible<false>&&) = default;
	};
}
