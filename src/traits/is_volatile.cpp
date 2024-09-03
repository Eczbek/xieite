export module xieite:traits.IsVolatile;

import std;
import :concepts.Volatile;

export namespace xieite::traits {
	template<typename Type>
	struct IsVolatile
	: std::bool_constant<xieite::concepts::Volatile<Type>> {};
}
