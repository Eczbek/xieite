#ifndef XIEITE_HEADER_TYPES_COLLAPSE_REFERENCE
#	define XIEITE_HEADER_TYPES_COLLAPSE_REFERENCE

#	include <type_traits>

namespace xieite::types {
	template<typename Type, typename Other>
	using CollapseReference = std::conditional_t<std::is_lvalue_reference_v<Other>, std::conditional_t<std::is_const_v<Other>, std::add_const_t<std::add_lvalue_reference_t<Type>>, std::add_lvalue_reference_t<Type>>, std::add_rvalue_reference_t<Type>>;
}

#endif
