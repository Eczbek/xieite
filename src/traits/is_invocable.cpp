export module xieite:traits.IsInvocable;

import std;

export namespace xieite::traits {
	template<typename, typename>
	struct IsInvocable
	: std::false_type {};

	template<typename Type, typename Return, typename... Arguments>
	struct IsInvocable<Type, Return(Arguments...)>
	: std::is_invocable_r<Return, Type, Arguments...> {};
}
