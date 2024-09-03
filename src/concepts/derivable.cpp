export module xieite:concepts.Derivable;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept Derivable = !std::is_final_v<Type>;
}
