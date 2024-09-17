export module xieite:concepts.Invocable;

import std;

namespace {
	template<typename, typename>
	struct IsInvocable
	: std::false_type {};

	template<typename Type, typename Return, typename... Arguments>
	struct IsInvocable<Type, Return(Arguments...)>
	: std::is_invocable_r<Return, Type, Arguments...> {};
}

export namespace xieite::concepts {
	template<typename Type, typename Signature>
	concept Invocable = IsInvocable<Type, Signature>::value;
}
