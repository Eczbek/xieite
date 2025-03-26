#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_CP_CTOR
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_CP_CTOR

namespace xieite {
	template<bool>
	struct set_cp_ctor {};

	template<>
	struct set_cp_ctor<false> {
		set_cp_ctor() = default;
		set_cp_ctor(const xieite::set_cp_ctor<false>&) = delete;
		set_cp_ctor(xieite::set_cp_ctor<false>&&) = default;
		xieite::set_cp_ctor<false>& operator=(const xieite::set_cp_ctor<false>&) = default;
		xieite::set_cp_ctor<false>& operator=(xieite::set_cp_ctor<false>&&) = default;
	};
}

#endif
