export module xieite:concepts.Enumeration;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept Enumeration = std::is_enum_v<Type>;
}
