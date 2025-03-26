#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_MV_ASSIGN
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_MV_ASSIGN

namespace xieite {
	template<bool>
	struct set_mv_assign {};

	template<>
	struct set_mv_assign<false> {
		set_mv_assign() = default;
		set_mv_assign(const xieite::set_mv_assign<false>&) = default;
		set_mv_assign(xieite::set_mv_assign<false>&&) = default;
		xieite::set_mv_assign<false>& operator=(const xieite::set_mv_assign<false>&) = default;
		auto operator=(xieite::set_mv_assign<false>&&) = delete;
	};
}

#endif
