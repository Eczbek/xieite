#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_RREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_RREF_REFERENT
#
#	include "../fn/visitor.hpp"
#	include "../meta/type.hpp"
#	include "../trait/cp_cvref.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::add_rref_referent {
	template<typename T>
	struct impl : decltype(xieite::visitor(
		[](...) { return xieite::type<T>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) noexcept(noex)>) { return xieite::type<Ret(Args...) && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) const noexcept(noex)>) { return xieite::type<Ret(Args...) const && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) volatile noexcept(noex)>) { return xieite::type<Ret(Args...) volatile && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) const volatile noexcept(noex)>) { return xieite::type<Ret(Args...) const volatile && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) & noexcept(noex)>) { return xieite::type<Ret(Args...) noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) const & noexcept(noex)>) { return xieite::type<Ret(Args...) const noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) volatile & noexcept(noex)>) { return xieite::type<Ret(Args...) volatile noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) const volatile & noexcept(noex)>) { return xieite::type<Ret(Args...) const volatile noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) noexcept(noex)>) { return xieite::type<Ret(Args..., ...) && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) const noexcept(noex)>) { return xieite::type<Ret(Args..., ...) const && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) volatile noexcept(noex)>) { return xieite::type<Ret(Args..., ...) volatile && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) const volatile noexcept(noex)>) { return xieite::type<Ret(Args..., ...) const volatile && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) & noexcept(noex)>) { return xieite::type<Ret(Args..., ...) noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) const & noexcept(noex)>) { return xieite::type<Ret(Args..., ...) const noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) volatile & noexcept(noex)>) { return xieite::type<Ret(Args..., ...) volatile noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) const volatile & noexcept(noex)>) { return xieite::type<Ret(Args..., ...) const volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) noexcept(noex)>) { return xieite::type<Ret(S::*)(Args...) && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) const noexcept(noex)>) { return xieite::type<Ret(S::*)(Args...) const && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) volatile noexcept(noex)>) { return xieite::type<Ret(S::*)(Args...) volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) const volatile noexcept(noex)>) { return xieite::type<Ret(S::*)(Args...) const volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) & noexcept(noex)>) { return xieite::type<Ret(S::*)(Args...) noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) const & noexcept(noex)>) { return xieite::type<Ret(S::*)(Args...) const noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) volatile & noexcept(noex)>) { return xieite::type<Ret(S::*)(Args...) volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) const volatile & noexcept(noex)>) { return xieite::type<Ret(S::*)(Args...) const volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) noexcept(noex)>) { return xieite::type<Ret(S::*)(Args..., ...) && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) const noexcept(noex)>) { return xieite::type<Ret(S::*)(Args..., ...) const && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) volatile noexcept(noex)>) { return xieite::type<Ret(S::*)(Args..., ...) volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) const volatile noexcept(noex)>) { return xieite::type<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) & noexcept(noex)>) { return xieite::type<Ret(S::*)(Args..., ...) noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) const & noexcept(noex)>) { return xieite::type<Ret(S::*)(Args..., ...) const noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) volatile & noexcept(noex)>) { return xieite::type<Ret(S::*)(Args..., ...) volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)>) { return xieite::type<Ret(S::*)(Args..., ...) const volatile noexcept(noex)>(); }
	)(xieite::type<xieite::rm_cvref<T>>())) {};
}

namespace xieite {
	template<typename T>
	using add_rref_referent = xieite::cp_cvref<T, typename DETAIL_XIEITE::add_rref_referent::impl<T>::type>;
}

#endif
