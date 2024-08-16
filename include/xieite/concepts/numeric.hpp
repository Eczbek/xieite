#ifndef XIEITE_HEADER_CONCEPTS_NUMERIC
#	define XIEITE_HEADER_CONCEPTS_NUMERIC

#	include <concepts>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept Numeric = xieite::concepts::Arithmetic<Type> && !std::same_as<std::remove_cv_t<Type>, bool>;
}

#endif
