#pragma once

#include <type_traits>
#include "../fn/visitor.hpp"
#include "../trait/cpcvref.hpp"
#include "../trait/rmcvref.hpp"

namespace x4 {
	template<typename T>
	using addnoex = x4::cpcvref<T, typename decltype(x4::visitor(
		[](...) static {  return std::type_identity<T>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...)>) static {  return std::type_identity<Ret(Args...) noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...)>) static {  return std::type_identity<Ret(Args..., ...) noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(*)(Args...)>) static {  return std::type_identity<Ret(*)(Args...) noexcept>(); },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(*)(Args..., ...)>) static {  return std::type_identity<Ret(*)(Args..., ...) noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...)>) static {  return std::type_identity<Ret(S::*)(Args...) noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...)>) static {  return std::type_identity<Ret(S::*)(Args..., ...) noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const>) static {  return std::type_identity<Ret(S::*)(Args...) const noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const>) static {  return std::type_identity<Ret(S::*)(Args..., ...) const noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) volatile>) static {  return std::type_identity<Ret(S::*)(Args...) volatile noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) volatile>) static {  return std::type_identity<Ret(S::*)(Args..., ...) volatile noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const volatile>) static {  return std::type_identity<Ret(S::*)(Args...) const volatile noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const volatile>) static {  return std::type_identity<Ret(S::*)(Args..., ...) const volatile noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) &>) static {  return std::type_identity<Ret(S::*)(Args...) & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) &>) static {  return std::type_identity<Ret(S::*)(Args..., ...) & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const &>) static {  return std::type_identity<Ret(S::*)(Args...) const & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const &>) static {  return std::type_identity<Ret(S::*)(Args..., ...) const & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) volatile &>) static {  return std::type_identity<Ret(S::*)(Args...) volatile & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) volatile &>) static {  return std::type_identity<Ret(S::*)(Args..., ...) volatile & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const volatile &>) static {  return std::type_identity<Ret(S::*)(Args...) const volatile & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const volatile &>) static {  return std::type_identity<Ret(S::*)(Args..., ...) const volatile & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) &&>) static {  return std::type_identity<Ret(S::*)(Args...) && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) &&>) static {  return std::type_identity<Ret(S::*)(Args..., ...) && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const &&>) static {  return std::type_identity<Ret(S::*)(Args...) const && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const &&>) static {  return std::type_identity<Ret(S::*)(Args..., ...) const && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) volatile &&>) static {  return std::type_identity<Ret(S::*)(Args...) volatile && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) volatile &&>) static {  return std::type_identity<Ret(S::*)(Args..., ...) volatile && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const volatile &&>) static {  return std::type_identity<Ret(S::*)(Args...) const volatile && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const volatile &&>) static {  return std::type_identity<Ret(S::*)(Args..., ...) const volatile && noexcept>(); }
	)(std::type_identity<x4::rmcvref<T>>()))::type>;
}
