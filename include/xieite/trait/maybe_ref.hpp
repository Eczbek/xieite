#ifndef DETAIL_XIEITE_HEADER_TRAIT_MAYBE_REF
#	define DETAIL_XIEITE_HEADER_TRAIT_MAYBE_REF
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	using maybe_ref = std::conditional_t<((sizeof(T) <= (sizeof(int*) * 2)) && std::is_trivially_copyable_v<T>), T, const T&>; 
}

#endif
