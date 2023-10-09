#ifndef XIEITE_HEADER__CONCEPTS__UNSIGNED_INTEGER
#	define XIEITE_HEADER__CONCEPTS__UNSIGNED_INTEGER

#	include <concepts>

namespace xieite::concepts {
	template<typename Type>
	concept UnsignedInteger = std::unsigned_integral<Type> && !std::same_as<Type, bool>;
}

#endif
