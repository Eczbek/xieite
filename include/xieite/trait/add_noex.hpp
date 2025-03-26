#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_NOEX
#
#	include <type_traits>
#	include "../fn/visitor.hpp"
#	include "../trait/cp_cvref.hpp"
#	include "../trait/rm_cvref.hpp"

namespace xieite {
	template<typename T>
	using add_noex = xieite::cp_cvref<T, typename decltype(xieite::visitor(
		[](...) static { return std::type_identity<T>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...)>) static { return std::type_identity<Ret(Args...) noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...)>) static { return std::type_identity<Ret(Args..., ...) noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(*)(Args...)>) static { return std::type_identity<Ret(*)(Args...) noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(*)(Args..., ...)>) static { return std::type_identity<Ret(*)(Args..., ...) noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...)>) static { return std::type_identity<Ret(S::*)(Args...) noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...)>) static { return std::type_identity<Ret(S::*)(Args..., ...) noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const>) static { return std::type_identity<Ret(S::*)(Args...) const noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const>) static { return std::type_identity<Ret(S::*)(Args..., ...) const noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) volatile>) static { return std::type_identity<Ret(S::*)(Args...) volatile noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) volatile>) static { return std::type_identity<Ret(S::*)(Args..., ...) volatile noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const volatile>) static { return std::type_identity<Ret(S::*)(Args...) const volatile noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const volatile>) static { return std::type_identity<Ret(S::*)(Args..., ...) const volatile noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) &>) static { return std::type_identity<Ret(S::*)(Args...) & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) &>) static { return std::type_identity<Ret(S::*)(Args..., ...) & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const &>) static { return std::type_identity<Ret(S::*)(Args...) const & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const &>) static { return std::type_identity<Ret(S::*)(Args..., ...) const & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) volatile &>) static { return std::type_identity<Ret(S::*)(Args...) volatile & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) volatile &>) static { return std::type_identity<Ret(S::*)(Args..., ...) volatile & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const volatile &>) static { return std::type_identity<Ret(S::*)(Args...) const volatile & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const volatile &>) static { return std::type_identity<Ret(S::*)(Args..., ...) const volatile & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) &&>) static { return std::type_identity<Ret(S::*)(Args...) && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) &&>) static { return std::type_identity<Ret(S::*)(Args..., ...) && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const &&>) static { return std::type_identity<Ret(S::*)(Args...) const && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const &&>) static { return std::type_identity<Ret(S::*)(Args..., ...) const && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) volatile &&>) static { return std::type_identity<Ret(S::*)(Args...) volatile && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) volatile &&>) static { return std::type_identity<Ret(S::*)(Args..., ...) volatile && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const volatile &&>) static { return std::type_identity<Ret(S::*)(Args...) const volatile && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const volatile &&>) static { return std::type_identity<Ret(S::*)(Args..., ...) const volatile && noexcept>(); }
	)(std::type_identity<xieite::rm_cvref<T>>()))::type>;
}

#endif
