export module xieite:types.MaybeConstant;

import std;
import :types.CopyReference;

export namespace xieite::types {
	template<typename Type, bool qualified>
	using MaybeConstant = xieite::types::CopyReference<Type, std::conditional_t<qualified, const std::remove_reference_t<Type>, std::remove_const_t<std::remove_reference_t<Type>>>>;
}
