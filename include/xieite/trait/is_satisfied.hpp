#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SATISFIED
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SATISFIED

namespace xieite {
	template<auto fn, typename... Ts>
	concept is_satisfied = requires { fn.template operator()<Ts...>(); };
}

#endif
