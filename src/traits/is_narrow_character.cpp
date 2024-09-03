export module xieite:traits.IsNarrowCharacter;

import std;
import :concepts.NarrowCharacter;

export namespace xieite::traits {
	template<typename Type>
	struct IsNarrowCharacter
	: std::bool_constant<xieite::concepts::NarrowCharacter<Type>> {};
}
