#ifndef XIEITE_HEADER_CONCEPTS_HASHER
#	define XIEITE_HEADER_CONCEPTS_HASHER

#	include <concepts>
#	include <cstddef>
#	include <functional>

namespace xieite::concepts {
	template<typename Type, typename Argument>
	concept Hasher = requires(Type hasher, Argument value) {
		{ std::invoke(hasher, value) } -> std::convertible_to<std::size_t>;
	};
}

#endif
