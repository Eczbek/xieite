#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_NOEX_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_DROP_NOEX_FUNC

namespace DETAIL_XTE::drop_noex_func {
	template<typename func_type>
	constexpr auto impl = ^^func_type;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) noexcept> = ^^return_type(arg_types...);

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) noexcept> = ^^return_type(arg_types..., ...);

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) const noexcept> = ^^return_type(arg_types...) const;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) const noexcept> = ^^return_type(arg_types..., ...) const;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) volatile noexcept> = ^^return_type(arg_types...) volatile;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) volatile noexcept> = ^^return_type(arg_types..., ...) volatile;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) const volatile noexcept> = ^^return_type(arg_types...) const volatile;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) const volatile noexcept> = ^^return_type(arg_types..., ...) const volatile;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) & noexcept> = ^^return_type(arg_types...) &;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) & noexcept> = ^^return_type(arg_types..., ...) &;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) const& noexcept> = ^^return_type(arg_types...) const&;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) const& noexcept> = ^^return_type(arg_types..., ...) const&;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) volatile& noexcept> = ^^return_type(arg_types...) volatile&;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) volatile& noexcept> = ^^return_type(arg_types..., ...) volatile&;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) const volatile& noexcept> = ^^return_type(arg_types...) const volatile&;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) const volatile& noexcept> = ^^return_type(arg_types..., ...) const volatile&;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) && noexcept> = ^^return_type(arg_types...) &&;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) && noexcept> = ^^return_type(arg_types..., ...) &&;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) const&& noexcept> = ^^return_type(arg_types...) const&&;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) const&& noexcept> = ^^return_type(arg_types..., ...) const&&;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) volatile&& noexcept> = ^^return_type(arg_types...) volatile&&;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) volatile&& noexcept> = ^^return_type(arg_types..., ...) volatile&&;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types...) const volatile&& noexcept> = ^^return_type(arg_types...) const volatile&&;

	template<typename return_type, typename... arg_types>
	constexpr auto impl<return_type(arg_types..., ...) const volatile&& noexcept> = ^^return_type(arg_types..., ...) const volatile&&;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) noexcept> = ^^return_type(class_type::*)(arg_types...);

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) noexcept> = ^^return_type(class_type::*)(arg_types..., ...);

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) const noexcept> = ^^return_type(class_type::*)(arg_types...) const;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) const noexcept> = ^^return_type(class_type::*)(arg_types..., ...) const;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) volatile noexcept> = ^^return_type(class_type::*)(arg_types...) volatile;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) volatile noexcept> = ^^return_type(class_type::*)(arg_types..., ...) volatile;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) const volatile noexcept> = ^^return_type(class_type::*)(arg_types...) const volatile;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) const volatile noexcept> = ^^return_type(class_type::*)(arg_types..., ...) const volatile;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) & noexcept> = ^^return_type(class_type::*)(arg_types...) &;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) & noexcept> = ^^return_type(class_type::*)(arg_types..., ...) &;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) const& noexcept> = ^^return_type(class_type::*)(arg_types...) const&;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) const& noexcept> = ^^return_type(class_type::*)(arg_types..., ...) const&;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) volatile& noexcept> = ^^return_type(class_type::*)(arg_types...) volatile&;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) volatile& noexcept> = ^^return_type(class_type::*)(arg_types..., ...) volatile&;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) const volatile& noexcept> = ^^return_type(class_type::*)(arg_types...) const volatile&;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) const volatile& noexcept> = ^^return_type(class_type::*)(arg_types..., ...) const volatile&;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) && noexcept> = ^^return_type(class_type::*)(arg_types...) &&;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) && noexcept> = ^^return_type(class_type::*)(arg_types..., ...) &&;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) const&& noexcept> = ^^return_type(class_type::*)(arg_types...) const&&;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) const&& noexcept> = ^^return_type(class_type::*)(arg_types..., ...) const&&;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) volatile&& noexcept> = ^^return_type(class_type::*)(arg_types...) volatile&&;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) volatile&& noexcept> = ^^return_type(class_type::*)(arg_types..., ...) volatile&&;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) const volatile&& noexcept> = ^^return_type(class_type::*)(arg_types...) const volatile&&;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) const volatile&& noexcept> = ^^return_type(class_type::*)(arg_types..., ...) const volatile&&;
}

namespace xte {
	template<typename func_type>
	using drop_noex_func = [:DETAIL_XTE::drop_noex_func::impl<func_type>:];
}

#endif

// TODO: `xte::type<return_type(arg_types...) &> class_type::*`
