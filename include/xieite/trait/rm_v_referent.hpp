#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_V_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_V_REFERENT
#
#	include "../fn/visitor.hpp"
#	include "../meta/type.hpp"
#	include "../trait/cp_cvref.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::rm_v_referent {
	template<typename T>
	struct impl : decltype(xieite::visitor(
		[](...) { return xieite::type<T>(); },
		[]<typename U>(xieite::type<volatile U*>) { return xieite::type<U*>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) volatile noexcept(noex)>) { return xieite::type<Ret(Args...) noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) const volatile noexcept(noex)>) { return xieite::type<Ret(Args...) const noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) volatile & noexcept(noex)>) { return xieite::type<Ret(Args...) & noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) const volatile & noexcept(noex)>) { return xieite::type<Ret(Args...) const & noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) volatile && noexcept(noex)>) { return xieite::type<Ret(Args...) && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) const volatile && noexcept(noex)>) { return xieite::type<Ret(Args...) const && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) volatile noexcept(noex)>) { return xieite::type<Ret(Args..., ...) noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) const volatile noexcept(noex)>) { return xieite::type<Ret(Args..., ...) const noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) volatile & noexcept(noex)>) { return xieite::type<Ret(Args..., ...) & noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) const volatile & noexcept(noex)>) { return xieite::type<Ret(Args..., ...) const & noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) volatile && noexcept(noex)>) { return xieite::type<Ret(Args..., ...) && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) const volatile && noexcept(noex)>) { return xieite::type<Ret(Args..., ...) const && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) volatile noexcept(noex)>) { return xieite::type<Ret(S::*)(Args...) noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) const volatile noexcept(noex)>) { return xieite::type<Ret(S::*)(Args...) const noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) volatile & noexcept(noex)>) { return xieite::type<Ret(S::*)(Args...) & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) const volatile & noexcept(noex)>) { return xieite::type<Ret(S::*)(Args...) const & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) volatile && noexcept(noex)>) { return xieite::type<Ret(S::*)(Args...) && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) const volatile && noexcept(noex)>) { return xieite::type<Ret(S::*)(Args...) const && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) volatile noexcept(noex)>) { return xieite::type<Ret(S::*)(Args..., ...) noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) const volatile noexcept(noex)>) { return xieite::type<Ret(S::*)(Args..., ...) const noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) volatile & noexcept(noex)>) { return xieite::type<Ret(S::*)(Args..., ...) & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)>) { return xieite::type<Ret(S::*)(Args..., ...) const & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) volatile && noexcept(noex)>) { return xieite::type<Ret(S::*)(Args..., ...) && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)>) { return xieite::type<Ret(S::*)(Args..., ...) const && noexcept(noex)>(); }
	)(xieite::type<xieite::rm_cvref<T>>())) {};
}

namespace xieite {
	template<typename T>
	using rm_v_referent = xieite::cp_cvref<T, typename DETAIL_XIEITE::rm_v_referent::impl<T>::type>;
}

#endif
