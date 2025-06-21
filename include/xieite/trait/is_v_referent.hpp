#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_V_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_V_REFERENT
#
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::is_v_referent {
	template<typename>
	constexpr bool impl = false;

	template<typename T>
	constexpr bool impl<volatile T*> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args...) volatile noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args...) const volatile noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args...) volatile & noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args...) const volatile & noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args...) volatile && noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args...) const volatile && noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args..., ...) volatile noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args..., ...) const volatile noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args..., ...) volatile & noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args..., ...) const volatile & noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args..., ...) volatile && noexcept(noex)> = true;

	template<typename Ret, typename... Args, bool noex>
	constexpr bool impl<Ret(Args..., ...) const volatile && noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args...) volatile noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args...) const volatile noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args...) volatile & noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args...) const volatile & noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args...) volatile && noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args...) const volatile && noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args..., ...) volatile noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args..., ...) const volatile noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args..., ...) volatile & noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args..., ...) volatile && noexcept(noex)> = true;

	template<typename Ret, typename S, typename... Args, bool noex>
	constexpr bool impl<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)> = true;
}

namespace xieite {
	template<typename T>
	concept is_v_referent = DETAIL_XIEITE::is_v_referent::impl<xieite::rm_cvref<T>>;
}

#endif
