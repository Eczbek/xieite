export module xieite:concepts.NoThrowInvocable;

import std;

namespace {
	template<typename, typename>
	struct IsNoThrowInvocable
	: std::false_type {};

	template<typename Type, typename Return, typename... Arguments>
	struct IsNoThrowInvocable<Type, Return(Arguments...)>
	: std::is_nothrow_invocable_r<Return, Type, Arguments...> {};
}

export namespace xieite::concepts {
	template<typename Functor, typename Signature>
	concept NoThrowInvocable = IsNoThrowInvocable<Functor, Signature>::value;
}
