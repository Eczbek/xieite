#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_FN
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_FN
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_fn = std::is_function_v<T>;
}

#endif
