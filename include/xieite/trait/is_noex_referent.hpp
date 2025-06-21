#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_REFERENT
#
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::is_noex_referent {
	template<typename>
	constexpr bool impl = false;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(*)(Args...) noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(*)(Args..., ...) noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args...) noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args...) const noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args...) volatile noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args...) const volatile noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args...) & noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args...) const & noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args...) volatile & noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args...) const volatile & noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args...) && noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args...) const && noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args...) volatile && noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args...) const volatile && noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args..., ...) noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args..., ...) const noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args..., ...) volatile noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args..., ...) const volatile noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args..., ...) & noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args..., ...) const & noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args..., ...) volatile & noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args..., ...) const volatile & noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args..., ...) && noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args..., ...) const && noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args..., ...) volatile && noexcept> = true;

	template<typename Ret, typename... Args>
	constexpr bool impl<Ret(Args..., ...) const volatile && noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args...) noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args...) const noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args...) volatile noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args...) const volatile noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args...) & noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args...) const & noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args...) volatile & noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args...) const volatile & noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args...) && noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args...) const && noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args...) volatile && noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args...) const volatile && noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args..., ...) noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args..., ...) const noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args..., ...) volatile noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args..., ...) const volatile noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args..., ...) & noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args..., ...) const & noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args..., ...) volatile & noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args..., ...) const volatile & noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args..., ...) && noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args..., ...) const && noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args..., ...) volatile && noexcept> = true;

	template<typename Ret, typename S, typename... Args>
	constexpr bool impl<Ret(S::*)(Args..., ...) const volatile && noexcept> = true;
}

namespace xieite {
	template<typename T>
	concept is_noex_referent = DETAIL_XIEITE::is_noex_referent::impl<xieite::rm_cvref<T>>;
}

#endif
