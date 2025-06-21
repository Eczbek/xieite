#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VARIADIC_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VARIADIC_REFERENT
#
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::is_variadic_referent {
	template<typename>
	constexpr bool impl = false;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(*)(Args..., ...) noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args..., ...) noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args..., ...) const noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args..., ...) volatile noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args..., ...) const volatile noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args..., ...) & noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args..., ...) const & noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args..., ...) volatile & noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args..., ...) const volatile & noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args..., ...) && noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args..., ...) const && noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args..., ...) volatile && noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args..., ...) const volatile && noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args..., ...) noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args..., ...) const noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args..., ...) volatile noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args..., ...) const volatile noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args..., ...) & noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args..., ...) const & noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args..., ...) volatile & noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args..., ...) && noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args..., ...) const && noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args..., ...) volatile && noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)> = true;
}

namespace xieite {
	template<typename T>
	concept is_variadic_referent = DETAIL_XIEITE::is_variadic_referent::impl<xieite::rm_cvref<T>>;
}

#endif
