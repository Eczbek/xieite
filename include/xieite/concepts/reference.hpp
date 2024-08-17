#ifndef XIEITE_HEADER_CONCEPTS_REFERENCE
#	define XIEITE_HEADER_CONCEPTS_REFERENCE

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Reference = std::is_reference_v<Type>;
}

#endif
