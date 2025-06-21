#ifndef DETAIL_XIEITE_HEADER_TRAIT_GET_FN_RET
#	define DETAIL_XIEITE_HEADER_TRAIT_GET_FN_RET
#
#	include "../fn/visitor.hpp"
#	include "../meta/type.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::get_fn_ret {
	template<typename T>
	struct impl : decltype(xieite::visitor(
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(*)(Args...) noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(*)(Args..., ...) noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) const noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) volatile noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) const volatile noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) & noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) const & noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) volatile & noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) const volatile & noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) && noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) const && noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) volatile && noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args...) const volatile && noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) const noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) volatile noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) const volatile noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) & noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) const & noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) volatile & noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) const volatile & noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) && noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) const && noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) volatile && noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(xieite::type<Ret(Args..., ...) const volatile && noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) const noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) volatile noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) const volatile noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) & noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) const & noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) volatile & noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) const volatile & noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) && noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) const && noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) volatile && noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args...) const volatile && noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) const noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) volatile noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) const volatile noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) & noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) const & noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) volatile & noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) && noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) const && noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) volatile && noexcept(noex)>) { return xieite::type<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::type<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)>) { return xieite::type<Ret>(); }
	)(xieite::type<xieite::rm_cvref<T>>())) {};
}

namespace xieite {
	template<typename T>
	using get_fn_ret = DETAIL_XIEITE::get_fn_ret::impl<T>::type;
}

#endif
