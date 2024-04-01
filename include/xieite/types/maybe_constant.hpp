#ifndef XIEITE_HEADER_TYPES_MAYBE_CONSTANT
#	define XIEITE_HEADER_TYPES_MAYBE_CONSTANT

#	include <type_traits>

namespace xieite::types {
	template<typename Type, bool constant>
	using MaybeConstant = std::conditional_t<constant, std::add_const<Type>, std::remove_const<Type>>::type;
}

#endif
