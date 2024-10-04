export module xieite:concepts.Invocable;

import std;

export namespace xieite::concepts {
	template<typename Type, typename Signature>
	concept Invocable = ([]<typename Return, typename... Arguments>(std::type_identity<Return(Arguments...)>) {
		return std::is_invocable_r_v<Return, Type, Arguments...>;
	})(std::type_identity<Signature>());
}

