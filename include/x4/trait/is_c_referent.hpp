#pragma once

#include <type_traits>
#include "../fn/visitor.hpp"
#include "../traitrmcvref.hpp"

namespace x4 {
	template<typename T>
	concept iscreft = x4::visitor(
		[](...) static {  return false; },
		[]<typename U>(std::type_identity<const U*>) static {  return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const noexcept(noex)>) static {  return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const noexcept(noex)>) static {  return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const volatile noexcept(noex)>) static {  return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const volatile noexcept(noex)>) static {  return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const & noexcept(noex)>) static {  return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const & noexcept(noex)>) static {  return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const volatile & noexcept(noex)>) static {  return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)>) static {  return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const && noexcept(noex)>) static {  return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const && noexcept(noex)>) static {  return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const volatile && noexcept(noex)>) static {  return true; },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)>) static {  return true; }
	)(std::type_identity<x4:rmcvref<T>>());
}
