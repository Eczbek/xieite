#ifndef DETAIL_XIEITE_HEADER_TRAIT_AS_NOT_C
#	define DETAIL_XIEITE_HEADER_TRAIT_AS_NOT_C
#
#	include "../pp/arrow.hpp"
#	include "../trait/rm_c.hpp"

namespace xieite {
	constexpr auto as_not_c =
		[]<typename T>[[nodiscard]](T&& x) static
			XIEITE_ARROW(const_cast<xieite::rm_c<T&&>>(x));
}

#endif
