#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_REFERENT
#
#	include <type_traits>
#	include "../fn/visitor.hpp"
#	include "../trait/rm_cvref.hpp"

namespace xieite {
	template<typename T>
	concept is_noex_referent = xieite::visitor(
		[](...) { return false; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(*)(Args...) noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(*)(Args..., ...) noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) const noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) volatile noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) const volatile noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) & noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) const & noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) volatile & noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) const volatile & noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) && noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) const && noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) volatile && noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) const volatile && noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) const noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) volatile noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) const volatile noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) & noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) const & noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) volatile & noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) const volatile & noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) && noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) const && noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) volatile && noexcept>) { return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) const volatile && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) volatile noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const volatile noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) volatile & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const volatile & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) volatile && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const volatile && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) volatile noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const volatile noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) volatile & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const volatile & noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) volatile && noexcept>) { return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const volatile && noexcept>) { return true; }
	)(std::type_identity<xieite::rm_cvref<T>>());
}

#endif

// https://cplusplus.github.io/CWG/issues/2988.html
