#ifndef XIEITE_HEADER_CONCEPTS_INTEGRAL
#	define XIEITE_HEADER_CONCEPTS_INTEGRAL

#	include <concepts>
#	include <type_traits>

namespace xieite::concepts {
	template<typename Type_>
	concept Integral = std::integral<Type_> && !std::same_as<std::remove_cv_t<Type_>, bool>;
}

#endif
