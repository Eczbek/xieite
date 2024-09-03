export module xieite:traits.IsOrdinaryCharacter;

import std;
import :concepts.OrdinaryCharacter;

export namespace xieite::traits {
	template<typename Type>
	struct IsOrdinaryCharacter
	: std::bool_constant<xieite::concepts::OrdinaryCharacter<Type>> {};
}
