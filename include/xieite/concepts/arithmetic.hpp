#ifndef XIEITE_HEADER_CONCEPTS_ARITHMETIC
#	define XIEITE_HEADER_CONCEPTS_ARITHMETIC

#	include <concepts>

namespace xieite::concepts {
	template<typename Type>
	concept Arithmetic = std::integral<Type> || std::floating_point<Type>;
}

#endif
