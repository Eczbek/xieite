#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_BOUNDED_ARRAY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_BOUNDED_ARRAY
#
#	include <cstddef>
#	include <type_traits>

namespace xieite {
	template<typename T, std::size_t n = -1uz>
	concept is_bounded_array = (n == -1uz)
		? requires { ([]<typename U, std::size_t m>(std::type_identity<U[m]>) {})(std::type_identity<T>()); }
		: requires { ([]<typename U>(std::type_identity<U[n]>) {})(std::type_identity<T>()); };
}

#endif
