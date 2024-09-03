export module xieite:concepts.Volatile;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept Volatile = std::is_volatile_v<std::remove_reference_t<Type>>;
}
