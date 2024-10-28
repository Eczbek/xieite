export module xieite:is_invocable;

import std;

export namespace xieite {
	template<typename T, typename Sig>
	concept is_invocable = ([]<typename Ret, typename... Args>(std::type_identity<Ret(Args...)>) {
		return std::is_invocable_r_v<Ret, T, Args...>;
	})(std::type_identity<Sig>());
}

