export module xieite:concepts.Trivial;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept Trivial = std::is_trivial_v<Type>;
}
