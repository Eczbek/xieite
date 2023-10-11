#ifndef XIEITE_HEADER_CONCEPTS_INTEGER
#	define XIEITE_HEADER_CONCEPTS_INTEGER

#	include <concepts>

namespace xieite::concepts {
	template<typename Type>
	concept Integer = std::integral<Type> && !std::same_as<Type, bool>;
}

#endif
