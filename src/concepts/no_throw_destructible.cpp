export module xieite:concepts.NoThrowDestructible;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept NoThrowDestructible = std::is_nothrow_destructible_v<Type>;
}
