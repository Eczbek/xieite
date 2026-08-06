#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_VARARGS
#	define DETAIL_XTE_HEADER_TRAIT_DROP_VARARGS
#
#	include "../meta/member_type.hpp"
#	include "../trait/is_func.hpp"

namespace DETAIL_XTE::is_varargs {
	template<typename func_type>
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

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) const noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) volatile noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) const volatile noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) & noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) const& noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) volatile& noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) const volatile& noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) && noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) const&& noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) volatile&& noexcept(noex_spec)>> = true;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr bool impl<xte::member_type<class_type, return_type(arg_types..., ...) const volatile&& noexcept(noex_spec)>> = true;
}

namespace xte {
	template<typename func_type>
	concept is_varargs = xte::is_func<func_type> && DETAIL_XTE::is_varargs::impl<func_type>;
}

#endif
