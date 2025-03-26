#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SCALAR
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SCALAR
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_scalar = std::is_scalar_v<T>;
}

#endif
