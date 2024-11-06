export module xieite:maybe_default_ctor;

export namespace xieite {
	template<bool>
	struct maybe_default_ctor {};

	template<>
	struct maybe_default_ctor<false> {
		maybe_default_ctor() = delete;
		maybe_default_ctor(const xieite::maybe_default_ctor<false>&) = default;
		maybe_default_ctor(xieite::maybe_default_ctor<false>&&) = default;
		xieite::maybe_default_ctor<false>& operator=(const xieite::maybe_default_ctor<false>&) = default;
		xieite::maybe_default_ctor<false>& operator=(xieite::maybe_default_ctor<false>&&) = default;
	};
}
