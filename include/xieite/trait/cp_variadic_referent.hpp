#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VARIADIC_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VARIADIC_REFERENT
#
#	include "../trait/is_variadic_referent.hpp"
#	include "../trait/set_variadic_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_variadic_referent = xieite::set_variadic_referent<xieite::is_variadic_referent<T>, U>;
}

#endif
