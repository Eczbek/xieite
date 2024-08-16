#ifndef XIEITE_HEADER_CONCEPTS_DESTRUCTIBLE
#	define XIEITE_HEADER_CONCEPTS_DESTRUCTIBLE

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Destructible = std::is_destructible_v<Type>;
}

#endif
