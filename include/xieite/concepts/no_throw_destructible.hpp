#ifndef XIEITE_HEADER_CONCEPTS_NO_THROW_DESTRUCTIBLE
#	define XIEITE_HEADER_CONCEPTS_NO_THROW_DESTRUCTIBLE

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept NoThrowDestructible = std::is_nothrow_destructible_v<Type>;
}

#endif
