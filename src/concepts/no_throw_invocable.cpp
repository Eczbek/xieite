export module xieite:concepts.NoThrowInvocable;

import std;

export namespace xieite::concepts {
	template<typename Type, typename Signature>
	concept NoThrowInvocable = ([]<typename Return, typename... Arguments>(std::type_identity<Return(Arguments...)>) {
		return std::is_nothrow_invocable_r_v<Return, Type, Arguments...>;
	})(std::type_identity<Signature>());
}
