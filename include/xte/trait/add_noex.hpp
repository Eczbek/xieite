#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_ADD_NOEX
#
#	include "../meta/member_type.hpp"

namespace DETAIL_XTE::add_noex {
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
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...)>> = ^^xte::member_type<class_type, return_type(arg_types...) noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types..., ...)>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) const>> = ^^xte::member_type<class_type, return_type(arg_types...) const noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types..., ...) const>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) const noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) volatile>> = ^^xte::member_type<class_type, return_type(arg_types...) volatile noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types..., ...) volatile>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) volatile noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) const volatile>> = ^^xte::member_type<class_type, return_type(arg_types...) const volatile noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types..., ...) const volatile>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) const volatile noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) &>> = ^^xte::member_type<class_type, return_type(arg_types...) & noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types..., ...) &>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) & noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) const&>> = ^^xte::member_type<class_type, return_type(arg_types...) const& noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types..., ...) const&>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) const& noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) volatile&>> = ^^xte::member_type<class_type, return_type(arg_types...) volatile& noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types..., ...) volatile&>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) volatile& noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) const volatile&>> = ^^xte::member_type<class_type, return_type(arg_types...) const volatile& noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types..., ...) const volatile&>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) const volatile& noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) &&>> = ^^xte::member_type<class_type, return_type(arg_types...) && noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types..., ...) &&>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) && noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) const&&>> = ^^xte::member_type<class_type, return_type(arg_types...) const&& noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types..., ...) const&&>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) const&& noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) volatile&&>> = ^^xte::member_type<class_type, return_type(arg_types...) volatile&& noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types..., ...) volatile&&>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) volatile&& noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types...) const volatile&&>> = ^^xte::member_type<class_type, return_type(arg_types...) const volatile&& noexcept>;

	template<typename return_type, typename... arg_types, typename class_type>
	constexpr auto impl<xte::member_type<class_type, return_type(arg_types..., ...) const volatile&&>> = ^^xte::member_type<class_type, return_type(arg_types..., ...) const volatile&& noexcept>;
}

namespace xte {
	template<typename func_type>
	using add_noex = [:DETAIL_XTE::add_noex::impl<func_type>:];
}

#endif
