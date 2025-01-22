export module xieite:is_noex_invoc;

import std;
import :t;

export namespace xieite {
	template<typename T, typename Sig = void()>
	concept is_noex_invoc = ([]<typename Ret, typename... Args>(xieite::t<Ret(Args...)>) -> bool {
		return std::is_nothrow_invocable_r_v<Ret, T, Args...>;
	})(xieite::t<Sig>());
}
