#ifndef XIEITE_HEADER_CONCEPTS_RIGHT_VALUE_REFERENCE
#	define XIEITE_HEADER_CONCEPTS_RIGHT_VALUE_REFERENCE

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept RightValueReference = std::is_rvalue_reference_v<Type>;
}

#endif
