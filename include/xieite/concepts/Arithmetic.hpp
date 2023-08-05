#ifndef XIEITE_HEADER__CONCEPTS__ARITHMETIC
#	define XIEITE_HEADER__CONCEPTS__ARITHMETIC

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Arithmetic = std::is_arithmetic_v<Type>;
}

#endif
