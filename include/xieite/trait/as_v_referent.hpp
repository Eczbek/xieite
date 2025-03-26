#ifndef DETAIL_XIEITE_HEADER_TRAIT_AS_V_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_AS_V_REFERENT
#
#	include "../pp/arrow.hpp"
#	include "../trait/add_v_referent.hpp"

namespace xieite {
	constexpr auto as_v_referent =
		[]<typename T>[[nodiscard]](T&& x) static
			XIEITE_ARROW(const_cast<xieite::add_v_referent<T&&>>(x));
}

#endif
