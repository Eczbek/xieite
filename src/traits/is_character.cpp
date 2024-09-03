export module xieite:traits.IsCharacter;

import std;
import :concepts.Character;

export namespace xieite::traits {
	template<typename Type>
	struct IsCharacter
	: std::bool_constant<xieite::concepts::Character<Type>> {};
}
