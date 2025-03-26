#ifndef DETAIL_XIEITE_HEADER_TRAIT_AS_NOT_V_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_AS_NOT_V_REFERENT
#
#	include "../pp/arrow.hpp"
#	include "../trait/rm_v_referent.hpp"

namespace xieite {
	constexpr auto as_not_v_referent =
		[]<typename T>[[nodiscard]](T&& x) static
			XIEITE_ARROW(const_cast<xieite::rm_v_referent<T&&>>(x));
}

#endif
