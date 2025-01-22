export module xieite:set_cp_assign;

export namespace xieite {
	template<bool>
	struct set_cp_assign {};

	template<>
	struct set_cp_assign<false> {
		set_cp_assign() = default;
		set_cp_assign(const xieite::set_cp_assign<false>&) = default;
		set_cp_assign(xieite::set_cp_assign<false>&&) = default;
		auto operator=(const xieite::set_cp_assign<false>&) = delete;
		xieite::set_cp_assign<false>& operator=(xieite::set_cp_assign<false>&&) = default;
	};
}
