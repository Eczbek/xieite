export module xieite:traits.IsWideCharacter;

import std;
import :concepts.WideCharacter;

export namespace xieite::traits {
	template<typename Type>
	struct IsWideCharacter
	: std::bool_constant<xieite::concepts::WideCharacter<Type>> {};
}
