#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_DEFAULT_CTOR
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_DEFAULT_CTOR

namespace xieite {
	template<bool>
	struct set_default_ctor {};

	template<>
	struct set_default_ctor<false> {
		set_default_ctor() = delete;
		set_default_ctor(const xieite::set_default_ctor<false>&) = default;
		set_default_ctor(xieite::set_default_ctor<false>&&) = default;
		xieite::set_default_ctor<false>& operator=(const xieite::set_default_ctor<false>&) = default;
		xieite::set_default_ctor<false>& operator=(xieite::set_default_ctor<false>&&) = default;
	};
}

#endif
