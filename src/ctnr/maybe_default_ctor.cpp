export module xieite:maybe_default_constructible;

export namespace xieite {
	template<bool>
	struct maybe_default_constructible {};

	template<>
	struct maybe_default_constructible<false> {
		maybe_default_constructible() = delete;
		maybe_default_constructible(const xieite::maybe_default_constructible<false>&) = default;
		maybe_default_constructible(xieite::maybe_default_constructible<false>&&) = default;
		xieite::maybe_default_constructible<false>& operator=(const xieite::maybe_default_constructible<false>&) = default;
		xieite::maybe_default_constructible<false>& operator=(xieite::maybe_default_constructible<false>&&) = default;
	};
}
