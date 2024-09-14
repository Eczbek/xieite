export module xieite:types.MaybeRightValueReference;

import std;

export namespace xieite::types {
	template<typename Type, bool qualified>
	using MaybeRightValueReference = std::conditional_t<qualified, std::remove_reference_t<Type>&&, std::remove_reference_t<Type>>;
}