#pragma once

#include "../fn/visitor.hpp"
#include "../meta/t.hpp"
#include "../trait/cp_cvref.hpp"
#include "../trait/rm_cvref.hpp"

namespace xieite {
	template<typename T>
	using add_noex = xieite::cp_cvref<T, typename decltype(xieite::visitor(
		[](...) { return xieite::t<T>(); },
		[]<typename Ret, typename... Args>(xieite::t<Ret(Args...)>) { return xieite::t<Ret(Args...) noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::t<Ret(Args..., ...)>) { return xieite::t<Ret(Args..., ...) noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::t<Ret(*)(Args...)>) { return xieite::t<Ret(*)(Args...) noexcept>(); },
		[]<typename Ret, typename... Args>(xieite::t<Ret(*)(Args..., ...)>) { return xieite::t<Ret(*)(Args..., ...) noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...)>) { return xieite::t<Ret(S::*)(Args...) noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...)>) { return xieite::t<Ret(S::*)(Args..., ...) noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const>) { return xieite::t<Ret(S::*)(Args...) const noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const>) { return xieite::t<Ret(S::*)(Args..., ...) const noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) volatile>) { return xieite::t<Ret(S::*)(Args...) volatile noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) volatile>) { return xieite::t<Ret(S::*)(Args..., ...) volatile noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const volatile>) { return xieite::t<Ret(S::*)(Args...) const volatile noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const volatile>) { return xieite::t<Ret(S::*)(Args..., ...) const volatile noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) &>) { return xieite::t<Ret(S::*)(Args...) & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) &>) { return xieite::t<Ret(S::*)(Args..., ...) & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const &>) { return xieite::t<Ret(S::*)(Args...) const & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const &>) { return xieite::t<Ret(S::*)(Args..., ...) const & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) volatile &>) { return xieite::t<Ret(S::*)(Args...) volatile & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) volatile &>) { return xieite::t<Ret(S::*)(Args..., ...) volatile & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const volatile &>) { return xieite::t<Ret(S::*)(Args...) const volatile & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const volatile &>) { return xieite::t<Ret(S::*)(Args..., ...) const volatile & noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) &&>) { return xieite::t<Ret(S::*)(Args...) && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) &&>) { return xieite::t<Ret(S::*)(Args..., ...) && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const &&>) { return xieite::t<Ret(S::*)(Args...) const && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const &&>) { return xieite::t<Ret(S::*)(Args..., ...) const && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) volatile &&>) { return xieite::t<Ret(S::*)(Args...) volatile && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) volatile &&>) { return xieite::t<Ret(S::*)(Args..., ...) volatile && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args...) const volatile &&>) { return xieite::t<Ret(S::*)(Args...) const volatile && noexcept>(); },
		[]<typename Ret, typename S, typename... Args>(xieite::t<Ret(S::*)(Args..., ...) const volatile &&>) { return xieite::t<Ret(S::*)(Args..., ...) const volatile && noexcept>(); }
	)(xieite::t<xieite::rm_cvref<T>>()))::type>;
}
