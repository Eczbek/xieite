#ifndef XIEITE_HEADER__CONCEPTS__NUMERIC
#	define XIEITE_HEADER__CONCEPTS__NUMERIC

#	include <concepts>
#	include "../concepts/arithmetic.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept Numeric = xieite::concepts::Arithmetic<Type> && !std::same_as<Type, bool>;
}

#endif
