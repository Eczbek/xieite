#ifndef DETAIL_XTE_HEADER_FUNC_TRAITS
#	define DETAIL_XTE_HEADER_FUNC_TRAITS
#
#	include <meta>

namespace DETAIL_XTE::func_traits {
	template<typename>
	constexpr bool is_variadic_func = false;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool is_variadic_func<return_type(arg_types..., ...) noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool is_variadic_func<return_type(arg_types..., ...) const noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool is_variadic_func<return_type(arg_types..., ...) volatile noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool is_variadic_func<return_type(arg_types..., ...) const volatile noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool is_variadic_func<return_type(arg_types..., ...) & noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool is_variadic_func<return_type(arg_types..., ...) const& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool is_variadic_func<return_type(arg_types..., ...) volatile& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool is_variadic_func<return_type(arg_types..., ...) const volatile& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool is_variadic_func<return_type(arg_types..., ...) && noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool is_variadic_func<return_type(arg_types..., ...) const&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool is_variadic_func<return_type(arg_types..., ...) volatile&& noexcept(noex_spec)> = true;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr bool is_variadic_func<return_type(arg_types..., ...) const volatile&& noexcept(noex_spec)> = true;

	template<typename type>
	constexpr auto add_const = ^^type;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_const<return_type(arg_types...) noexcept(noex_spec)> = ^^return_type(arg_types...) const noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_const<return_type(arg_types..., ...) noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_const<return_type(arg_types...) volatile noexcept(noex_spec)> = ^^return_type(arg_types...) const volatile noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_const<return_type(arg_types..., ...) volatile noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const volatile noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_const<return_type(arg_types...) & noexcept(noex_spec)> = ^^return_type(arg_types...) const& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_const<return_type(arg_types..., ...) & noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_const<return_type(arg_types...) volatile& noexcept(noex_spec)> = ^^return_type(arg_types...) const volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_const<return_type(arg_types..., ...) volatile& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_const<return_type(arg_types...) && noexcept(noex_spec)> = ^^return_type(arg_types...) const&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_const<return_type(arg_types..., ...) && noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_const<return_type(arg_types...) volatile&& noexcept(noex_spec)> = ^^return_type(arg_types...) const volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_const<return_type(arg_types..., ...) volatile&& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const volatile&& noexcept(noex_spec);

	template<typename type>
	constexpr auto add_volatile = ^^type;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_volatile<return_type(arg_types...) noexcept(noex_spec)> = ^^return_type(arg_types...) volatile noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_volatile<return_type(arg_types..., ...) noexcept(noex_spec)> = ^^return_type(arg_types..., ...) volatile noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_volatile<return_type(arg_types...) const noexcept(noex_spec)> = ^^return_type(arg_types...) const volatile noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_volatile<return_type(arg_types..., ...) const noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const volatile noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_volatile<return_type(arg_types...) & noexcept(noex_spec)> = ^^return_type(arg_types...) volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_volatile<return_type(arg_types..., ...) & noexcept(noex_spec)> = ^^return_type(arg_types..., ...) volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_volatile<return_type(arg_types...) const& noexcept(noex_spec)> = ^^return_type(arg_types...) const volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_volatile<return_type(arg_types..., ...) const& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_volatile<return_type(arg_types...) && noexcept(noex_spec)> = ^^return_type(arg_types...) volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_volatile<return_type(arg_types..., ...) && noexcept(noex_spec)> = ^^return_type(arg_types..., ...) volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_volatile<return_type(arg_types...) const&& noexcept(noex_spec)> = ^^return_type(arg_types...) const volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_volatile<return_type(arg_types..., ...) const&& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const volatile&& noexcept(noex_spec);

	template<typename type>
	constexpr auto add_lvalue_ref = ^^type;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_lvalue_ref<return_type(arg_types...) noexcept(noex_spec)> = ^^return_type(arg_types...) & noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_lvalue_ref<return_type(arg_types..., ...) noexcept(noex_spec)> = ^^return_type(arg_types..., ...) & noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_lvalue_ref<return_type(arg_types...) const noexcept(noex_spec)> = ^^return_type(arg_types...) const& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_lvalue_ref<return_type(arg_types..., ...) const noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_lvalue_ref<return_type(arg_types...) volatile noexcept(noex_spec)> = ^^return_type(arg_types...) volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_lvalue_ref<return_type(arg_types..., ...) volatile noexcept(noex_spec)> = ^^return_type(arg_types..., ...) volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_lvalue_ref<return_type(arg_types...) const volatile noexcept(noex_spec)> = ^^return_type(arg_types...) const volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_lvalue_ref<return_type(arg_types..., ...) const volatile noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_lvalue_ref<return_type(arg_types...) && noexcept(noex_spec)> = ^^return_type(arg_types...) & noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_lvalue_ref<return_type(arg_types..., ...) && noexcept(noex_spec)> = ^^return_type(arg_types..., ...) & noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_lvalue_ref<return_type(arg_types...) const&& noexcept(noex_spec)> = ^^return_type(arg_types...) const& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_lvalue_ref<return_type(arg_types..., ...) const&& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_lvalue_ref<return_type(arg_types...) volatile&& noexcept(noex_spec)> = ^^return_type(arg_types...) volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_lvalue_ref<return_type(arg_types..., ...) volatile&& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_lvalue_ref<return_type(arg_types...) const volatile&& noexcept(noex_spec)> = ^^return_type(arg_types...) const volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_lvalue_ref<return_type(arg_types..., ...) const volatile&& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const volatile& noexcept(noex_spec);

	template<typename type>
	constexpr auto add_rvalue_ref = ^^type;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_rvalue_ref<return_type(arg_types...) noexcept(noex_spec)> = ^^return_type(arg_types...) && noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_rvalue_ref<return_type(arg_types..., ...) noexcept(noex_spec)> = ^^return_type(arg_types..., ...) && noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_rvalue_ref<return_type(arg_types...) const noexcept(noex_spec)> = ^^return_type(arg_types...) const&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_rvalue_ref<return_type(arg_types..., ...) const noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_rvalue_ref<return_type(arg_types...) volatile noexcept(noex_spec)> = ^^return_type(arg_types...) volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_rvalue_ref<return_type(arg_types..., ...) volatile noexcept(noex_spec)> = ^^return_type(arg_types..., ...) volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_rvalue_ref<return_type(arg_types...) const volatile noexcept(noex_spec)> = ^^return_type(arg_types...) const volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_rvalue_ref<return_type(arg_types..., ...) const volatile noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_rvalue_ref<return_type(arg_types...) & noexcept(noex_spec)> = ^^return_type(arg_types...) && noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_rvalue_ref<return_type(arg_types..., ...) & noexcept(noex_spec)> = ^^return_type(arg_types..., ...) && noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_rvalue_ref<return_type(arg_types...) const& noexcept(noex_spec)> = ^^return_type(arg_types...) const&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_rvalue_ref<return_type(arg_types..., ...) const& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_rvalue_ref<return_type(arg_types...) volatile& noexcept(noex_spec)> = ^^return_type(arg_types...) volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_rvalue_ref<return_type(arg_types..., ...) volatile& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_rvalue_ref<return_type(arg_types...) const volatile& noexcept(noex_spec)> = ^^return_type(arg_types...) const volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_rvalue_ref<return_type(arg_types..., ...) const volatile& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const volatile&& noexcept(noex_spec);

	template<typename type>
	constexpr auto add_noex = ^^type;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types...)> = ^^return_type(arg_types...) noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types..., ...)> = ^^return_type(arg_types..., ...) noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types...) const> = ^^return_type(arg_types...) const noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types..., ...) const> = ^^return_type(arg_types..., ...) const noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types...) volatile> = ^^return_type(arg_types...) volatile noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types..., ...) volatile> = ^^return_type(arg_types..., ...) volatile noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types...) const volatile> = ^^return_type(arg_types...) const volatile noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types..., ...) const volatile> = ^^return_type(arg_types..., ...) const volatile noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types...) &> = ^^return_type(arg_types...) & noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types..., ...) &> = ^^return_type(arg_types..., ...) & noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types...) const&> = ^^return_type(arg_types...) const& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types..., ...) const&> = ^^return_type(arg_types..., ...) const& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types...) volatile&> = ^^return_type(arg_types...) volatile& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types..., ...) volatile&> = ^^return_type(arg_types..., ...) volatile& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types...) const volatile&> = ^^return_type(arg_types...) const volatile& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types..., ...) const volatile&> = ^^return_type(arg_types..., ...) const volatile& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types...) &&> = ^^return_type(arg_types...) && noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types..., ...) &&> = ^^return_type(arg_types..., ...) && noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types...) const&&> = ^^return_type(arg_types...) const&& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types..., ...) const&&> = ^^return_type(arg_types..., ...) const&& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types...) volatile&&> = ^^return_type(arg_types...) volatile&& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types..., ...) volatile&&> = ^^return_type(arg_types..., ...) volatile&& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types...) const volatile&&> = ^^return_type(arg_types...) const volatile&& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto add_noex<return_type(arg_types..., ...) const volatile&&> = ^^return_type(arg_types..., ...) const volatile&& noexcept;

	template<typename type>
	constexpr auto add_variadic_func = ^^type;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_variadic_func<return_type(arg_types...) noexcept(noex_spec)> = ^^return_type(arg_types..., ...) noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_variadic_func<return_type(arg_types...) const noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_variadic_func<return_type(arg_types...) volatile noexcept(noex_spec)> = ^^return_type(arg_types..., ...) volatile noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_variadic_func<return_type(arg_types...) const volatile noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const volatile noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_variadic_func<return_type(arg_types...) & noexcept(noex_spec)> = ^^return_type(arg_types..., ...) & noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_variadic_func<return_type(arg_types...) const& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_variadic_func<return_type(arg_types...) volatile& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_variadic_func<return_type(arg_types...) const volatile& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_variadic_func<return_type(arg_types...) && noexcept(noex_spec)> = ^^return_type(arg_types..., ...) && noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_variadic_func<return_type(arg_types...) const&& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_variadic_func<return_type(arg_types...) volatile&& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto add_variadic_func<return_type(arg_types...) const volatile&& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const volatile&& noexcept(noex_spec);

	template<typename type>
	constexpr auto drop_const = ^^type;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_const<return_type(arg_types...) const noexcept(noex_spec)> = ^^return_type(arg_types...) noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_const<return_type(arg_types..., ...) const noexcept(noex_spec)> = ^^return_type(arg_types..., ...) noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_const<return_type(arg_types...) const volatile noexcept(noex_spec)> = ^^return_type(arg_types...) volatile noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_const<return_type(arg_types..., ...) const volatile noexcept(noex_spec)> = ^^return_type(arg_types..., ...) volatile noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_const<return_type(arg_types...) const& noexcept(noex_spec)> = ^^return_type(arg_types...) & noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_const<return_type(arg_types..., ...) const& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) & noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_const<return_type(arg_types...) const volatile& noexcept(noex_spec)> = ^^return_type(arg_types...) volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_const<return_type(arg_types..., ...) const volatile& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_const<return_type(arg_types...) const&& noexcept(noex_spec)> = ^^return_type(arg_types...) && noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_const<return_type(arg_types..., ...) const&& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) && noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_const<return_type(arg_types...) const volatile&& noexcept(noex_spec)> = ^^return_type(arg_types...) volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_const<return_type(arg_types..., ...) const volatile&& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) volatile&& noexcept(noex_spec);

	template<typename type>
	constexpr auto drop_volatile = ^^type;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_volatile<return_type(arg_types...) volatile noexcept(noex_spec)> = ^^return_type(arg_types...) noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_volatile<return_type(arg_types..., ...) volatile noexcept(noex_spec)> = ^^return_type(arg_types..., ...) noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_volatile<return_type(arg_types...) const volatile noexcept(noex_spec)> = ^^return_type(arg_types...) const noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_volatile<return_type(arg_types..., ...) const volatile noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_volatile<return_type(arg_types...) volatile& noexcept(noex_spec)> = ^^return_type(arg_types...) & noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_volatile<return_type(arg_types..., ...) volatile& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) & noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_volatile<return_type(arg_types...) const volatile& noexcept(noex_spec)> = ^^return_type(arg_types...) const& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_volatile<return_type(arg_types..., ...) const volatile& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_volatile<return_type(arg_types...) volatile&& noexcept(noex_spec)> = ^^return_type(arg_types...) && noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_volatile<return_type(arg_types..., ...) volatile&& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) && noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_volatile<return_type(arg_types...) const volatile&& noexcept(noex_spec)> = ^^return_type(arg_types...) const&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_volatile<return_type(arg_types..., ...) const volatile&& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const&& noexcept(noex_spec);

	template<typename type>
	constexpr auto drop_lvalue_ref = ^^type;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_lvalue_ref<return_type(arg_types...) & noexcept(noex_spec)> = ^^return_type(arg_types...) noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_lvalue_ref<return_type(arg_types..., ...) & noexcept(noex_spec)> = ^^return_type(arg_types..., ...) noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_lvalue_ref<return_type(arg_types...) const& noexcept(noex_spec)> = ^^return_type(arg_types...) const noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_lvalue_ref<return_type(arg_types..., ...) const& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_lvalue_ref<return_type(arg_types...) volatile& noexcept(noex_spec)> = ^^return_type(arg_types...) volatile noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_lvalue_ref<return_type(arg_types..., ...) volatile& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) volatile noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_lvalue_ref<return_type(arg_types...) const volatile& noexcept(noex_spec)> = ^^return_type(arg_types...) const volatile noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_lvalue_ref<return_type(arg_types..., ...) const volatile& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const volatile noexcept(noex_spec);

	template<typename type>
	constexpr auto drop_rvalue_ref = ^^type;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_rvalue_ref<return_type(arg_types...) && noexcept(noex_spec)> = ^^return_type(arg_types...) noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_rvalue_ref<return_type(arg_types..., ...) && noexcept(noex_spec)> = ^^return_type(arg_types..., ...) noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_rvalue_ref<return_type(arg_types...) const&& noexcept(noex_spec)> = ^^return_type(arg_types...) const noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_rvalue_ref<return_type(arg_types..., ...) const&& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_rvalue_ref<return_type(arg_types...) volatile&& noexcept(noex_spec)> = ^^return_type(arg_types...) volatile noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_rvalue_ref<return_type(arg_types..., ...) volatile&& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) volatile noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_rvalue_ref<return_type(arg_types...) const volatile&& noexcept(noex_spec)> = ^^return_type(arg_types...) const volatile noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_rvalue_ref<return_type(arg_types..., ...) const volatile&& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const volatile noexcept(noex_spec);

	template<typename type>
	constexpr auto drop_noex = ^^type;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types...) noexcept> = ^^return_type(arg_types...);

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types..., ...) noexcept> = ^^return_type(arg_types..., ...);

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types...) const noexcept> = ^^return_type(arg_types...) const;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types..., ...) const noexcept> = ^^return_type(arg_types..., ...) const;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types...) volatile noexcept> = ^^return_type(arg_types...) volatile;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types..., ...) volatile noexcept> = ^^return_type(arg_types..., ...) volatile;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types...) const volatile noexcept> = ^^return_type(arg_types...) const volatile;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types..., ...) const volatile noexcept> = ^^return_type(arg_types..., ...) const volatile;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types...) & noexcept> = ^^return_type(arg_types...) &;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types..., ...) & noexcept> = ^^return_type(arg_types..., ...) &;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types...) const& noexcept> = ^^return_type(arg_types...) const&;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types..., ...) const& noexcept> = ^^return_type(arg_types..., ...) const&;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types...) volatile& noexcept> = ^^return_type(arg_types...) volatile&;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types..., ...) volatile& noexcept> = ^^return_type(arg_types..., ...) volatile&;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types...) const volatile& noexcept> = ^^return_type(arg_types...) const volatile&;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types..., ...) const volatile& noexcept> = ^^return_type(arg_types..., ...) const volatile&;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types...) && noexcept> = ^^return_type(arg_types...) &&;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types..., ...) && noexcept> = ^^return_type(arg_types..., ...) &&;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types...) const&& noexcept> = ^^return_type(arg_types...) const&&;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types..., ...) const&& noexcept> = ^^return_type(arg_types..., ...) const&&;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types...) volatile&& noexcept> = ^^return_type(arg_types...) volatile&&;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types..., ...) volatile&& noexcept> = ^^return_type(arg_types..., ...) volatile&&;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types...) const volatile&& noexcept> = ^^return_type(arg_types...) const volatile&&;

	template<typename return_type, typename... arg_types>
	constexpr auto drop_noex<return_type(arg_types..., ...) const volatile&& noexcept> = ^^return_type(arg_types..., ...) const volatile&&;

	template<typename type>
	constexpr auto drop_variadic = ^^type;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_variadic<return_type(arg_types..., ...) noexcept(noex_spec)> = ^^return_type(arg_types...) noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_variadic<return_type(arg_types..., ...) const noexcept(noex_spec)> = ^^return_type(arg_types...) const noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_variadic<return_type(arg_types..., ...) volatile noexcept(noex_spec)> = ^^return_type(arg_types...) volatile noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_variadic<return_type(arg_types..., ...) const volatile noexcept(noex_spec)> = ^^return_type(arg_types...) const volatile noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_variadic<return_type(arg_types..., ...) & noexcept(noex_spec)> = ^^return_type(arg_types...) & noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_variadic<return_type(arg_types..., ...) const& noexcept(noex_spec)> = ^^return_type(arg_types...) const& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_variadic<return_type(arg_types..., ...) volatile& noexcept(noex_spec)> = ^^return_type(arg_types...) volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_variadic<return_type(arg_types..., ...) const volatile& noexcept(noex_spec)> = ^^return_type(arg_types...) const volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_variadic<return_type(arg_types..., ...) && noexcept(noex_spec)> = ^^return_type(arg_types...) && noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_variadic<return_type(arg_types..., ...) const&& noexcept(noex_spec)> = ^^return_type(arg_types...) const&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_variadic<return_type(arg_types..., ...) volatile&& noexcept(noex_spec)> = ^^return_type(arg_types...) volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto drop_variadic<return_type(arg_types..., ...) const volatile&& noexcept(noex_spec)> = ^^return_type(arg_types...) const volatile&& noexcept(noex_spec);
}

namespace xte {
	template<typename type>
	concept is_func = std::meta::is_function_type(^^type);

	template<typename type>
	concept is_const_func = xte::is_func<type> && std::meta::is_const(^^type);

	template<typename type>
	concept is_volatile_func = xte::is_func<type> && std::meta::is_volatile(^^type);

	template<typename type>
	concept is_cv_func = xte::is_const_func<type> && xte::is_volatile_func<type>;

	template<typename type>
	concept is_lvalue_ref_func = xte::is_func<type> && std::meta::is_lvalue_reference_qualified(^^type);

	template<typename type>
	concept is_rvalue_ref_func = xte::is_func<type> && std::meta::is_rvalue_reference_qualified(^^type);

	template<typename type>
	concept is_ref_func = xte::is_lvalue_ref_func<type> || xte::is_rvalue_ref_func<type>;

	template<typename type>
	concept is_const_lvalue_ref_func = xte::is_const_func<type> && xte::is_lvalue_ref_func<type>;

	template<typename type>
	concept is_volatile_lvalue_ref_func = xte::is_volatile_func<type> && xte::is_lvalue_ref_func<type>;

	template<typename type>
	concept is_cv_lvalue_ref_func = xte::is_cv_func<type> && xte::is_lvalue_ref_func<type>;

	template<typename type>
	concept is_const_rvalue_ref_func = xte::is_const_func<type> && xte::is_rvalue_ref_func<type>;

	template<typename type>
	concept is_volatile_rvalue_ref_func = xte::is_volatile_func<type> && xte::is_rvalue_ref_func<type>;

	template<typename type>
	concept is_cv_rvalue_ref_func = xte::is_cv_func<type> && xte::is_rvalue_ref_func<type>;

	template<typename type>
	concept is_const_ref_func = xte::is_const_func<type> && xte::is_ref_func<type>;

	template<typename type>
	concept is_volatile_ref_func = xte::is_volatile_func<type> && xte::is_ref_func<type>;

	template<typename type>
	concept is_cvref_func = xte::is_cv_func<type> && xte::is_ref_func<type>;

	template<typename type>
	concept is_noex_func = xte::is_func<type> && std::meta::is_noexcept(^^type);

	template<typename type>
	concept is_const_noex_func = xte::is_const_func<type> && xte::is_noex_func<type>;

	template<typename type>
	concept is_volatile_noex_func = xte::is_volatile_func<type> && xte::is_noex_func<type>;

	template<typename type>
	concept is_cv_noex_func = xte::is_cv_func<type> && xte::is_noex_func<type>;

	template<typename type>
	concept is_lvalue_ref_noex_func = xte::is_lvalue_ref_func<type> && xte::is_noex_func<type>;

	template<typename type>
	concept is_rvalue_ref_noex_func = xte::is_rvalue_ref_func<type> && xte::is_noex_func<type>;

	template<typename type>
	concept is_ref_noex_func = xte::is_lvalue_ref_noex_func<type> || xte::is_rvalue_ref_noex_func<type>;

	template<typename type>
	concept is_const_lvalue_ref_noex_func = xte::is_const_noex_func<type> && xte::is_lvalue_ref_func<type>;

	template<typename type>
	concept is_volatile_lvalue_ref_noex_func = xte::is_volatile_noex_func<type> && xte::is_lvalue_ref_func<type>;

	template<typename type>
	concept is_cv_lvalue_ref_noex_func = xte::is_cv_noex_func<type> && xte::is_lvalue_ref_func<type>;

	template<typename type>
	concept is_const_rvalue_ref_noex_func = xte::is_const_noex_func<type> && xte::is_rvalue_ref_func<type>;

	template<typename type>
	concept is_volatile_rvalue_ref_noex_func = xte::is_volatile_noex_func<type> && xte::is_rvalue_ref_func<type>;

	template<typename type>
	concept is_cv_rvalue_ref_noex_func = xte::is_cv_noex_func<type> && xte::is_rvalue_ref_func<type>;

	template<typename type>
	concept is_const_ref_noex_func = xte::is_const_noex_func<type> && xte::is_ref_func<type>;

	template<typename type>
	concept is_volatile_ref_noex_func = xte::is_volatile_noex_func<type> && xte::is_ref_func<type>;

	template<typename type>
	concept is_cvref_noex_func = xte::is_cv_noex_func<type> && xte::is_ref_func<type>;

	template<typename type>
	concept is_variadic_func = xte::is_func<type> && DETAIL_XTE::func_traits::is_variadic_func<type>;

	template<typename type>
	concept is_variadic_const_func = xte::is_variadic_func<type> && xte::is_const_func<type>;

	template<typename type>
	concept is_variadic_volatile_func = xte::is_variadic_func<type> && xte::is_volatile_func<type>;

	template<typename type>
	concept is_variadic_cv_func = xte::is_variadic_const_func<type> && xte::is_volatile_func<type>;

	template<typename type>
	concept is_variadic_lvalue_ref_func = xte::is_variadic_func<type> && xte::is_lvalue_ref_func<type>;

	template<typename type>
	concept is_variadic_rvalue_ref_func = xte::is_variadic_func<type> && xte::is_rvalue_ref_func<type>;

	template<typename type>
	concept is_variadic_ref_func = xte::is_variadic_lvalue_ref_func<type> || xte::is_variadic_rvalue_ref_func<type>;

	template<typename type>
	concept is_variadic_const_lvalue_ref_func = xte::is_variadic_const_func<type> && xte::is_lvalue_ref_func<type>;

	template<typename type>
	concept is_variadic_volatile_lvalue_ref_func = xte::is_variadic_volatile_func<type> && xte::is_lvalue_ref_func<type>;

	template<typename type>
	concept is_variadic_cv_lvalue_ref_func = xte::is_variadic_cv_func<type> && xte::is_lvalue_ref_func<type>;

	template<typename type>
	concept is_variadic_const_rvalue_ref_func = xte::is_variadic_const_func<type> && xte::is_rvalue_ref_func<type>;

	template<typename type>
	concept is_variadic_volatile_rvalue_ref_func = xte::is_variadic_volatile_func<type> && xte::is_rvalue_ref_func<type>;

	template<typename type>
	concept is_variadic_cv_rvalue_ref_func = xte::is_variadic_cv_func<type> && xte::is_rvalue_ref_func<type>;

	template<typename type>
	concept is_variadic_const_ref_func = xte::is_variadic_const_func<type> && xte::is_ref_func<type>;

	template<typename type>
	concept is_variadic_volatile_ref_func = xte::is_variadic_volatile_func<type> && xte::is_ref_func<type>;

	template<typename type>
	concept is_variadic_cvref_func = xte::is_variadic_cv_func<type> && xte::is_ref_func<type>;

	template<typename type>
	concept is_variadic_noex_func = xte::is_variadic_func<type> && xte::is_noex_func<type>;

	template<typename type>
	concept is_variadic_const_noex_func = xte::is_variadic_const_func<type> && xte::is_noex_func<type>;

	template<typename type>
	concept is_variadic_volatile_noex_func = xte::is_variadic_volatile_func<type> && xte::is_noex_func<type>;

	template<typename type>
	concept is_variadic_cv_noex_func = xte::is_variadic_cv_func<type> && xte::is_noex_func<type>;

	template<typename type>
	concept is_variadic_lvalue_ref_noex_func = xte::is_variadic_noex_func<type> && xte::is_lvalue_ref_func<type>;

	template<typename type>
	concept is_variadic_rvalue_ref_noex_func = xte::is_variadic_noex_func<type> && xte::is_rvalue_ref_func<type>;

	template<typename type>
	concept is_variadic_ref_noex_func = xte::is_variadic_lvalue_ref_noex_func<type> || xte::is_variadic_rvalue_ref_noex_func<type>;

	template<typename type>
	concept is_variadic_const_lvalue_ref_noex_func = xte::is_variadic_const_noex_func<type> && xte::is_lvalue_ref_func<type>;

	template<typename type>
	concept is_variadic_volatile_lvalue_ref_noex_func = xte::is_variadic_volatile_noex_func<type> && xte::is_lvalue_ref_func<type>;

	template<typename type>
	concept is_variadic_cv_lvalue_ref_noex_func = xte::is_variadic_cv_noex_func<type> && xte::is_lvalue_ref_func<type>;

	template<typename type>
	concept is_variadic_const_rvalue_ref_noex_func = xte::is_variadic_const_noex_func<type> && xte::is_rvalue_ref_func<type>;

	template<typename type>
	concept is_variadic_volatile_rvalue_ref_noex_func = xte::is_variadic_volatile_noex_func<type> && xte::is_rvalue_ref_func<type>;

	template<typename type>
	concept is_variadic_cv_rvalue_ref_noex_func = xte::is_variadic_cv_noex_func<type> && xte::is_rvalue_ref_func<type>;

	template<typename type>
	concept is_variadic_const_ref_noex_func = xte::is_variadic_const_noex_func<type> && xte::is_ref_func<type>;

	template<typename type>
	concept is_variadic_volatile_ref_noex_func = xte::is_variadic_volatile_noex_func<type> && xte::is_ref_func<type>;

	template<typename type>
	concept is_variadic_cvref_noex_func = xte::is_variadic_cv_noex_func<type> && xte::is_ref_func<type>;

	template<typename type>
	using add_const_func = [:DETAIL_XTE::func_traits::add_const<type>:];

	template<typename type>
	using add_volatile_func = [:DETAIL_XTE::func_traits::add_volatile<type>:];

	template<typename type>
	using add_cv_func = xte::add_volatile_func<xte::add_const_func<type>>;

	template<typename type>
	using add_lvalue_ref_func = [:DETAIL_XTE::func_traits::add_lvalue_ref<type>:];

	template<typename type>
	using add_rvalue_ref_func = [:DETAIL_XTE::func_traits::add_rvalue_ref<type>:];

	template<typename type>
	using add_const_lvalue_ref_func = xte::add_lvalue_ref_func<xte::add_const_func<type>>;

	template<typename type>
	using add_volatile_lvalue_ref_func = xte::add_lvalue_ref_func<xte::add_volatile_func<type>>;

	template<typename type>
	using add_cv_lvalue_ref_func = xte::add_lvalue_ref_func<xte::add_cv_func<type>>;

	template<typename type>
	using add_const_rvalue_ref_func = xte::add_rvalue_ref_func<xte::add_const_func<type>>;

	template<typename type>
	using add_volatile_rvalue_ref_func = xte::add_rvalue_ref_func<xte::add_volatile_func<type>>;

	template<typename type>
	using add_cv_rvalue_ref_func = xte::add_rvalue_ref_func<xte::add_cv_func<type>>;

	template<typename type>
	using add_noex_func = [:DETAIL_XTE::func_traits::add_noex<type>:];

	template<typename type>
	using add_const_noex_func = xte::add_noex_func<xte::add_const_func<type>>;

	template<typename type>
	using add_volatile_noex_func = xte::add_noex_func<xte::add_volatile_func<type>>;

	template<typename type>
	using add_cv_noex_func = xte::add_noex_func<xte::add_cv_func<type>>;

	template<typename type>
	using add_lvalue_ref_noex_func = xte::add_noex_func<xte::add_lvalue_ref_func<type>>;

	template<typename type>
	using add_rvalue_ref_noex_func = xte::add_noex_func<xte::add_rvalue_ref_func<type>>;

	template<typename type>
	using add_const_lvalue_ref_noex_func = xte::add_noex_func<xte::add_const_lvalue_ref_func<type>>;

	template<typename type>
	using add_volatile_lvalue_ref_noex_func = xte::add_noex_func<xte::add_volatile_lvalue_ref_func<type>>;

	template<typename type>
	using add_cv_lvalue_ref_noex_func = xte::add_noex_func<xte::add_cv_lvalue_ref_func<type>>;

	template<typename type>
	using add_const_rvalue_ref_noex_func = xte::add_noex_func<xte::add_const_rvalue_ref_func<type>>;

	template<typename type>
	using add_volatile_rvalue_ref_noex_func = xte::add_noex_func<xte::add_volatile_rvalue_ref_func<type>>;

	template<typename type>
	using add_cv_rvalue_ref_noex_func = xte::add_noex_func<xte::add_cv_rvalue_ref_func<type>>;

	template<typename type>
	using add_variadic_func = [:DETAIL_XTE::func_traits::add_variadic_func<type>:];

	template<typename type>
	using add_variadic_const_func = xte::add_const_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_volatile_func = xte::add_volatile_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_cv_func = xte::add_cv_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_lvalue_ref_func = xte::add_lvalue_ref_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_rvalue_ref_func = xte::add_rvalue_ref_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_const_lvalue_ref_func = xte::add_const_lvalue_ref_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_volatile_lvalue_ref_func = xte::add_volatile_lvalue_ref_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_cv_lvalue_ref_func = xte::add_cv_lvalue_ref_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_const_rvalue_ref_func = xte::add_const_rvalue_ref_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_volatile_rvalue_ref_func = xte::add_volatile_rvalue_ref_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_cv_rvalue_ref_func = xte::add_cv_rvalue_ref_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_noex_func = xte::add_noex_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_const_noex_func = xte::add_const_noex_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_volatile_noex_func = xte::add_volatile_noex_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_cv_noex_func = xte::add_cv_noex_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_lvalue_ref_noex_func = xte::add_lvalue_ref_noex_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_rvalue_ref_noex_func = xte::add_rvalue_ref_noex_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_const_lvalue_ref_noex_func = xte::add_const_lvalue_ref_noex_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_volatile_lvalue_ref_noex_func = xte::add_volatile_lvalue_ref_noex_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_cv_lvalue_ref_noex_func = xte::add_cv_lvalue_ref_noex_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_const_rvalue_ref_noex_func = xte::add_const_rvalue_ref_noex_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_volatile_rvalue_ref_noex_func = xte::add_volatile_rvalue_ref_noex_func<xte::add_variadic_func<type>>;

	template<typename type>
	using add_variadic_cv_rvalue_ref_noex_func = xte::add_cv_rvalue_ref_noex_func<xte::add_variadic_func<type>>;

	template<typename type>
	using drop_const_func = [:DETAIL_XTE::func_traits::drop_const<type>:];

	template<typename type>
	using drop_volatile_func = [:DETAIL_XTE::func_traits::drop_volatile<type>:];

	template<typename type>
	using drop_cv_func = xte::drop_volatile_func<xte::drop_const_func<type>>;

	template<typename type>
	using drop_lvalue_ref_func = [:DETAIL_XTE::func_traits::drop_lvalue_ref<type>:];

	template<typename type>
	using drop_rvalue_ref_func = [:DETAIL_XTE::func_traits::drop_rvalue_ref<type>:];

	template<typename type>
	using drop_ref_func = xte::drop_rvalue_ref_func<xte::drop_lvalue_ref_func<type>>;

	template<typename type>
	using drop_const_lvalue_ref_func = xte::drop_lvalue_ref_func<xte::drop_const_func<type>>;

	template<typename type>
	using drop_volatile_lvalue_ref_func = xte::drop_lvalue_ref_func<xte::drop_volatile_func<type>>;

	template<typename type>
	using drop_cv_lvalue_ref_func = xte::drop_lvalue_ref_func<xte::drop_cv_func<type>>;

	template<typename type>
	using drop_const_rvalue_ref_func = xte::drop_rvalue_ref_func<xte::drop_const_func<type>>;

	template<typename type>
	using drop_volatile_rvalue_ref_func = xte::drop_rvalue_ref_func<xte::drop_volatile_func<type>>;

	template<typename type>
	using drop_cv_rvalue_ref_func = xte::drop_rvalue_ref_func<xte::drop_cv_func<type>>;

	template<typename type>
	using drop_const_ref_func = xte::drop_ref_func<xte::drop_const_func<type>>;

	template<typename type>
	using drop_volatile_ref_func = xte::drop_ref_func<xte::drop_volatile_func<type>>;

	template<typename type>
	using drop_cvref_func = xte::drop_ref_func<xte::drop_cv_func<type>>;

	template<typename type>
	using drop_noex_func = [:DETAIL_XTE::func_traits::drop_noex<type>:];

	template<typename type>
	using drop_const_noex_func = xte::drop_noex_func<xte::drop_const_func<type>>;

	template<typename type>
	using drop_volatile_noex_func = xte::drop_noex_func<xte::drop_volatile_func<type>>;

	template<typename type>
	using drop_cv_noex_func = xte::drop_noex_func<xte::drop_cv_func<type>>;

	template<typename type>
	using drop_lvalue_ref_noex_func = xte::drop_noex_func<xte::drop_lvalue_ref_func<type>>;

	template<typename type>
	using drop_rvalue_ref_noex_func = xte::drop_noex_func<xte::drop_rvalue_ref_func<type>>;

	template<typename type>
	using drop_ref_noex_func = xte::drop_noex_func<xte::drop_ref_func<type>>;

	template<typename type>
	using drop_const_lvalue_ref_noex_func = xte::drop_noex_func<xte::drop_const_lvalue_ref_func<type>>;

	template<typename type>
	using drop_volatile_lvalue_ref_noex_func = xte::drop_noex_func<xte::drop_volatile_lvalue_ref_func<type>>;

	template<typename type>
	using drop_cv_lvalue_ref_noex_func = xte::drop_noex_func<xte::drop_cv_lvalue_ref_func<type>>;

	template<typename type>
	using drop_const_rvalue_ref_noex_func = xte::drop_noex_func<xte::drop_const_rvalue_ref_func<type>>;

	template<typename type>
	using drop_volatile_rvalue_ref_noex_func = xte::drop_noex_func<xte::drop_volatile_rvalue_ref_func<type>>;

	template<typename type>
	using drop_cv_rvalue_ref_noex_func = xte::drop_noex_func<xte::drop_cv_rvalue_ref_func<type>>;

	template<typename type>
	using drop_const_ref_noex_func = xte::drop_noex_func<xte::drop_const_ref_func<type>>;

	template<typename type>
	using drop_volatile_ref_noex_func = xte::drop_noex_func<xte::drop_volatile_ref_func<type>>;

	template<typename type>
	using drop_cvref_noex_func = xte::drop_noex_func<xte::drop_cvref_func<type>>;

	template<typename type>
	using drop_variadic_func = [:DETAIL_XTE::func_traits::drop_variadic<type>:];

	template<typename type>
	using drop_variadic_const_func = xte::drop_const_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_volatile_func = xte::drop_volatile_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_cv_func = xte::drop_cv_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_lvalue_ref_func = xte::drop_lvalue_ref_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_rvalue_ref_func = xte::drop_rvalue_ref_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_ref_func = xte::drop_ref_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_const_lvalue_ref_func = xte::drop_const_lvalue_ref_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_volatile_lvalue_ref_func = xte::drop_volatile_lvalue_ref_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_cv_lvalue_ref_func = xte::drop_cv_lvalue_ref_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_const_rvalue_ref_func = xte::drop_const_rvalue_ref_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_volatile_rvalue_ref_func = xte::drop_volatile_rvalue_ref_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_cv_rvalue_ref_func = xte::drop_cv_rvalue_ref_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_const_ref_func = xte::drop_const_ref_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_volatile_ref_func = xte::drop_volatile_ref_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_cvref_func = xte::drop_cvref_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_noex_func = xte::drop_noex_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_const_noex_func = xte::drop_const_noex_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_volatile_noex_func = xte::drop_volatile_noex_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_cv_noex_func = xte::drop_cv_noex_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_lvalue_ref_noex_func = xte::drop_lvalue_ref_noex_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_rvalue_ref_noex_func = xte::drop_rvalue_ref_noex_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_ref_noex_func = xte::drop_ref_noex_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_const_lvalue_ref_noex_func = xte::drop_const_lvalue_ref_noex_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_volatile_lvalue_ref_noex_func = xte::drop_volatile_lvalue_ref_noex_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_cv_lvalue_ref_noex_func = xte::drop_cv_lvalue_ref_noex_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_const_rvalue_ref_noex_func = xte::drop_const_rvalue_ref_noex_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_volatile_rvalue_ref_noex_func = xte::drop_volatile_rvalue_ref_noex_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_cv_rvalue_ref_noex_func = xte::drop_cv_rvalue_ref_noex_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_const_ref_noex_func = xte::drop_const_ref_noex_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_volatile_ref_noex_func = xte::drop_volatile_ref_noex_func<xte::drop_variadic_func<type>>;

	template<typename type>
	using drop_variadic_cvref_noex_func = xte::drop_cvref_noex_func<xte::drop_variadic_func<type>>;

	template<typename source_type, typename target_type>
	using copy_const_func = [:xte::is_const_func<source_type> ? ^^xte::add_const_func<target_type> : ^^xte::drop_const_func<target_type>:];

	template<typename source_type, typename target_type>
	using copy_volatile_func = [:xte::is_volatile_func<source_type> ? ^^xte::add_volatile_func<target_type> : ^^xte::drop_volatile_func<target_type>:];

	template<typename source_type, typename target_type>
	using copy_cv_func = xte::copy_volatile_func<source_type, xte::copy_const_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_lvalue_ref_func = [:xte::is_lvalue_ref_func<source_type> ? ^^xte::add_lvalue_ref_func<target_type> : ^^xte::drop_lvalue_ref_func<target_type>:];

	template<typename source_type, typename target_type>
	using copy_rvalue_ref_func = [:xte::is_rvalue_ref_func<source_type> ? ^^xte::add_rvalue_ref_func<target_type> : ^^xte::drop_rvalue_ref_func<target_type>:];

	template<typename source_type, typename target_type>
	using copy_ref_func =
		[:xte::is_lvalue_ref_func<source_type>
			? ^^xte::add_lvalue_ref_func<target_type>
			: (xte::is_rvalue_ref_func<source_type>
				? ^^xte::add_rvalue_ref_func<target_type>
				: ^^xte::drop_ref_func<target_type>):];

	template<typename source_type, typename target_type>
	using copy_const_lvalue_ref_func = xte::copy_lvalue_ref_func<source_type, xte::copy_const_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_volatile_lvalue_ref_func = xte::copy_lvalue_ref_func<source_type, xte::copy_volatile_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_cv_lvalue_ref_func = xte::copy_lvalue_ref_func<source_type, xte::copy_cv_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_const_rvalue_ref_func = xte::copy_rvalue_ref_func<source_type, xte::copy_const_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_volatile_rvalue_ref_func = xte::copy_rvalue_ref_func<source_type, xte::copy_volatile_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_cv_rvalue_ref_func = xte::copy_rvalue_ref_func<source_type, xte::copy_cv_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_const_ref_func = xte::copy_ref_func<source_type, xte::copy_const_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_volatile_ref_func = xte::copy_ref_func<source_type, xte::copy_volatile_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_cvref_func = xte::copy_ref_func<source_type, xte::copy_cv_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_noex_func = [:xte::is_noex_func<source_type> ? ^^xte::add_noex_func<target_type> : ^^xte::drop_noex_func<target_type>:];

	template<typename source_type, typename target_type>
	using copy_const_noex_func = xte::copy_noex_func<source_type, xte::copy_const_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_volatile_noex_func = xte::copy_noex_func<source_type, xte::copy_volatile_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_cv_noex_func = xte::copy_noex_func<source_type, xte::copy_cv_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_lvalue_ref_noex_func = xte::copy_noex_func<source_type, xte::copy_lvalue_ref_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_rvalue_ref_noex_func = xte::copy_noex_func<source_type, xte::copy_rvalue_ref_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_ref_noex_func = xte::copy_noex_func<source_type, xte::copy_ref_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_const_lvalue_ref_noex_func = xte::copy_noex_func<source_type, xte::copy_const_lvalue_ref_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_volatile_lvalue_ref_noex_func = xte::copy_noex_func<source_type, xte::copy_volatile_lvalue_ref_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_cv_lvalue_ref_noex_func = xte::copy_noex_func<source_type, xte::copy_cv_lvalue_ref_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_const_rvalue_ref_noex_func = xte::copy_noex_func<source_type, xte::copy_const_rvalue_ref_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_volatile_rvalue_ref_noex_func = xte::copy_noex_func<source_type, xte::copy_volatile_rvalue_ref_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_cv_rvalue_ref_noex_func = xte::copy_noex_func<source_type, xte::copy_cv_rvalue_ref_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_const_ref_noex_func = xte::copy_noex_func<source_type, xte::copy_const_ref_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_volatile_ref_noex_func = xte::copy_noex_func<source_type, xte::copy_volatile_ref_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_cvref_noex_func = xte::copy_noex_func<source_type, xte::copy_cvref_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_func = [:xte::is_variadic_func<source_type> ? ^^xte::add_variadic_func<target_type> : ^^xte::drop_variadic_func<target_type>:];

	template<typename source_type, typename target_type>
	using copy_variadic_const_func = xte::copy_const_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_volatile_func = xte::copy_volatile_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_cv_func = xte::copy_cv_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_lvalue_ref_func = xte::copy_lvalue_ref_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_rvalue_ref_func = xte::copy_rvalue_ref_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_ref_func = xte::copy_ref_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_const_lvalue_ref_func = xte::copy_const_lvalue_ref_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_volatile_lvalue_ref_func = xte::copy_volatile_lvalue_ref_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_cv_lvalue_ref_func = xte::copy_cv_lvalue_ref_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_const_rvalue_ref_func = xte::copy_const_rvalue_ref_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_volatile_rvalue_ref_func = xte::copy_volatile_rvalue_ref_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_cv_rvalue_ref_func = xte::copy_cv_rvalue_ref_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_const_ref_func = xte::copy_const_ref_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_volatile_ref_func = xte::copy_volatile_ref_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_cvref_func = xte::copy_cvref_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_noex_func = xte::copy_noex_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_const_noex_func = xte::copy_const_noex_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_volatile_noex_func = xte::copy_volatile_noex_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_cv_noex_func = xte::copy_cv_noex_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_lvalue_ref_noex_func = xte::copy_lvalue_ref_noex_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_rvalue_ref_noex_func = xte::copy_rvalue_ref_noex_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_ref_noex_func = xte::copy_ref_noex_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_const_lvalue_ref_noex_func = xte::copy_const_lvalue_ref_noex_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_volatile_lvalue_ref_noex_func = xte::copy_volatile_lvalue_ref_noex_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_cv_lvalue_ref_noex_func = xte::copy_cv_lvalue_ref_noex_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_const_rvalue_ref_noex_func = xte::copy_const_rvalue_ref_noex_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_volatile_rvalue_ref_noex_func = xte::copy_volatile_rvalue_ref_noex_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_cv_rvalue_ref_noex_func = xte::copy_cv_rvalue_ref_noex_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_const_ref_noex_func = xte::copy_const_ref_noex_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_volatile_ref_noex_func = xte::copy_volatile_ref_noex_func<source_type, xte::copy_variadic_func<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_variadic_cvref_noex_func = xte::copy_cvref_noex_func<source_type, xte::copy_variadic_func<source_type, target_type>>;
}

#endif
