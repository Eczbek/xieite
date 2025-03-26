#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_LREF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_LREF
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	using add_lref = std::add_lvalue_reference_t<T>;
}

#endif
