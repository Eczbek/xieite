export module xieite:traits.IsDerivable;

import std;
import :concepts.Derivable;

export namespace xieite::traits {
	template<typename Type>
	struct IsDerivable
	: std::bool_constant<xieite::concepts::Derivable<Type>> {};
}
