#ifndef XIEITE_HEADER__CONCEPTS__ENUMERATOR
#	define XIEITE_HEADER__CONCEPTS__ENUMERATOR

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Enumeration = std::is_enum_v<Type>;
}

#endif
