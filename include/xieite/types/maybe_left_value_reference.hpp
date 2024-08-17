#ifndef XIEITE_HEADER_TYPES_MAYBE_LEFT_VALUE_REFERENCE
#	define XIEITE_HEADER_TYPES_MAYBE_LEFT_VALUE_REFERENCE

#	include <type_traits>

namespace xieite::types {
	template<typename Type, bool qualified>
	using MaybeLeftValueReference = std::conditional_t<qualified, std::remove_reference_t<Type>&, std::remove_reference_t<Type>>;
}

#endif
