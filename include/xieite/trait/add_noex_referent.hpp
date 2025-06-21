#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_NOEX_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_NOEX_REFERENT
#
#	include "../fn/visitor.hpp"
#	include "../meta/type.hpp"
#	include "../trait/cp_cvref.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::add_noex_referent {
	template<typename T>
	struct impl : decltype(xieite::visitor(
		[](...) { return xieite::type<T>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(*)(Args...)>) { return xieite::type<Ret(*)(Args...) noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(*)(Args..., ...)>) { return xieite::type<Ret(*)(Args..., ...) noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...)>) { return xieite::type<Ret(Args...) noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) const>) { return xieite::type<Ret(Args...) const noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) volatile>) { return xieite::type<Ret(Args...) volatile noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) const volatile>) { return xieite::type<Ret(Args...) const volatile noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) &>) { return xieite::type<Ret(Args...) & noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) const &>) { return xieite::type<Ret(Args...) const & noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) volatile &>) { return xieite::type<Ret(Args...) volatile & noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) const volatile &>) { return xieite::type<Ret(Args...) const volatile & noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) &&>) { return xieite::type<Ret(Args...) && noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) const &&>) { return xieite::type<Ret(Args...) const && noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) volatile &&>) { return xieite::type<Ret(Args...) volatile && noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args...) const volatile &&>) { return xieite::type<Ret(Args...) const volatile && noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...)>) { return xieite::type<Ret(Args..., ...) noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) const>) { return xieite::type<Ret(Args..., ...) const noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) volatile>) { return xieite::type<Ret(Args..., ...) volatile noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) const volatile>) { return xieite::type<Ret(Args..., ...) const volatile noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) &>) { return xieite::type<Ret(Args..., ...) & noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) const &>) { return xieite::type<Ret(Args..., ...) const & noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) volatile &>) { return xieite::type<Ret(Args..., ...) volatile & noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) const volatile &>) { return xieite::type<Ret(Args..., ...) const volatile & noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) &&>) { return xieite::type<Ret(Args..., ...) && noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) const &&>) { return xieite::type<Ret(Args..., ...) const && noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) volatile &&>) { return xieite::type<Ret(Args..., ...) volatile && noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::type<Ret(Args..., ...) const volatile &&>) { return xieite::type<Ret(Args..., ...) const volatile && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...)>) { return xieite::type<Ret(S::*)(Args...) noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) const>) { return xieite::type<Ret(S::*)(Args...) const noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) volatile>) { return xieite::type<Ret(S::*)(Args...) volatile noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) const volatile>) { return xieite::type<Ret(S::*)(Args...) const volatile noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) &>) { return xieite::type<Ret(S::*)(Args...) & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) const &>) { return xieite::type<Ret(S::*)(Args...) const & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) volatile &>) { return xieite::type<Ret(S::*)(Args...) volatile & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) const volatile &>) { return xieite::type<Ret(S::*)(Args...) const volatile & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) &&>) { return xieite::type<Ret(S::*)(Args...) && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) const &&>) { return xieite::type<Ret(S::*)(Args...) const && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) volatile &&>) { return xieite::type<Ret(S::*)(Args...) volatile && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args...) const volatile &&>) { return xieite::type<Ret(S::*)(Args...) const volatile && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...)>) { return xieite::type<Ret(S::*)(Args..., ...) noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) const>) { return xieite::type<Ret(S::*)(Args..., ...) const noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) volatile>) { return xieite::type<Ret(S::*)(Args..., ...) volatile noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) const volatile>) { return xieite::type<Ret(S::*)(Args..., ...) const volatile noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) &>) { return xieite::type<Ret(S::*)(Args..., ...) & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) const &>) { return xieite::type<Ret(S::*)(Args..., ...) const & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) volatile &>) { return xieite::type<Ret(S::*)(Args..., ...) volatile & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) const volatile &>) { return xieite::type<Ret(S::*)(Args..., ...) const volatile & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) &&>) { return xieite::type<Ret(S::*)(Args..., ...) && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) const &&>) { return xieite::type<Ret(S::*)(Args..., ...) const && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) volatile &&>) { return xieite::type<Ret(S::*)(Args..., ...) volatile && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::type<Ret(S::*)(Args..., ...) const volatile &&>) { return xieite::type<Ret(S::*)(Args..., ...) const volatile && noexcept>(); }
	)(xieite::type<xieite::rm_cvref<T>>())) {};
}

namespace xieite {
	template<typename T>
	using add_noex_referent = xieite::cp_cvref<T, typename DETAIL_XIEITE::add_noex_referent::impl<T>::type>;
}

#endif
