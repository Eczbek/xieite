#ifndef XIEITE_HEADER_TYPES_MAYBE_CONSTANT
#	define XIEITE_HEADER_TYPES_MAYBE_CONSTANT

#	include <type_traits>

namespace xieite::types {
	template<typename Type_, bool constant_>
	using MaybeConstant = std::conditional_t<constant_, const Type_, std::remove_const<Type_>>::type;
}

#endif
