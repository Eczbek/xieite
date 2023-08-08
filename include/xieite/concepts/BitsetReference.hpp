#ifndef XIEITE_HEADER__CONCEPTS__BITSET_REFERENCE
#	define XIEITE_HEADER__CONCEPTS__BITSET_REFERENCE

#	include <bitset>
#	include <concepts>
#	include <utility>

namespace xieite::concepts {
	template<typename Type>
	concept BitsetReference = requires(Type value) {
		// If it destructs like a std::bitset<N>::reference,
		{ value.~Type() };

		// reassigns like a std::bitset<N>::reference,
		{ value = std::declval<bool>() } -> std::same_as<Type&>;
		{ value = std::declval<Type>() } -> std::same_as<Type&>;

		// casts like a std::bitset<N>::reference,
		{ static_cast<bool>(value) } -> std::same_as<bool>;

		// inverts like a std::bitset<N>::reference,
		{ ~value } -> std::same_as<bool>;

		// and flips like a std::bitset<N>::reference,
		{ value.flip() } -> std::same_as<Type&>;

		// then it just might be a std::bitset<N>::reference.
	};
}

#endif
