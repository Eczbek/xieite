#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_C_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_C_REFERENT
#
#	include <type_traits>
#	include "../fn/visitor.hpp"
#	include "../trait/rm_cvref.hpp"

namespace xieite {
	template<typename T>
	concept is_c_referent = xieite::visitor(
		[](...) { return false; },
		[]<typename U>(std::type_identity<const U*>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const volatile noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const & noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const volatile & noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const && noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const volatile && noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const volatile noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const & noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const volatile & noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const && noexcept(noex)>) { return true; },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const volatile && noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const volatile noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const & noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const volatile & noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const && noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const volatile && noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const volatile noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const & noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const && noexcept(noex)>) { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)>) { return true; }
	)(std::type_identity<xieite::rm_cvref<T>>());
}

#endif

// https://cplusplus.github.io/CWG/issues/2988.html
