#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_BOUNDED_ARRAY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_BOUNDED_ARRAY
#
#	include <cstddef>
#	include <type_traits>
#	include "../meta/type.hpp"

namespace xieite {
	template<typename T, std::size_t length = -1uz>
	concept is_bounded_array = ((length == -1uz) ? std::is_bounded_array_v<T> : requires { ([]<typename U>(xieite::type<U[length]>) {})(xieite::type<T>()); });
}

#endif

// https://cplusplus.github.io/CWG/issues/2988.html
// clangd insists on extra parentheses around the ternary expression
