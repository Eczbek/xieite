#ifndef XIEITE_HEADER_CONCEPTS_UNSIGNED_INTEGER
#	define XIEITE_HEADER_CONCEPTS_UNSIGNED_INTEGER

#	include <concepts>
#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept UnsignedInteger = std::unsigned_integral<Type> && !std::same_as<std::remove_cvref_t<Type>, bool>;
}

#endif
