#ifndef XIEITE_HEADER_TYPES_MAYBE_VOLATILE
#	define XIEITE_HEADER_TYPES_MAYBE_VOLATILE

#	include <type_traits>

namespace xieite::types {
	template<typename Type, bool constantQualified>
	using MaybeVolatile = std::conditional_t<constantQualified, volatile Type, std::remove_volatile<Type>>::type;
}

#endif
