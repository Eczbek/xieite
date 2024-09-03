export module xieite:concepts.UnscopedEnumeration;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept UnscopedEnumeration = std::is_enum_v<Type> && !std::is_scoped_enum_v<Type>;
}
