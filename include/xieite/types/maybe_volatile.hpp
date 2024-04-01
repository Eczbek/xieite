#ifndef XIEITE_HEADER_TYPES_MAYBE_VOLATILE
#	define XIEITE_HEADER_TYPES_MAYBE_VOLATILE

#	include <type_traits>

namespace xieite::types {
	template<typename Type, bool constant>
	using MaybeVolatile = std::conditional_t<constant, std::add_volatile<Type>, std::remove_volatile<Type>>::type;
}

#endif
