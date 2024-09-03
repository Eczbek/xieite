export module xieite:traits.IsNoThrowInvocable;

import std;

export namespace xieite::traits {
	template<typename, typename>
	struct IsNoThrowInvocable
	: std::false_type {};

	template<typename Type, typename Return, typename... Arguments>
	struct IsNoThrowInvocable<Type, Return(Arguments...)>
	: std::is_nothrow_invocable_r<Return, Type, Arguments...> {};
}
