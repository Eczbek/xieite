export module xieite:concepts.BitsetReference;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept BitsetReference = requires(Type value) {
		value.~Type(); // TODO: Use `std::is_destructible`?
		{ value = true } -> std::same_as<Type&>;
		{ value = value } -> std::same_as<Type&>;
		value.operator bool();
		{ ~value } -> std::same_as<bool>;
		{ value.flip() } -> std::same_as<Type&>;
	};
}
