#ifndef XIEITE_HEADER__CONCEPTS__INTEGER
#	define XIEITE_HEADER__CONCEPTS__INTEGER

#	include <concepts>

namespace xieite::concepts {
	template<typename Type>
	concept Integer = std::integral<Type> && !std::same_as<Type, bool>;
}

#endif
