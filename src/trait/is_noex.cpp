export module xieite:is_noex;

import :rm_cvref;
import :t;
import :visitor;

export namespace xieite {
	template<typename T>
	concept is_noex = xieite::visitor(
		[](...) { return false; },
		[]<typename Ret, typename... Args>(xieite::t<Ret(Args...) noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::t<Ret(Args..., ...) noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::t<Ret(*)(Args...) noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::t<Ret(*)(Args..., ...) noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) volatile noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) volatile noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const volatile noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const volatile noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) volatile & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) volatile & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const volatile & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const volatile & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) volatile && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) volatile && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const volatile && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const volatile && noexcept>) { return true; }
	)(xieite::t<xieite::rm_cvref<T>>());
}
