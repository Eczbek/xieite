#ifndef XIEITE_HEADER_TYPES_COLLAPSE_REFERENCE
#	define XIEITE_HEADER_TYPES_COLLAPSE_REFERENCE

#	include <type_traits>

namespace xieite::types {
	template<typename Type_, typename Other_>
	using CollapseReference = std::conditional_t<std::is_lvalue_reference_v<Other_>, std::conditional_t<std::is_const_v<Other_>, std::add_const_t<std::add_lvalue_reference_t<Type_>>, std::add_lvalue_reference_t<Type_>>, std::add_rvalue_reference_t<Type_>>;
}

#endif
