#ifndef DETAIL_XTE_HEADER_TRAIT_IS_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_IS_FUNC
#
#	include "../meta/member_type.hpp"

namespace DETAIL_XTE::is_func {
	template<typename>
	constexpr bool impl = false;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types...) noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types...) const noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) const noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types...) volatile noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) volatile noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types...) const volatile noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) const volatile noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types...) & noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) & noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types...) const& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) const& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types...) volatile& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) volatile& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types...) const volatile& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) const volatile& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types...) && noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) && noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types...) const&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) const&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types...) volatile&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) volatile&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types...) const volatile&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool impl<return_type(arg_types..., ...) const volatile&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types...) noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types...) const noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) const noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types...) volatile noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) volatile noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types...) const volatile noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) const volatile noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types...) & noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) & noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types...) const& noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) const& noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types...) volatile& noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) volatile& noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types...) const volatile& noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) const volatile& noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types...) && noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) && noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types...) const&& noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) const&& noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types...) volatile&& noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) volatile&& noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types...) const volatile&& noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) const volatile&& noexcept(noex_spec)>> = true;
}

namespace xte {
	template<typename func_type>
	concept is_func = DETAIL_XTE::is_func::impl<func_type>;
}

#endif
