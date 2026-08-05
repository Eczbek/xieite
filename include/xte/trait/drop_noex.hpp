#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_DROP_NOEX

namespace DETAIL_XTE::drop_noex {
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
	using drop_noex = [:DETAIL_XTE::drop_noex::impl<func_type>:];
}

#endif

// TODO: `xte::type<return_type(arg_types...) &> class_type::*`
