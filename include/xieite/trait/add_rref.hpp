#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_RREF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_RREF
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	using add_rref = std::add_rvalue_reference_t<T>;
}

#endif
