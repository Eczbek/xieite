export module xieite:concepts.Arithmetic;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept Arithmetic = std::integral<Type> || std::floating_point<Type>;
}
