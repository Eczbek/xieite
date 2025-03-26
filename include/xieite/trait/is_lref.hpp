#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_LREF
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_LREF
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_lref = std::is_lvalue_reference_v<T>;
}

#endif
