#ifndef DETAIL_XIEITE_HEADER_TRAIT_AS_C
#	define DETAIL_XIEITE_HEADER_TRAIT_AS_C
#
#	include "../pp/arrow.hpp"
#	include "../trait/add_c.hpp"

namespace xieite {
	constexpr auto as_c =
		[]<typename T>[[nodiscard]](T&& x) static
			XIEITE_ARROW(const_cast<xieite::add_c<T&&>>(x));
}

#endif
