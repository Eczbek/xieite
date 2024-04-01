#ifndef XIEITE_HEADER_TYPES_MAYBE_LEFT_VALUE_REFERENCE
#	define XIEITE_HEADER_TYPES_MAYBE_LEFT_VALUE_REFERENCE

#	include <type_traits>

namespace xieite::types {
	template<typename Type_, bool rightLeftReference_>
	using MaybeLeftValueReference = std::conditional_t<rightLeftReference_, std::add_lvalue_reference<Type_>, std::type_identity<Type_>>::type;
}

#endif
