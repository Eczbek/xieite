#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_V_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_V_REFERENT
#
#	include "../fn/visitor.hpp"
#	include "../meta/type.hpp"
#	include "../trait/rm_cvref.hpp"

namespace xieite {
	template<typename T>
	concept is_v_referent = xieite::visitor(
		[](...) { return false; },
		[]<typename U>(xieite::type<volatile U*>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) volatile noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) const volatile noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) volatile & noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) const volatile & noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) volatile && noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) const volatile && noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) volatile noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) const volatile noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) volatile & noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) const volatile & noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) volatile && noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) const volatile && noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) volatile noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) const volatile noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) volatile & noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) const volatile & noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) volatile && noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) const volatile && noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) volatile noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) const volatile noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) volatile & noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) volatile && noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)>) { return true; }
	)(xieite::type<xieite::rm_cvref<T>>());
}

#endif

// https://cplusplus.github.io/CWG/issues/2988.html
