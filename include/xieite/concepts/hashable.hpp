#ifndef XIEITE_HEADER_CONCEPTS_HASHABLE
#	define XIEITE_HEADER_CONCEPTS_HASHABLE

#	include <concepts>
#	include <cstddef>
#	include <functional>
#	include <utility>

namespace xieite::concepts {
	template<typename Type, typename Hasher = std::hash<Type>>
	concept Hashable = requires(Type value, Hasher hasher) {
		{ std::invoke(std::forward<Hasher>(hasher), std::forward<Type>(value)) } -> std::convertible_to<std::size_t>;
	};
}

#endif
