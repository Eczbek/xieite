#ifndef XIEITE_HEADER_CONCEPTS_FUNCTION
#	define XIEITE_HEADER_CONCEPTS_FUNCTION

#	include <xieite/traits/isFunction.hpp>

namespace xieite::concepts {
	template<typename Invocable, typename ResultOfParameters>
	concept Function = xieite::traits::isFunction<Invocable, ResultOfParameters>;
}

#endif
