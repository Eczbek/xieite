#ifndef XIEITE_HEADER_CONCEPTS_TRIVIALLY_DESTRUCTIBLE
#	define XIEITE_HEADER_CONCEPTS_TRIVIALLY_DESTRUCTIBLE

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type_>
	concept TriviallyDestructible = std::is_trivially_destructible_v<Type_>;
}

#endif
