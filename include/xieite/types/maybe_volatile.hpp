#ifndef XIEITE_HEADER_TYPES_MAYBE_VOLATILE
#	define XIEITE_HEADER_TYPES_MAYBE_VOLATILE

#	include <type_traits>

namespace xieite::types {
	template<typename Type_, bool constant_>
	using MaybeVolatile = std::conditional_t<constant_, volatile Type_, std::remove_volatile<Type_>>::type;
}

#endif
