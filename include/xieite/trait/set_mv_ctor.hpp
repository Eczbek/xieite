#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_MV_CTOR
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_MV_CTOR

namespace xieite {
	template<bool>
	struct set_mv_ctor {};

	template<>
	struct set_mv_ctor<false> {
		set_mv_ctor() = default;
		set_mv_ctor(const xieite::set_mv_ctor<false>&) = default;
		set_mv_ctor(xieite::set_mv_ctor<false>&&) = delete;
		xieite::set_mv_ctor<false>& operator=(const xieite::set_mv_ctor<false>&) = default;
		xieite::set_mv_ctor<false>& operator=(xieite::set_mv_ctor<false>&&) = default;
	};
}

#endif
