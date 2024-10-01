export module xieite:concepts.DefaultConstructible;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept DefaultConstructible = std::is_default_constructible_v<Type>;
}
