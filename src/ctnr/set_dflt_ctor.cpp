export module xieite:set_dflt_ctor;

export namespace xieite {
	template<bool>
	struct set_dflt_ctor {};

	template<>
	struct set_dflt_ctor<false> {
		set_dflt_ctor() = delete;
		set_dflt_ctor(const xieite::set_dflt_ctor<false>&) = default;
		set_dflt_ctor(xieite::set_dflt_ctor<false>&&) = default;
		xieite::set_dflt_ctor<false>& operator=(const xieite::set_dflt_ctor<false>&) = default;
		xieite::set_dflt_ctor<false>& operator=(xieite::set_dflt_ctor<false>&&) = default;
	};
}
