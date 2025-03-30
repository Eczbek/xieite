#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_NOEX_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_NOEX_REFERENT
#
#	include <type_traits>
#	include "../fn/visitor.hpp"
#	include "../trait/cp_cvref.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::rm_noex_referent {
	template<typename T>
	struct impl : decltype(xieite::visitor(
		[](...) static { return std::type_identity<T>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) noexcept>) static { return std::type_identity<Ret(Args...)>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) noexcept>) static { return std::type_identity<Ret(Args..., ...)>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(*)(Args...) noexcept>) static { return std::type_identity<Ret(*)(Args...)>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(*)(Args..., ...) noexcept>) static { return std::type_identity<Ret(*)(Args..., ...)>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) noexcept>) static { return std::type_identity<Ret(S::*)(Args...)>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) noexcept>) static { return std::type_identity<Ret(S::*)(Args..., ...)>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const noexcept>) static { return std::type_identity<Ret(S::*)(Args...) const>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const noexcept>) static { return std::type_identity<Ret(S::*)(Args..., ...) const>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) volatile noexcept>) static { return std::type_identity<Ret(S::*)(Args...) volatile>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) volatile noexcept>) static { return std::type_identity<Ret(S::*)(Args..., ...) volatile>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const volatile noexcept>) static { return std::type_identity<Ret(S::*)(Args...) const volatile>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const volatile noexcept>) static { return std::type_identity<Ret(S::*)(Args..., ...) const volatile>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) & noexcept>) static { return std::type_identity<Ret(S::*)(Args...) &>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) & noexcept>) static { return std::type_identity<Ret(S::*)(Args..., ...) &>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const & noexcept>) static { return std::type_identity<Ret(S::*)(Args...) const &>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const & noexcept>) static { return std::type_identity<Ret(S::*)(Args..., ...) const &>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) volatile & noexcept>) static { return std::type_identity<Ret(S::*)(Args...) volatile &>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) volatile & noexcept>) static { return std::type_identity<Ret(S::*)(Args..., ...) volatile &>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const volatile & noexcept>) static { return std::type_identity<Ret(S::*)(Args...) const volatile &>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const volatile & noexcept>) static { return std::type_identity<Ret(S::*)(Args..., ...) const volatile &>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) && noexcept>) static { return std::type_identity<Ret(S::*)(Args...) &&>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) && noexcept>) static { return std::type_identity<Ret(S::*)(Args..., ...) &&>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const && noexcept>) static { return std::type_identity<Ret(S::*)(Args...) const &&>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const && noexcept>) static { return std::type_identity<Ret(S::*)(Args..., ...) const &&>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) volatile && noexcept>) static { return std::type_identity<Ret(S::*)(Args...) volatile &&>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) volatile && noexcept>) static { return std::type_identity<Ret(S::*)(Args..., ...) volatile &&>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const volatile && noexcept>) static { return std::type_identity<Ret(S::*)(Args...) const volatile &&>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const volatile && noexcept>) static { return std::type_identity<Ret(S::*)(Args..., ...) const volatile &&>(); }
	)(std::type_identity<xieite::rm_cvref<T>>())) {};
}

namespace xieite {
	template<typename T>
	using rm_noex_referent = xieite::cp_cvref<T, typename DETAIL_XIEITE::rm_noex_referent::impl<T>::type>;
}

#endif
