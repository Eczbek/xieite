#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_REFERENT
#
#	include "../fn/visitor.hpp"
#	include "../meta/type.hpp"
#	include "../trait/rm_cvref.hpp"

namespace xieite {
	template<typename T>
	concept is_noex_referent = xieite::visitor(
		[](...) { return false; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(*)(Args...) noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(*)(Args..., ...) noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) const noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) volatile noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) const volatile noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) & noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) const & noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) volatile & noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) const volatile & noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) && noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) const && noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) volatile && noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) const volatile && noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) const noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) volatile noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) const volatile noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) & noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) const & noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) volatile & noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) const volatile & noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) && noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) const && noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) volatile && noexcept>) { return true; },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) const volatile && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) const noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) volatile noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) const volatile noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) const & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) volatile & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) const volatile & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) const && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) volatile && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) const volatile && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) const noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) volatile noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) const volatile noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) const & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) volatile & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) const volatile & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) const && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) volatile && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) const volatile && noexcept>) { return true; }
	)(xieite::type<xieite::rm_cvref<T>>());
}

#endif

// https://cplusplus.github.io/CWG/issues/2988.html
