#ifndef XIEITE_HEADER_CONCEPTS_HASHABLE
#	define XIEITE_HEADER_CONCEPTS_HASHABLE

#	include <concepts>
#	include <cstddef>
#	include <functional>

namespace xieite::concepts {
	template<typename Type_, typename Hasher_ = std::hash<Type_>>
	concept Hashable = requires(Type_ value, Hasher_ hasher) {
		{ std::invoke(hasher, value) } -> std::convertible_to<std::size_t>;
	};
}

#endif
