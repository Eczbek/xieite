#ifndef XIEITE_HEADER_CONCEPTS_ARITHMETIC
#	define XIEITE_HEADER_CONCEPTS_ARITHMETIC

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Arithmetic = std::is_arithmetic_v<Type>;
}

#endif
