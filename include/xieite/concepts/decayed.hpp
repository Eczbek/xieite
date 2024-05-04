#ifndef XIEITE_HEADER_CONCEPTS_DECAYED
#	define XIEITE_HEADER_CONCEPTS_DECAYED

#	include <concepts>
#	include <type_traits>

namespace xieite::concepts {
	template<typename Type_>
	concept Decayed = std::same_as<Type_, std::decay_t<Type_>>;
}

#endif
