#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_CP_ASSIGN
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_CP_ASSIGN

namespace xieite {
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

#endif
