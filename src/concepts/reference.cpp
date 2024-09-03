export module xieite:concepts.Reference;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept Reference = std::is_reference_v<Type>;
}
