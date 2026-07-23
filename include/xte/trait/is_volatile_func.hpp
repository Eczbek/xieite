#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CONST_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_IS_CONST_FUNC
#
#	include "../trait/is_func.hpp"

namespace DETAIL_XTE::is_volatile_func {
	template<typename>
	constexpr bool impl = false;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types...) volatile noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) volatile noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types...) const volatile noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) const volatile noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types...) volatile& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) volatile& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types...) const volatile& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) const volatile& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types...) volatile&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) volatile&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types...) const volatile&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) const volatile&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types...) volatile noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) volatile noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types...) const volatile noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const volatile noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types...) volatile& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) volatile& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types...) const volatile& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const volatile& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types...) volatile&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) volatile&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types...) const volatile&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const volatile&& noexcept(noex_spec)> = true;
}

namespace xte {
	template<typename func_type>
	concept is_volatile_func = xte::is_func<func_type> && DETAIL_XTE::is_volatile_func::impl<func_type>;
}

#endif

// TODO: `xte::type<return_type(arg_types...) &> class_type::*`
