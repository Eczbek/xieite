export module xieite:traits.IsUnscopedEnumeration;

import std;
import :concepts.UnscopedEnumeration;

export namespace xieite::traits {
	template<typename Type>
	struct IsUnscopedEnumeration
	: std::bool_constant<xieite::concepts::UnscopedEnumeration<Type>> {};
}
