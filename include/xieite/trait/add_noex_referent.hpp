#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_NOEX_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_NOEX_REFERENT
#
#	include <type_traits>
#	include "../fn/visitor.hpp"
#	include "../trait/cp_cvref.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::add_noex_referent {
	template<typename T>
	struct impl : decltype(xieite::visitor(
		[](...) { return std::type_identity<T>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(*)(Args...)>) { return std::type_identity<Ret(*)(Args...) noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(*)(Args..., ...)>) { return std::type_identity<Ret(*)(Args..., ...) noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...)>) { return std::type_identity<Ret(Args...) noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) const>) { return std::type_identity<Ret(Args...) const noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) volatile>) { return std::type_identity<Ret(Args...) volatile noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) const volatile>) { return std::type_identity<Ret(Args...) const volatile noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) &>) { return std::type_identity<Ret(Args...) & noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) const &>) { return std::type_identity<Ret(Args...) const & noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) volatile &>) { return std::type_identity<Ret(Args...) volatile & noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) const volatile &>) { return std::type_identity<Ret(Args...) const volatile & noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) &&>) { return std::type_identity<Ret(Args...) && noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) const &&>) { return std::type_identity<Ret(Args...) const && noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) volatile &&>) { return std::type_identity<Ret(Args...) volatile && noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) const volatile &&>) { return std::type_identity<Ret(Args...) const volatile && noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...)>) { return std::type_identity<Ret(Args..., ...) noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) const>) { return std::type_identity<Ret(Args..., ...) const noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) volatile>) { return std::type_identity<Ret(Args..., ...) volatile noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) const volatile>) { return std::type_identity<Ret(Args..., ...) const volatile noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) &>) { return std::type_identity<Ret(Args..., ...) & noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) const &>) { return std::type_identity<Ret(Args..., ...) const & noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) volatile &>) { return std::type_identity<Ret(Args..., ...) volatile & noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) const volatile &>) { return std::type_identity<Ret(Args..., ...) const volatile & noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) &&>) { return std::type_identity<Ret(Args..., ...) && noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) const &&>) { return std::type_identity<Ret(Args..., ...) const && noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) volatile &&>) { return std::type_identity<Ret(Args..., ...) volatile && noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) const volatile &&>) { return std::type_identity<Ret(Args..., ...) const volatile && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...)>) { return std::type_identity<Ret(S::*)(Args...) noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const>) { return std::type_identity<Ret(S::*)(Args...) const noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) volatile>) { return std::type_identity<Ret(S::*)(Args...) volatile noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const volatile>) { return std::type_identity<Ret(S::*)(Args...) const volatile noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) &>) { return std::type_identity<Ret(S::*)(Args...) & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const &>) { return std::type_identity<Ret(S::*)(Args...) const & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) volatile &>) { return std::type_identity<Ret(S::*)(Args...) volatile & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const volatile &>) { return std::type_identity<Ret(S::*)(Args...) const volatile & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) &&>) { return std::type_identity<Ret(S::*)(Args...) && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const &&>) { return std::type_identity<Ret(S::*)(Args...) const && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) volatile &&>) { return std::type_identity<Ret(S::*)(Args...) volatile && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const volatile &&>) { return std::type_identity<Ret(S::*)(Args...) const volatile && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...)>) { return std::type_identity<Ret(S::*)(Args..., ...) noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const>) { return std::type_identity<Ret(S::*)(Args..., ...) const noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) volatile>) { return std::type_identity<Ret(S::*)(Args..., ...) volatile noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const volatile>) { return std::type_identity<Ret(S::*)(Args..., ...) const volatile noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) &>) { return std::type_identity<Ret(S::*)(Args..., ...) & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const &>) { return std::type_identity<Ret(S::*)(Args..., ...) const & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) volatile &>) { return std::type_identity<Ret(S::*)(Args..., ...) volatile & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const volatile &>) { return std::type_identity<Ret(S::*)(Args..., ...) const volatile & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) &&>) { return std::type_identity<Ret(S::*)(Args..., ...) && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const &&>) { return std::type_identity<Ret(S::*)(Args..., ...) const && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) volatile &&>) { return std::type_identity<Ret(S::*)(Args..., ...) volatile && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const volatile &&>) { return std::type_identity<Ret(S::*)(Args..., ...) const volatile && noexcept>(); }
	)(std::type_identity<xieite::rm_cvref<T>>())) {};
}

namespace xieite {
	template<typename T>
	using add_noex_referent = xieite::cp_cvref<T, typename DETAIL_XIEITE::add_noex_referent::impl<T>::type>;
}

#endif
