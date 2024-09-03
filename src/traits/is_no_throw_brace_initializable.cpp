export module xieite:traits.IsNoThrowBraceInitializable;

import std;
import :concepts.NoThrowBraceInitializable;

export namespace xieite::traits {
	template<typename Type, typename... Arguments>
	struct IsNoThrowBraceInitializable
	: std::bool_constant<xieite::concepts::NoThrowBraceInitializable<Type, Arguments...>> {};
}
