export module xieite:traits.IsHasher;

import std;
import :concepts.Hasher;

export namespace xieite::traits {
	template<typename Type, typename Argument>
	struct IsHasher
	: std::bool_constant<xieite::concepts::Hasher<Type, Argument>> {};
}
