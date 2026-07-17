#ifndef DETAIL_XTE_HEADER_TRAIT_IS_VARIADIC
#	define DETAIL_XTE_HEADER_TRAIT_IS_VARIADIC
#
#	include "../trait/drop_cvref.hpp"

namespace DETAIL_XTE::is_variadic {
	template<typename>
	constexpr bool impl = false;

	template<typename Return, typename... Args, bool noex>
	constexpr bool impl<Return(Args..., ...) noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool impl<Return(Args..., ...) const noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool impl<Return(Args..., ...) volatile noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool impl<Return(Args..., ...) const volatile noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool impl<Return(Args..., ...) & noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool impl<Return(Args..., ...) const & noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool impl<Return(Args..., ...) volatile & noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool impl<Return(Args..., ...) const volatile & noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool impl<Return(Args..., ...) && noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool impl<Return(Args..., ...) const && noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool impl<Return(Args..., ...) volatile && noexcept(noex)> = true;

	template<typename Return, typename... Args, bool noex>
	constexpr bool impl<Return(Args..., ...) const volatile && noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool impl<Return(Class::*)(Args..., ...) noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool impl<Return(Class::*)(Args..., ...) const noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool impl<Return(Class::*)(Args..., ...) volatile noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool impl<Return(Class::*)(Args..., ...) const volatile noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool impl<Return(Class::*)(Args..., ...) & noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool impl<Return(Class::*)(Args..., ...) const & noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool impl<Return(Class::*)(Args..., ...) volatile & noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool impl<Return(Class::*)(Args..., ...) const volatile & noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool impl<Return(Class::*)(Args..., ...) && noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool impl<Return(Class::*)(Args..., ...) const && noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool impl<Return(Class::*)(Args..., ...) volatile && noexcept(noex)> = true;

	template<typename Return, typename Class, typename... Args, bool noex>
	constexpr bool impl<Return(Class::*)(Args..., ...) const volatile && noexcept(noex)> = true;
}

namespace xte {
	template<typename T>
	concept is_variadic = DETAIL_XTE::is_variadic::impl<xte::drop_cvref<T>>;
}

#endif

// TODO: `xte::type<Return(Args..., ...) &> Class::*`
