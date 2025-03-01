#pragma once

#include <type_traits>
#include "../fn/visitor.hpp"
#include "../trait/cpcvref.hpp"
#include "../traitrmcvref.hpp"

namespace x4 {
	template<typename T>
	using addvreft = x4::cpcvref<T, typename decltype(x4::visitor(
		[](...) static {  return std::type_identity<T>(); },
		[]<typename U>(std::type_identity<U*>) static {  return std::type_identity<volatile U*>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) noexcept(noex)>) static {  return std::type_identity<Ret(S::*)(Args...) volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) noexcept(noex)>) static {  return std::type_identity<Ret(S::*)(Args..., ...) volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const noexcept(noex)>) static {  return std::type_identity<Ret(S::*)(Args...) const volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const noexcept(noex)>) static {  return std::type_identity<Ret(S::*)(Args..., ...) const volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) & noexcept(noex)>) static {  return std::type_identity<Ret(S::*)(Args...) volatile & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) & noexcept(noex)>) static {  return std::type_identity<Ret(S::*)(Args..., ...) volatile & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const & noexcept(noex)>) static {  return std::type_identity<Ret(S::*)(Args...) const volatile & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const & noexcept(noex)>) static {  return std::type_identity<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) && noexcept(noex)>) static {  return std::type_identity<Ret(S::*)(Args...) volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) && noexcept(noex)>) static {  return std::type_identity<Ret(S::*)(Args..., ...) volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const && noexcept(noex)>) static {  return std::type_identity<Ret(S::*)(Args...) const volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const && noexcept(noex)>) static {  return std::type_identity<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)>(); }
	)(std::type_identity<x4:rmcvref<T>>()))::type>;
}
