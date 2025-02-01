#pragma once

#include "../fn/visitor.hpp"
#include "../meta/t.hpp"
#include "../trait/rm_cvref.hpp"

namespace xieite {
	template<typename T>
	concept is_noex = xieite::visitor(
		[](...) static {  return false; },
		[]<typename Ret, typename... Args>(xieite::t<Ret(Args...) noexcept>) static {  return true; },
		[]<typename Ret, typename... Args>(xieite::t<Ret(Args..., ...) noexcept>) static {  return true; },
		[]<typename Ret, typename... Args>(xieite::t<Ret(*)(Args...) noexcept>) static {  return true; },
		[]<typename Ret, typename... Args>(xieite::t<Ret(*)(Args..., ...) noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) volatile noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) volatile noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const volatile noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const volatile noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) & noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) & noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const & noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const & noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) volatile & noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) volatile & noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const volatile & noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const volatile & noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) && noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) && noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const && noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const && noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) volatile && noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) volatile && noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const volatile && noexcept>) static {  return true; },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const volatile && noexcept>) static {  return true; }
	)(xieite::t<xieite::rm_cvref<T>>());
}
