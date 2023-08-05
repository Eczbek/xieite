#ifndef XIEITE_HEADER__TRAITS__IS_BITSET_REFERENCE
#	define XIEITE_HEADER__TRAITS__IS_BITSET_REFERENCE

#	include <bitset>
#	include <concepts>
#	include <type_traits>
#	include <utility>

namespace xieite::traits {
	template<typename>
	struct IsBitsetReference
	: std::false_type {};

	template<typename Type>
	requires(requires(Type value) {
		{ value.~Type() };
		{ value = std::declval<bool>() } -> std::same_as<Type&>;
		{ value = std::declval<Type>() } -> std::same_as<Type&>;
		{ static_cast<bool>(value) } -> std::same_as<bool>;
		{ ~value } -> std::same_as<bool>;
		{ value.flip() } -> std::same_as<Type&>;
	})
	struct IsBitsetReference<Type>
	: std::true_type {};
}

// I stole this from someone and made it better

#endif
