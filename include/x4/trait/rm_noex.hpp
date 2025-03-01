#pragma once

#include <type_traits>
#include "../fn/visitor.hpp"
#include "../trait/cpcvref.hpp"
#include "../traitrmcvref.hpp"

namespace x4 {
	template<typename T>
	using rmnoex = x4::cpcvref<T, typename decltype(x4::visitor(
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
	)(std::type_identity<x4:rmcvref<T>>()))::type>;
}
