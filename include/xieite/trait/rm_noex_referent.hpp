#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_NOEX_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_NOEX_REFERENT
#
#	include "../fn/visitor.hpp"
#	include "../meta/type.hpp"
#	include "../trait/cp_cvref.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::rm_noex_referent {
	template<typename T>
	struct impl : decltype(xieite::visitor(
		[](...) { return xieite::type<T>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(*)(Args...) noexcept>) { return xieite::type<Ret(*)(Args...)>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(*)(Args..., ...) noexcept>) { return xieite::type<Ret(*)(Args..., ...)>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) noexcept>) { return xieite::type<Ret(Args...)>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) const noexcept>) { return xieite::type<Ret(Args...) const>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) volatile noexcept>) { return xieite::type<Ret(Args...) volatile>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) const volatile noexcept>) { return xieite::type<Ret(Args...) const volatile>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) & noexcept>) { return xieite::type<Ret(Args...) &>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) const & noexcept>) { return xieite::type<Ret(Args...) const &>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) volatile & noexcept>) { return xieite::type<Ret(Args...) volatile &>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) const volatile & noexcept>) { return xieite::type<Ret(Args...) const volatile &>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) && noexcept>) { return xieite::type<Ret(Args...) &&>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) const && noexcept>) { return xieite::type<Ret(Args...) const &&>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) volatile && noexcept>) { return xieite::type<Ret(Args...) volatile &&>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) const volatile && noexcept>) { return xieite::type<Ret(Args...) const volatile &&>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) noexcept>) { return xieite::type<Ret(Args..., ...)>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) const noexcept>) { return xieite::type<Ret(Args..., ...) const>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) volatile noexcept>) { return xieite::type<Ret(Args..., ...) volatile>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) const volatile noexcept>) { return xieite::type<Ret(Args..., ...) const volatile>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) & noexcept>) { return xieite::type<Ret(Args..., ...) &>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) const & noexcept>) { return xieite::type<Ret(Args..., ...) const &>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) volatile & noexcept>) { return xieite::type<Ret(Args..., ...) volatile &>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) const volatile & noexcept>) { return xieite::type<Ret(Args..., ...) const volatile &>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) && noexcept>) { return xieite::type<Ret(Args..., ...) &&>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) const && noexcept>) { return xieite::type<Ret(Args..., ...) const &&>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) volatile && noexcept>) { return xieite::type<Ret(Args..., ...) volatile &&>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) const volatile && noexcept>) { return xieite::type<Ret(Args..., ...) const volatile &&>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) noexcept>) { return xieite::type<Ret(S::*)(Args...)>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) const noexcept>) { return xieite::type<Ret(S::*)(Args...) const>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) volatile noexcept>) { return xieite::type<Ret(S::*)(Args...) volatile>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) const volatile noexcept>) { return xieite::type<Ret(S::*)(Args...) const volatile>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) & noexcept>) { return xieite::type<Ret(S::*)(Args...) &>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) const & noexcept>) { return xieite::type<Ret(S::*)(Args...) const &>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) volatile & noexcept>) { return xieite::type<Ret(S::*)(Args...) volatile &>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) const volatile & noexcept>) { return xieite::type<Ret(S::*)(Args...) const volatile &>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) && noexcept>) { return xieite::type<Ret(S::*)(Args...) &&>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) const && noexcept>) { return xieite::type<Ret(S::*)(Args...) const &&>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) volatile && noexcept>) { return xieite::type<Ret(S::*)(Args...) volatile &&>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) const volatile && noexcept>) { return xieite::type<Ret(S::*)(Args...) const volatile &&>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) noexcept>) { return xieite::type<Ret(S::*)(Args..., ...)>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) const noexcept>) { return xieite::type<Ret(S::*)(Args..., ...) const>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) volatile noexcept>) { return xieite::type<Ret(S::*)(Args..., ...) volatile>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) const volatile noexcept>) { return xieite::type<Ret(S::*)(Args..., ...) const volatile>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) & noexcept>) { return xieite::type<Ret(S::*)(Args..., ...) &>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) const & noexcept>) { return xieite::type<Ret(S::*)(Args..., ...) const &>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) volatile & noexcept>) { return xieite::type<Ret(S::*)(Args..., ...) volatile &>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) const volatile & noexcept>) { return xieite::type<Ret(S::*)(Args..., ...) const volatile &>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) && noexcept>) { return xieite::type<Ret(S::*)(Args..., ...) &&>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) const && noexcept>) { return xieite::type<Ret(S::*)(Args..., ...) const &&>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) volatile && noexcept>) { return xieite::type<Ret(S::*)(Args..., ...) volatile &&>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) const volatile && noexcept>) { return xieite::type<Ret(S::*)(Args..., ...) const volatile &&>(); }
	)(xieite::type<xieite::rm_cvref<T>>())) {};
}

namespace xieite {
	template<typename T>
	using rm_noex_referent = xieite::cp_cvref<T, typename DETAIL_XIEITE::rm_noex_referent::impl<T>::type>;
}

#endif
