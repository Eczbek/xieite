#ifndef XIEITE_HEADER__CONCEPTS__BITSET_REFERENCE
#	define XIEITE_HEADER__CONCEPTS__BITSET_REFERENCE

#	include <bitset>
#	include <concepts>
#	include <utility>

namespace xieite::concepts {
	template<typename Type>
	concept BitsetReference = requires(Type value) {
		{ value.~Type() };
		{ value = std::declval<bool>() } -> std::same_as<Type&>;
		{ value = std::declval<Type>() } -> std::same_as<Type&>;
		{ static_cast<bool>(value) } -> std::same_as<bool>;
		{ ~value } -> std::same_as<bool>;
		{ value.flip() } -> std::same_as<Type&>;
	};
}

#endif
