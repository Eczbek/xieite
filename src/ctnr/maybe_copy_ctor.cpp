export module xieite:maybe_copy_ctor;

export namespace xieite {
	template<bool>
	struct maybe_copy_ctor {};

	template<>
	struct maybe_copy_ctor<false> {
		maybe_copy_ctor() = default;
		maybe_copy_ctor(const xieite::maybe_copy_ctor<false>&) = delete;
		maybe_copy_ctor(xieite::maybe_copy_ctor<false>&&) = default;
		xieite::maybe_copy_ctor<false>& operator=(const xieite::maybe_copy_ctor<false>&) = default;
		xieite::maybe_copy_ctor<false>& operator=(xieite::maybe_copy_ctor<false>&&) = default;
	};
}
