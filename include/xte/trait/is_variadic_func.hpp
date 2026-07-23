#ifndef DETAIL_XTE_HEADER_TRAIT_IS_VARIADIC_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_IS_VARIADIC_FUNC
#
#	include "../trait/drop_cvref.hpp"
#	include "../trait/drop_ptr.hpp"
#	include "../trait/is_func.hpp"

namespace DETAIL_XTE::is_variadic_func {
	template<typename>
	constexpr bool impl = false;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) const noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) volatile noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) const volatile noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) & noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) const& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) volatile& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) const volatile& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) && noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) const&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) volatile&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) const volatile&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) & noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) const& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) volatile& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) const volatile& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) && noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) const&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) volatile&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) const volatile&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) volatile noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const volatile noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) & noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) volatile& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const volatile& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) && noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) volatile&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const volatile&& noexcept(noex_spec)> = true;
}

namespace xte {
	template<typename func_type>
	concept is_variadic_func = xte::is_func<func_type> && DETAIL_XTE::is_variadic_func::impl<xte::drop_cvref<xte::drop_ptr<func_type>>>;
}

#endif

// TODO: `xte::type<return_type(arg_types...) &> class_type::*`
