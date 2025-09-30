#ifndef DETAIL_XTE_HEADER_TRAIT_IS
#	define DETAIL_XTE_HEADER_TRAIT_IS

namespace xte {
	template<typename T, auto... predicates>
	concept is = (... && requires { predicates.template operator()<T>(); });
}

#endif
