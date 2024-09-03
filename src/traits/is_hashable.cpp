export module xieite:traits.IsHashable;

import std;
import :concepts.Hashable;

export namespace xieite::traits {
	template<typename Type, typename Hasher = std::hash<Type>>
	struct IsHashable
	: std::bool_constant<xieite::concepts::Hashable<Type, Hasher>> {};
}
