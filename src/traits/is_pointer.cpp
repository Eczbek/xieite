export module xieite:traits.IsPointer;

import std;
import :concepts.Pointer;

export namespace xieite::traits {
	template<typename Type>
	struct IsPointer
	: std::bool_constant<xieite::concepts::Pointer<Type>> {};
}
