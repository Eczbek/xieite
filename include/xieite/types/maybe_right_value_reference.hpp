#ifndef XIEITE_HEADER_TYPES_MAYBE_RIGHT_VALUE_REFERENCE
#	define XIEITE_HEADER_TYPES_MAYBE_RIGHT_VALUE_REFERENCE

#	include <type_traits>

namespace xieite::types {
	template<typename Type_, bool rightValueReference_>
	using MaybeRightValueReference = std::conditional_t<rightValueReference_, std::add_rvalue_reference<Type_>, std::type_dentity<Type_>>::type;
}

#endif
