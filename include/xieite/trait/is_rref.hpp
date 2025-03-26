#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_RREF
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_RREF
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_rref = std::is_rvalue_reference_v<T>;
}

#endif
