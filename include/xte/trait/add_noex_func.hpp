#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_NOEX_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_ADD_NOEX_FUNC

namespace DETAIL_XTE::add_noex_func {
	template<typename func_type>
	constexpr auto impl = ^^func_type;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...)> = ^^return_type(arg_types...) noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...)> = ^^return_type(arg_types..., ...) noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) const> = ^^return_type(arg_types...) const noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) const> = ^^return_type(arg_types..., ...) const noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) volatile> = ^^return_type(arg_types...) volatile noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) volatile> = ^^return_type(arg_types..., ...) volatile noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) const volatile> = ^^return_type(arg_types...) const volatile noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) const volatile> = ^^return_type(arg_types..., ...) const volatile noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) &> = ^^return_type(arg_types...) & noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) &> = ^^return_type(arg_types..., ...) & noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) const&> = ^^return_type(arg_types...) const& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) const&> = ^^return_type(arg_types..., ...) const& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) volatile&> = ^^return_type(arg_types...) volatile& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) volatile&> = ^^return_type(arg_types..., ...) volatile& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) const volatile&> = ^^return_type(arg_types...) const volatile& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) const volatile&> = ^^return_type(arg_types..., ...) const volatile& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) &&> = ^^return_type(arg_types...) && noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) &&> = ^^return_type(arg_types..., ...) && noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) const&&> = ^^return_type(arg_types...) const&& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) const&&> = ^^return_type(arg_types..., ...) const&& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) volatile&&> = ^^return_type(arg_types...) volatile&& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) volatile&&> = ^^return_type(arg_types..., ...) volatile&& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) const volatile&&> = ^^return_type(arg_types...) const volatile&& noexcept;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) const volatile&&> = ^^return_type(arg_types..., ...) const volatile&& noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...)> = ^^return_type(class_type::*)(arg_types...) noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...)> = ^^return_type(class_type::*)(arg_types..., ...) noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) const> = ^^return_type(class_type::*)(arg_types...) const noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) const> = ^^return_type(class_type::*)(arg_types..., ...) const noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) volatile> = ^^return_type(class_type::*)(arg_types...) volatile noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) volatile> = ^^return_type(class_type::*)(arg_types..., ...) volatile noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) const volatile> = ^^return_type(class_type::*)(arg_types...) const volatile noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) const volatile> = ^^return_type(class_type::*)(arg_types..., ...) const volatile noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) &> = ^^return_type(class_type::*)(arg_types...) & noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) &> = ^^return_type(class_type::*)(arg_types..., ...) & noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) const&> = ^^return_type(class_type::*)(arg_types...) const& noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) const&> = ^^return_type(class_type::*)(arg_types..., ...) const& noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) volatile&> = ^^return_type(class_type::*)(arg_types...) volatile& noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) volatile&> = ^^return_type(class_type::*)(arg_types..., ...) volatile& noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) const volatile&> = ^^return_type(class_type::*)(arg_types...) const volatile& noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) const volatile&> = ^^return_type(class_type::*)(arg_types..., ...) const volatile& noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) &&> = ^^return_type(class_type::*)(arg_types...) && noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) &&> = ^^return_type(class_type::*)(arg_types..., ...) && noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) const&&> = ^^return_type(class_type::*)(arg_types...) const&& noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) const&&> = ^^return_type(class_type::*)(arg_types..., ...) const&& noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) volatile&&> = ^^return_type(class_type::*)(arg_types...) volatile&& noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) volatile&&> = ^^return_type(class_type::*)(arg_types..., ...) volatile&& noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) const volatile&&> = ^^return_type(class_type::*)(arg_types...) const volatile&& noexcept;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) const volatile&&> = ^^return_type(class_type::*)(arg_types..., ...) const volatile&& noexcept;
}

namespace xte {
	template<typename func_type>
	using add_noex_func = [:DETAIL_XTE::add_noex_func::impl<func_type>:];
}

#endif

// TODO: `xte::type<return_type(arg_types...) &> class_type::*`
