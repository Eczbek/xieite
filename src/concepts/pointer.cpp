export module xieite:concepts.Pointer;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept Pointer = std::is_pointer_v<std::remove_reference_t<Type>>;
}
