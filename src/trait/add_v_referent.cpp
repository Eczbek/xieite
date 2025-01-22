export module xieite:add_v_referent;

import :cp_cvref;
import :rm_cvref;
import :t;
import :visitor;

export namespace xieite {
	template<typename T>
	using add_v_referent = xieite::cp_cvref<T, typename decltype(xieite::visitor(
		[](...) { return xieite::t<T>(); },
		[]<typename U>(xieite::t<U*>) { return xieite::t<volatile U*>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args...) noexcept(noex)>) { return xieite::t<Ret(S::*)(Args...) volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args..., ...) noexcept(noex)>) { return xieite::t<Ret(S::*)(Args..., ...) volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args...) const noexcept(noex)>) { return xieite::t<Ret(S::*)(Args...) const volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args..., ...) const noexcept(noex)>) { return xieite::t<Ret(S::*)(Args..., ...) const volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args...) & noexcept(noex)>) { return xieite::t<Ret(S::*)(Args...) volatile & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args..., ...) & noexcept(noex)>) { return xieite::t<Ret(S::*)(Args..., ...) volatile & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args...) const & noexcept(noex)>) { return xieite::t<Ret(S::*)(Args...) const volatile & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args..., ...) const & noexcept(noex)>) { return xieite::t<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args...) && noexcept(noex)>) { return xieite::t<Ret(S::*)(Args...) volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args..., ...) && noexcept(noex)>) { return xieite::t<Ret(S::*)(Args..., ...) volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args...) const && noexcept(noex)>) { return xieite::t<Ret(S::*)(Args...) const volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args..., ...) const && noexcept(noex)>) { return xieite::t<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)>(); }
	)(xieite::t<xieite::rm_cvref<T>>()))::type>;
}
