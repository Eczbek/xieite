#ifndef DETAIL_XIEITE_HEADER_TRAIT_AS_NOT_V
#	define DETAIL_XIEITE_HEADER_TRAIT_AS_NOT_V
#
#	include "../pp/arrow.hpp"
#	include "../trait/rm_v.hpp"

namespace xieite {
	constexpr auto as_not_v =
		[]<typename T>[[nodiscard]](T&& x) static
			XIEITE_ARROW(const_cast<xieite::rm_v<T&&>>(x));
}

#endif
