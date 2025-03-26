#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SATISFD
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SATISFD

namespace xieite {
	template<auto fn, typename... Ts>
	concept is_satisfd = requires { fn.template operator()<Ts...>(); };
}

#endif
