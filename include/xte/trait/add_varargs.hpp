#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_VARARGS
#	define DETAIL_XTE_HEADER_TRAIT_ADD_VARARGS
#
#	include "../meta/member_type.hpp"

namespace DETAIL_XTE::add_varargs {
	template<typename func_type>
	constexpr auto impl = ^^func_type;

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto impl<return_type(arg_types...) noexcept(noex_spec)> = ^^return_type(arg_types..., ...) noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto impl<return_type(arg_types...) const noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto impl<return_type(arg_types...) volatile noexcept(noex_spec)> = ^^return_type(arg_types..., ...) volatile noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto impl<return_type(arg_types...) const volatile noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const volatile noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto impl<return_type(arg_types...) & noexcept(noex_spec)> = ^^return_type(arg_types..., ...) & noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto impl<return_type(arg_types...) const& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto impl<return_type(arg_types...) volatile& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto impl<return_type(arg_types...) const volatile& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const volatile& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto impl<return_type(arg_types...) && noexcept(noex_spec)> = ^^return_type(arg_types..., ...) && noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto impl<return_type(arg_types...) const&& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto impl<return_type(arg_types...) volatile&& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec>
	constexpr auto impl<return_type(arg_types...) const volatile&& noexcept(noex_spec)> = ^^return_type(arg_types..., ...) const volatile&& noexcept(noex_spec);

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) noexcept(noex_spec)>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) noexcept(noex_spec)>;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) const noexcept(noex_spec)>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) const noexcept(noex_spec)>;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) volatile noexcept(noex_spec)>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) volatile noexcept(noex_spec)>;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) const volatile noexcept(noex_spec)>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) const volatile noexcept(noex_spec)>;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) & noexcept(noex_spec)>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) & noexcept(noex_spec)>;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) const& noexcept(noex_spec)>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) const& noexcept(noex_spec)>;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) volatile& noexcept(noex_spec)>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) volatile& noexcept(noex_spec)>;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) const volatile& noexcept(noex_spec)>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) const volatile& noexcept(noex_spec)>;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) && noexcept(noex_spec)>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) && noexcept(noex_spec)>;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) const&& noexcept(noex_spec)>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) const&& noexcept(noex_spec)>;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) volatile&& noexcept(noex_spec)>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) volatile&& noexcept(noex_spec)>;

	template<typename return_type, typename... arg_types, bool noex_spec, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) const volatile&& noexcept(noex_spec)>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) const volatile&& noexcept(noex_spec)>;
}

namespace xte {
	template<typename func_type>
	using add_varargs = [:DETAIL_XTE::add_varargs::impl<func_type>:];
}

#endif
