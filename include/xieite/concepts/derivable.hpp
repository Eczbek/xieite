#ifndef XIEITE_HEADER_CONCEPTS_DERIVABLE
#	define XIEITE_HEADER_CONCEPTS_DERIVABLE

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Derivable = !std::is_final_v<Type>; // Type must be a complete structure
}

#endif
