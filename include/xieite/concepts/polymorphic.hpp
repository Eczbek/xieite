#ifndef XIEITE_HEADER_CONCEPTS_POLYMORPHIC
#	define XIEITE_HEADER_CONCEPTS_POLYMORPHIC

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Polymorphic = std::is_polymorphic_v<Type>;
	// Can be used for checking if a type has a virtual table
}

#endif
