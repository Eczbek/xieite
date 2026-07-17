#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CALLABLE_LVALUE
#	define DETAIL_XTE_HEADER_TRAIT_IS_CALLABLE_LVALUE
#
#	include "../trait/is_callable.hpp"

namespace xte {
	template<typename T, typename Signature>
	concept is_callable_lvalue = xte::is_callable<T&, Signature>;
}

#endif
