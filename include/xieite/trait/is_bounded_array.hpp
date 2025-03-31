#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_BOUNDED_ARRAY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_BOUNDED_ARRAY
#
#	include <cstddef>
#	include <type_traits>

namespace xieite {
	template<typename T, std::size_t n = -1uz>
	concept is_bounded_array = ((n == -1uz) ? std::is_bounded_array_v<T> : requires { ([]<typename U>(std::type_identity<U[n]>) {})(std::type_identity<T>()); });
}

#endif

// https://cplusplus.github.io/CWG/issues/2988.html
// clangd insists on extra parentheses around the ternary expression
