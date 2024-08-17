#ifndef XIEITE_HEADER_CONCEPTS_LEFT_VALUE_REFERENCE
#	define XIEITE_HEADER_CONCEPTS_LEFT_VALUE_REFERENCE

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept LeftValueReference = std::is_lvalue_reference_v<Type>;
}

#endif
