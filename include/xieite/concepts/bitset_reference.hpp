#ifndef XIEITE_HEADER_CONCEPTS_BITSET_REFERENCE
#	define XIEITE_HEADER_CONCEPTS_BITSET_REFERENCE

#	include <bitset>
#	include <concepts>
#	include <utility>

namespace xieite::concepts {
	template<typename Type_>
	concept BitsetReference = requires(Type_ value) {
		value.~Type_(); // TODO: Use `std::is_destructible`?
		{ value = true } -> std::same_as<Type_&>;
		{ value = value } -> std::same_as<Type_&>;
		value.operator bool();
		{ ~value } -> std::same_as<bool>;
		{ value.flip() } -> std::same_as<Type_&>;
	};
}

#endif
