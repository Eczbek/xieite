#ifndef DETAIL_XTE_HEADER_TRAIT_IS_VARIADIC
#	define DETAIL_XTE_HEADER_TRAIT_IS_VARIADIC
#
#	include "../trait/drop_cvref.hpp"

namespace DETAIL_XTE::is_variadic {
	template<typename>
	constexpr bool impl = false;

	template<typename return_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(arg_types..., ...) noexcept(noex)> = true;

	template<typename return_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(arg_types..., ...) const noexcept(noex)> = true;

	template<typename return_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(arg_types..., ...) volatile noexcept(noex)> = true;

	template<typename return_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(arg_types..., ...) const volatile noexcept(noex)> = true;

	template<typename return_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(arg_types..., ...) & noexcept(noex)> = true;

	template<typename return_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(arg_types..., ...) const & noexcept(noex)> = true;

	template<typename return_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(arg_types..., ...) volatile & noexcept(noex)> = true;

	template<typename return_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(arg_types..., ...) const volatile & noexcept(noex)> = true;

	template<typename return_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(arg_types..., ...) && noexcept(noex)> = true;

	template<typename return_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(arg_types..., ...) const && noexcept(noex)> = true;

	template<typename return_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(arg_types..., ...) volatile && noexcept(noex)> = true;

	template<typename return_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(arg_types..., ...) const volatile && noexcept(noex)> = true;

	template<typename return_type, typename class_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) noexcept(noex)> = true;

	template<typename return_type, typename class_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const noexcept(noex)> = true;

	template<typename return_type, typename class_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) volatile noexcept(noex)> = true;

	template<typename return_type, typename class_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const volatile noexcept(noex)> = true;

	template<typename return_type, typename class_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) & noexcept(noex)> = true;

	template<typename return_type, typename class_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const & noexcept(noex)> = true;

	template<typename return_type, typename class_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) volatile & noexcept(noex)> = true;

	template<typename return_type, typename class_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const volatile & noexcept(noex)> = true;

	template<typename return_type, typename class_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) && noexcept(noex)> = true;

	template<typename return_type, typename class_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const && noexcept(noex)> = true;

	template<typename return_type, typename class_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) volatile && noexcept(noex)> = true;

	template<typename return_type, typename class_type, typename... arg_types, bool noex>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const volatile && noexcept(noex)> = true;
}

namespace xte {
	template<typename T>
	concept is_variadic = DETAIL_XTE::is_variadic::impl<xte::drop_cvref<T>>;
}

#endif

// TODO: `xte::type<return_type(arg_types..., ...) &> class_type::*`
