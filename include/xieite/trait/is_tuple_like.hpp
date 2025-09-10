#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_TUPLE_LIKE
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_TUPLE_LIKE
#
#	include <tuple>

namespace xieite {
	template<typename T>
	concept is_tuple_like = requires { std::tuple_size<std::remove_cvref_t<T>>(); };
}

#endif
