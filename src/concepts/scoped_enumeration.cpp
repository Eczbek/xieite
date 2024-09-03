export module xieite:concepts.ScopedEnumeration;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept ScopedEnumeration = std::is_scoped_enum_v<Type>;
}
