#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_PTR_INTERCONV_BASE
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_PTR_INTERCONV_BASE
#
#	include <type_traits>

namespace xieite {
	template<typename T, typename U>
	concept is_ptr_interconv_base = std::is_pointer_interconvertible_base_of_v<T, U>;
}

#endif
