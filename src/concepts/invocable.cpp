export module xieite:concepts.Invocable;

import :traits.IsInvocable;

export namespace xieite::concepts {
	template<typename Type, typename Signature>
	concept Invocable = xieite::traits::IsInvocable<Type, Signature>::value;
}
