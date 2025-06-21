#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_V_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_V_REFERENT
#
#	include "../fn/visitor.hpp"
#	include "../meta/type.hpp"
#	include "../trait/cp_cvref.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::add_v_referent {
	template<typename T>
	struct impl : decltype(xieite::visitor(
		[](...) { return xieite::type<T>(); },
		[]<typename U>(xieite::type<U*>) { return xieite::type<const U*>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) noexcept(noex)>) { return xieite::type<Ret(Args...) volatile noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) const noexcept(noex)>) { return xieite::type<Ret(Args...) const volatile noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) & noexcept(noex)>) { return xieite::type<Ret(Args...) volatile & noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) const & noexcept(noex)>) { return xieite::type<Ret(Args...) const volatile & noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) && noexcept(noex)>) { return xieite::type<Ret(Args...) volatile && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) const && noexcept(noex)>) { return xieite::type<Ret(Args...) const volatile && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) noexcept(noex)>) { return xieite::type<Ret(Args..., ...) volatile noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) const noexcept(noex)>) { return xieite::type<Ret(Args..., ...) const volatile noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) & noexcept(noex)>) { return xieite::type<Ret(Args..., ...) volatile & noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) const & noexcept(noex)>) { return xieite::type<Ret(Args..., ...) const volatile & noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) && noexcept(noex)>) { return xieite::type<Ret(Args..., ...) volatile && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) const && noexcept(noex)>) { return xieite::type<Ret(Args..., ...) const volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) noexcept(noex)>) { return xieite::type<Ret(S::*)(Args...) volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) const noexcept(noex)>) { return xieite::type<Ret(S::*)(Args...) const volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) & noexcept(noex)>) { return xieite::type<Ret(S::*)(Args...) volatile & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) const & noexcept(noex)>) { return xieite::type<Ret(S::*)(Args...) const volatile & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) && noexcept(noex)>) { return xieite::type<Ret(S::*)(Args...) volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) const && noexcept(noex)>) { return xieite::type<Ret(S::*)(Args...) const volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) noexcept(noex)>) { return xieite::type<Ret(S::*)(Args..., ...) volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) const noexcept(noex)>) { return xieite::type<Ret(S::*)(Args..., ...) const volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) & noexcept(noex)>) { return xieite::type<Ret(S::*)(Args..., ...) volatile & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) const & noexcept(noex)>) { return xieite::type<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) && noexcept(noex)>) { return xieite::type<Ret(S::*)(Args..., ...) volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) const && noexcept(noex)>) { return xieite::type<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)>(); }
	)(xieite::type<xieite::rm_cvref<T>>())) {};
}

namespace xieite {
	template<typename T>
	using add_v_referent = xieite::cp_cvref<T, typename DETAIL_XIEITE::add_v_referent::impl<T>::type>;
}

#endif
