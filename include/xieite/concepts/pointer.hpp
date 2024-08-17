#ifndef XIEITE_HEADER_CONCEPTS_POINTER
#	define XIEITE_HEADER_CONCEPTS_POINTER

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Pointer = std::is_pointer_v<std::remove_reference_t<Type>>;
}

#endif
