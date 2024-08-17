#ifndef XIEITE_HEADER_TYPES_MAYBE_RIGHT_VALUE_REFERENCE
#	define XIEITE_HEADER_TYPES_MAYBE_RIGHT_VALUE_REFERENCE

#	include <type_traits>

namespace xieite::types {
	template<typename Type, bool qualified>
	using MaybeRightValueReference = std::conditional_t<qualified, std::remove_reference_t<Type>&&, std::remove_reference_t<Type>>;
}

#endif
