export module xieite:concepts.TriviallyDestructible;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept TriviallyDestructible = std::is_trivially_destructible_v<Type>;
}
