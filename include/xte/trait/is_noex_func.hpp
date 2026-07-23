#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_FUNC
#
#	include "../trait/drop_cvref.hpp"
#	include "../trait/drop_ptr.hpp"
#	include "../trait/is_func.hpp"

namespace DETAIL_XTE::is_noex_func {
	template<typename>
	constexpr bool impl = false;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types...) noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types..., ...) noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types...) const noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types..., ...) const noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types...) volatile noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types..., ...) volatile noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types...) const volatile noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types..., ...) const volatile noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types...) & noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types..., ...) & noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types...) const& noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types..., ...) const& noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types...) volatile& noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types..., ...) volatile& noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types...) const volatile& noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types..., ...) const volatile& noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types...) && noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types..., ...) && noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types...) const&& noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types..., ...) const&& noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types...) volatile&& noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types..., ...) volatile&& noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types...) const volatile&& noexcept> = true;

	template<typename return_type, typename... arg_types>
	constexpr bool impl<return_type(arg_types..., ...) const volatile&& noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types...) noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types...) const noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types...) volatile noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) volatile noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types...) const volatile noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const volatile noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types...) & noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) & noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types...) const& noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const& noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types...) volatile& noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) volatile& noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types...) const volatile& noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const volatile& noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types...) && noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) && noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types...) const&& noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const&& noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types...) volatile&& noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) volatile&& noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types...) const volatile&& noexcept> = true;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr bool impl<return_type(class_type::*)(arg_types..., ...) const volatile&& noexcept> = true;
}

namespace xte {
	template<typename func_type>
	concept is_noex_func = xte::is_func<func_type> && DETAIL_XTE::is_noex_func::impl<xte::drop_cvref<xte::drop_ptr<func_type>>>;
}

#endif

// TODO: `xte::type<return_type(arg_types...) &> class_type::*`
