#ifndef XIEITE_HEADER_CONCEPTS_INTEGRAL
#	define XIEITE_HEADER_CONCEPTS_INTEGRAL

#	include <concepts>
#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Integral = std::integral<Type> && !std::same_as<std::remove_cv_t<Type>, bool>;
}

#endif
