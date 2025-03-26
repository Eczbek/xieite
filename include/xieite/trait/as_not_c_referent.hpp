#ifndef DETAIL_XIEITE_HEADER_TRAIT_AS_NOT_C_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_AS_NOT_C_REFERENT
#
#	include "../pp/arrow.hpp"
#	include "../trait/rm_c_referent.hpp"

namespace xieite {
	constexpr auto as_not_c_referent =
		[]<typename T>[[nodiscard]](T&& x) static
			XIEITE_ARROW(const_cast<xieite::rm_c_referent<T&&>>(x));
}

#endif
