export module xieite:types.MaybeVolatile;

import std;
import :types.CopyReference;

export namespace xieite::types {
	template<typename Type, bool qualified>
	using MaybeVolatile = xieite::types::CopyReference<Type, std::conditional_t<qualified, volatile std::remove_reference_t<Type>, std::remove_volatile_t<std::remove_reference_t<Type>>>>;
}
