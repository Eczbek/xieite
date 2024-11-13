export module xieite:is_bitset_ref;

import std;

export namespace xieite {
	template<typename T>
	concept is_bitset_ref = requires(T value) {
		value.~T(); // TODO: Use `std::is_destructible`?
		{ value = true } -> std::same_as<T&>;
		{ value = value } -> std::same_as<T&>;
		value.operator bool();
		{ ~value } -> std::same_as<bool>;
		{ value.flip() } -> std::same_as<T&>;
	};
}
