#ifndef XIEITE_HEADER_CONCEPTS_FUNCTION
#	define XIEITE_HEADER_CONCEPTS_FUNCTION

#	include <xieite/traits/isFunctional.hpp>

namespace xieite::concepts {
	template<typename Invocable, typename ResultOfParameters>
	concept Functional = xieite::traits::isFunctional<Invocable, ResultOfParameters>;
}

#endif
