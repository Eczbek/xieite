#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_RVALUE_REF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_ADD_RVALUE_REF_FUNC

namespace DETAIL_XTE::add_rvalue_ref_func {
	template<typename func_type>
	constexpr auto impl = ^^func_type;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto impl<return_type(arg_types...) noexcept(noex_spec)> = ^^return_type(arg_types...) && noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto impl<return_type(arg_types..., ...) noexcept(noex_spec)> = ^^return_type(arg_types..., ...) && noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto impl<return_type(arg_types...) const noexcept(noex_spec)> = ^^return_type(arg_types...) const&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto impl<return_type(arg_types..., ...) const noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto impl<return_type(arg_types...) volatile noexcept(noex_spec)> = ^^return_type(arg_types...) volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto impl<return_type(arg_types..., ...) volatile noexcept(noex_spec)> = ^^return_type(arg_types..., ...) volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto impl<return_type(arg_types...) const volatile noexcept(noex_spec)> = ^^return_type(arg_types...) const volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto impl<return_type(arg_types..., ...) const volatile noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) noexcept(noex_spec)> = ^^return_type(class_type::*)(arg_types...) && noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) noexcept(noex_spec)> = ^^return_type(class_type::*)(arg_types..., ...) && noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) const noexcept(noex_spec)> = ^^return_type(class_type::*)(arg_types...) const&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) const noexcept(noex_spec)> = ^^return_type(class_type::*)(arg_types..., ...) const&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) volatile noexcept(noex_spec)> = ^^return_type(class_type::*)(arg_types...) volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) volatile noexcept(noex_spec)> = ^^return_type(class_type::*)(arg_types..., ...) volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types...) const volatile noexcept(noex_spec)> = ^^return_type(class_type::*)(arg_types...) const volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr auto impl<return_type(class_type::*)(arg_types..., ...) const volatile noexcept(noex_spec)> = ^^return_type(class_type::*)(arg_types..., ...) const volatile&& noexcept(noex_spec);
}

namespace xte {
	template<typename func_type>
	using add_rvalue_ref_func = [:DETAIL_XTE::add_rvalue_ref_func::impl<func_type>:];
}

#endif

// TODO: `xte::type<return_type(arg_types...) &> class_type::*`
