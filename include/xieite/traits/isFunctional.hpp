#ifndef XIEITE_HEADER_TRAITS_ISFUNCTIONAL
#	define XIEITE_HEADER_TRAITS_ISFUNCTIONAL

#	warning "'xieite::traits::isFunctional' is deprecated"

#	include <xieite/traits/isFunctable.hpp>

namespace xieite::traits {
	template<typename Any1, typename Any2>
	inline constexpr bool isFunctional = xieite::traits::isFunctable<Any1, Any2>;
}

#endif
