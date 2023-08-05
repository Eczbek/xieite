#ifndef XIEITE_HEADER__TRAITS__IS_HASHABLE
#	define XIEITE_HEADER__TRAITS__IS_HASHABLE

#	include <cstddef>
#	include <functional>
#	include <type_traits>

namespace xieite::traits {
	template<typename>
	struct IsHashable
	: std::false_type {};

	template<typename Type>
	requires(requires(Type value) {
		{ std::hash<Type>()(value) } -> std::convertible_to<std::size_t>;
	})
	struct IsHashable<Type>
	: std::true_type {};
}

#endif
