export module xieite:concepts.Hashable;

import std;
import :concepts.Invocable;

export namespace xieite::concepts {
	template<typename Type, typename Hasher = std::hash<Type>>
	concept Hashable = xieite::concepts::Invocable<Hasher, std::size_t(Type)>;
}
