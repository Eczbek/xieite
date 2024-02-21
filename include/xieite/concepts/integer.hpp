#ifndef XIEITE_HEADER_CONCEPTS_INTEGER
#	define XIEITE_HEADER_CONCEPTS_INTEGER

#	include <concepts>
#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Integer = std::integral<Type> && !std::same_as<std::remove_cv_t<Type>, bool>;
}

#endif
