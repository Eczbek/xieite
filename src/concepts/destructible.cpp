export module xieite:concepts.Destructible;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept Destructible = std::is_destructible_v<Type>;
}
