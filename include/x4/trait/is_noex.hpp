#pragma once

#include <type_traits>
#include "../fn/visitor.hpp"
#include "../trait/rmcvref.hpp"

namespace x4 {
	template<typename T>
	concept isnoex = x4::visitor(
		[](...) static {  return false; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args...) noexcept>) static {  return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(Args..., ...) noexcept>) static {  return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(*)(Args...) noexcept>) static {  return true; },
		[]<typename Ret, typename... Args>(std::type_identity<Ret(*)(Args..., ...) noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) volatile noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) volatile noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const volatile noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const volatile noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) & noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) & noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const & noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const & noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) volatile & noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) volatile & noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const volatile & noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const volatile & noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) && noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) && noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const && noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const && noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) volatile && noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) volatile && noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args...) const volatile && noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(std::type_identity<Ret(S::*)(Args..., ...) const volatile && noexcept>) static {  return true; }
	)(std::type_identity<x4::rmcvref<T>>());
}
