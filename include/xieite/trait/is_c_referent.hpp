#pragma once

#include <type_traits>
#include "../fn/visitor.hpp"
#include "../trait/rm_cvref.hpp"

namespace xieite {
	template<typename T>
	concept is_c_referent = xieite::visitor(
		[](...) static { return false; },
		[]<typename U>(std::type_identity<const U*>) static { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const noexcept(noex)>) static { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const noexcept(noex)>) static { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const volatile noexcept(noex)>) static { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const volatile noexcept(noex)>) static { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const & noexcept(noex)>) static { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const & noexcept(noex)>) static { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const volatile & noexcept(noex)>) static { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)>) static { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const && noexcept(noex)>) static { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const && noexcept(noex)>) static { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const volatile && noexcept(noex)>) static { return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)>) static { return true; }
	)(std::type_identity<xieite::rm_cvref<T>>());
}
