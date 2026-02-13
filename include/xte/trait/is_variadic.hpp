#ifndef DETAIL_XTE_HEADER_TRAIT_IS_VARIADIC
#	define DETAIL_XTE_HEADER_TRAIT_IS_VARIADIC
#
#	include "../trait/remove_cvref.hpp"

namespace DETAIL_XTE {
	template<typename>
	constexpr bool is_variadic = false;

	template<typename Return, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Args..., ...) noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Args..., ...) const noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Args..., ...) volatile noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Args..., ...) const volatile noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Args..., ...) & noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Args..., ...) const & noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Args..., ...) volatile & noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Args..., ...) const volatile & noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Args..., ...) && noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Args..., ...) const && noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Args..., ...) volatile && noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Args..., ...) const volatile && noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Class::*)(Args..., ...) noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Class::*)(Args..., ...) const noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Class::*)(Args..., ...) volatile noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Class::*)(Args..., ...) const volatile noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Class::*)(Args..., ...) & noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Class::*)(Args..., ...) const & noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Class::*)(Args..., ...) volatile & noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Class::*)(Args..., ...) const volatile & noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Class::*)(Args..., ...) && noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Class::*)(Args..., ...) const && noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Class::*)(Args..., ...) volatile && noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool is_variadic<Return(Class::*)(Args..., ...) const volatile && noexcept(noex)> = true;
}

namespace xte {
	template<typename T>
	concept is_variadic = DETAIL_XTE::is_variadic<xte::remove_cvref<T>>;
}

#endif
