#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CALLABLE_LREF
#	define DETAIL_XTE_HEADER_TRAIT_IS_CALLABLE_LREF
#
#	include "../trait/is_callable.hpp"

namespace xte {
	template<typename T, typename Signature>
	concept is_callable_lref = xte::is_callable<T&, Signature>;
}

#endif
