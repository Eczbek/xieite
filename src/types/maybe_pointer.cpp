export module xieite:types.MaybePointer;

import std;
import :types.CopyReference;

export namespace xieite::types {
	template<typename Type, bool value>
	using MaybePointer = xieite::types::CopyReference<Type, std::conditional_t<value, std::remove_pointer_t<std::remove_reference_t<Type>>*, std::remove_pointer_t<std::remove_reference_t<Type>>>>;
}
