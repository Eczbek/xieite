export module xieite:concepts.Decayed;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept Decayed = std::same_as<Type, std::decay_t<Type>>;
}
