export module xieite:rm_noex;

import :cp_cvref;
import :rm_cvref;
import :t;
import :visitor;

export namespace xieite {
	template<typename T>
	using rm_noex = xieite::cp_cvref<T, typename decltype(xieite::visitor(
		[](...) { return xieite::t<T>(); },
		[]<typename Ret, typename... Args>(xieite::t<Ret(Args...) noexcept>) { return xieite::t<Ret(Args...)>(); },
		[]<typename Ret, typename... Args>(xieite::t<Ret(Args..., ...) noexcept>) { return xieite::t<Ret(Args..., ...)>(); },
		[]<typename Ret, typename... Args>(xieite::t<Ret(*)(Args...) noexcept>) { return xieite::t<Ret(*)(Args...)>(); },
		[]<typename Ret, typename... Args>(xieite::t<Ret(*)(Args..., ...) noexcept>) { return xieite::t<Ret(*)(Args..., ...)>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) noexcept>) { return xieite::t<Ret(S::*)(Args...)>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) noexcept>) { return xieite::t<Ret(S::*)(Args..., ...)>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const noexcept>) { return xieite::t<Ret(S::*)(Args...) const>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const noexcept>) { return xieite::t<Ret(S::*)(Args..., ...) const>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) volatile noexcept>) { return xieite::t<Ret(S::*)(Args...) volatile>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) volatile noexcept>) { return xieite::t<Ret(S::*)(Args..., ...) volatile>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const volatile noexcept>) { return xieite::t<Ret(S::*)(Args...) const volatile>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const volatile noexcept>) { return xieite::t<Ret(S::*)(Args..., ...) const volatile>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) & noexcept>) { return xieite::t<Ret(S::*)(Args...) &>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) & noexcept>) { return xieite::t<Ret(S::*)(Args..., ...) &>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const & noexcept>) { return xieite::t<Ret(S::*)(Args...) const &>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const & noexcept>) { return xieite::t<Ret(S::*)(Args..., ...) const &>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) volatile & noexcept>) { return xieite::t<Ret(S::*)(Args...) volatile &>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) volatile & noexcept>) { return xieite::t<Ret(S::*)(Args..., ...) volatile &>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const volatile & noexcept>) { return xieite::t<Ret(S::*)(Args...) const volatile &>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const volatile & noexcept>) { return xieite::t<Ret(S::*)(Args..., ...) const volatile &>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) && noexcept>) { return xieite::t<Ret(S::*)(Args...) &&>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) && noexcept>) { return xieite::t<Ret(S::*)(Args..., ...) &&>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const && noexcept>) { return xieite::t<Ret(S::*)(Args...) const &&>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const && noexcept>) { return xieite::t<Ret(S::*)(Args..., ...) const &&>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) volatile && noexcept>) { return xieite::t<Ret(S::*)(Args...) volatile &&>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) volatile && noexcept>) { return xieite::t<Ret(S::*)(Args..., ...) volatile &&>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const volatile && noexcept>) { return xieite::t<Ret(S::*)(Args...) const volatile &&>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const volatile && noexcept>) { return xieite::t<Ret(S::*)(Args..., ...) const volatile &&>(); }
	)(xieite::t<xieite::rm_cvref<T>>()))::type>;
}
