export module xieite:traits.IsBraceInitializable;

import std;
import :concepts.BraceInitializable;

export namespace xieite::traits {
	template<typename Type, typename... Arguments>
	struct IsBraceInitializable
	: std::bool_constant<xieite::concepts::BraceInitializable<Type, Arguments...>> {};
}
