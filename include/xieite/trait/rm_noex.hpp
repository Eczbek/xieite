#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_NOEX
#
#	include <type_traits>
#	include "../fn/visitor.hpp"
#	include "../trait/cp_cvref.hpp"
#	include "../trait/rm_cvref.hpp"

namespace xieite {
	template<typename T>
	using rm_noex = xieite::cp_cvref<T, typename decltype(xieite::visitor(
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
	)(std::type_identity<xieite::rm_cvref<T>>()))::type>;
}

#endif
