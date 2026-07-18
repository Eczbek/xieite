#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CALLABLE_LVALUE
#	define DETAIL_XTE_HEADER_TRAIT_IS_CALLABLE_LVALUE
#
#	include "../trait/is_callable.hpp"

namespace xte {
	template<typename T, typename signature_type>
	concept is_callable_lvalue = xte::is_callable<T&, signature_type>;
}

#endif
