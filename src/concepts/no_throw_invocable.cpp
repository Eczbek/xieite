export module xieite:concepts.NoThrowInvocable;

import :traits.IsNoThrowInvocable;

export namespace xieite::concepts {
	template<typename Functor, typename Signature>
	concept NoThrowInvocable = xieite::traits::IsNoThrowInvocable<Functor, Signature>::value;
}
