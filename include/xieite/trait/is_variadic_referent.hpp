#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VARIADIC_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VARIADIC_REFERENT
#
#	include <type_traits>
#	include "../fn/visitor.hpp"
#	include "../trait/rm_cvref.hpp"

namespace xieite {
	template<typename T>
	concept is_variadic_referent = xieite::visitor(
		[](...) { return false; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(*)(Args..., ...) noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) volatile noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const volatile noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) & noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const & noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) volatile & noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const volatile & noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) && noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const && noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) volatile && noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const volatile && noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) volatile noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const volatile noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) & noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const & noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) volatile & noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) && noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const && noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) volatile && noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)>) { return true; }
	)(std::type_identity<xieite::rm_cvref<T>>());
}

#endif

// https://cplusplus.github.io/CWG/issues/2988.html
