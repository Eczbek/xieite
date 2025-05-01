#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_COMPLETE
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_COMPLETE

namespace xieite {
	template<typename T, auto = [] {}>
	concept is_complete = requires { ([]<typename U, auto = sizeof(U)> {}).template operator()<T>(); };
}

#endif

// https://cplusplus.github.io/CWG/issues/2988.html
