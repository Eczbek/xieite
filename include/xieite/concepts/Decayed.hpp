#ifndef XIEITE_HEADER_CONCEPTS_DECAYED
#	define XIEITE_HEADER_CONCEPTS_DECAYED

#	include <concepts>
#	include <type_traits>

namespace xieite::concepts {
	template<typename Any>
	concept Decayed = std::same_as<Any, std::decay_t<Any>>;
}

#endif
