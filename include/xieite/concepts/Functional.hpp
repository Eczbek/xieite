#ifndef XIEITE_HEADER_CONCEPTS_FUNCTIONAL
#	define XIEITE_HEADER_CONCEPTS_FUNCTIONAL

#	warning "'xieite::concepts::Functional' is deprecated"

#	include <xietie/concepts/Functable.hpp>

namespace xieite::concepts {
	template<typename Any1, typename Any2>
	concept Functional = xieite::concepts::Functable<Any1, Any2>;
}

#endif
