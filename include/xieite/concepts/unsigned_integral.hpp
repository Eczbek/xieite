#ifndef XIEITE_HEADER_CONCEPTS_UNSIGNED_INTEGRAL
#	define XIEITE_HEADER_CONCEPTS_UNSIGNED_INTEGRAL

#	include <concepts>
#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept UnsignedIntegral = std::unsigned_integral<std::remove_cv_t<Type>> && !std::same_as<std::remove_cv_t<Type>, bool>;
}

#endif
