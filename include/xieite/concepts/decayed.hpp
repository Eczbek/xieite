#ifndef XIEITE_HEADER__CONCEPTS__DECAYED
#	define XIEITE_HEADER__CONCEPTS__DECAYED

#	include <concepts>
#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Decayed = std::same_as<Type, std::decay_t<Type>>;
}

#endif
