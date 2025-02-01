#pragma once

#include "../fn/visitor.hpp"
#include "../meta/t.hpp"
#include "../trait/cp_cvref.hpp"
#include "../trait/rm_cvref.hpp"

namespace xieite {
	template<typename T>
	using add_v_referent = xieite::cp_cvref<T, typename decltype(xieite::visitor(
		[](...) static {  return xieite::t<T>(); },
		[]<typename U>(xieite::t<U*>) static {  return xieite::t<volatile U*>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args...) noexcept(noex)>) static {  return xieite::t<Ret(S::*)(Args...) volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args..., ...) noexcept(noex)>) static {  return xieite::t<Ret(S::*)(Args..., ...) volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args...) const noexcept(noex)>) static {  return xieite::t<Ret(S::*)(Args...) const volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args..., ...) const noexcept(noex)>) static {  return xieite::t<Ret(S::*)(Args..., ...) const volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args...) & noexcept(noex)>) static {  return xieite::t<Ret(S::*)(Args...) volatile & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args..., ...) & noexcept(noex)>) static {  return xieite::t<Ret(S::*)(Args..., ...) volatile & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args...) const & noexcept(noex)>) static {  return xieite::t<Ret(S::*)(Args...) const volatile & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args..., ...) const & noexcept(noex)>) static {  return xieite::t<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args...) && noexcept(noex)>) static {  return xieite::t<Ret(S::*)(Args...) volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args..., ...) && noexcept(noex)>) static {  return xieite::t<Ret(S::*)(Args..., ...) volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args...) const && noexcept(noex)>) static {  return xieite::t<Ret(S::*)(Args...) const volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(xieite::t<Ret(S::*)(Args..., ...) const && noexcept(noex)>) static {  return xieite::t<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)>(); }
	)(xieite::t<xieite::rm_cvref<T>>()))::type>;
}
