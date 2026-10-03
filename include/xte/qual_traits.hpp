#ifndef DETAIL_XTE_HEADER_QUAL_TRAITS
#	define DETAIL_XTE_HEADER_QUAL_TRAITS
#
#	include "./identity.hpp"
#	include <concepts>

namespace DETAIL_XTE::qual_traits {
	template<typename type>
	constexpr bool is_const = false;

	template<typename type>
	constexpr bool is_const<type const> = true;

	template<typename type>
	constexpr bool is_const<type const&> = true;

	template<typename type>
	constexpr bool is_const<type const&&> = true;

	template<typename type>
	constexpr bool is_volatile = false;

	template<typename type>
	constexpr bool is_volatile<type volatile> = true;

	template<typename type>
	constexpr bool is_volatile<type volatile&> = true;

	template<typename type>
	constexpr bool is_volatile<type volatile&&> = true;

	template<typename>
	constexpr bool is_lvalue_ref = false;

	template<typename type>
	constexpr bool is_lvalue_ref<type&> = true;

	template<typename>
	constexpr bool is_rvalue_ref = false;

	template<typename type>
	constexpr bool is_rvalue_ref<type&&> = true;

	template<typename type>
	constexpr auto add_const = ^^type const;

	template<typename type>
	constexpr auto add_const<type&> = ^^type const&;

	template<typename type>
	constexpr auto add_const<type&&> = ^^type const&&;

	template<typename type>
	constexpr auto add_volatile = ^^type volatile;

	template<typename type>
	constexpr auto add_volatile<type&> = ^^type volatile&;

	template<typename type>
	constexpr auto add_volatile<type&&> = ^^type volatile&&;

	template<typename type>
	constexpr auto add_lvalue_ref = ^^type&;

	template<>
	constexpr auto add_lvalue_ref<void> = ^^void;

	template<>
	constexpr auto add_lvalue_ref<void const> = ^^void const;

	template<>
	constexpr auto add_lvalue_ref<void volatile> = ^^void volatile;

	template<>
	constexpr auto add_lvalue_ref<void const volatile> = ^^void const volatile;

	template<typename type>
	constexpr auto add_rvalue_ref = ^^type&&;

	template<>
	constexpr auto add_rvalue_ref<void> = ^^void;

	template<>
	constexpr auto add_rvalue_ref<void const> = ^^void const;

	template<>
	constexpr auto add_rvalue_ref<void volatile> = ^^void volatile;

	template<>
	constexpr auto add_rvalue_ref<void const volatile> = ^^void const volatile;

	template<typename type>
	constexpr auto drop_const = ^^type;

	template<typename type>
	constexpr auto drop_const<type const> = ^^type;

	template<typename type>
	constexpr auto drop_const<type const&> = ^^type&;

	template<typename type>
	constexpr auto drop_const<type const&&> = ^^type&&;

	template<typename type>
	constexpr auto drop_volatile = ^^type;

	template<typename type>
	constexpr auto drop_volatile<type volatile> = ^^type;

	template<typename type>
	constexpr auto drop_volatile<type volatile&> = ^^type&;

	template<typename type>
	constexpr auto drop_volatile<type volatile&&> = ^^type&&;

	template<typename type>
	constexpr auto drop_lvalue_ref = ^^type;

	template<typename type>
	constexpr auto drop_lvalue_ref<type&> = ^^type;

	template<typename type>
	constexpr auto drop_rvalue_ref = ^^type;

	template<typename type>
	constexpr auto drop_rvalue_ref<type&&> = ^^type;

	template<typename, typename target_type>
	constexpr auto copy_ref = ^^target_type;

	template<typename source_type, typename target_type>
	constexpr auto copy_ref<source_type, target_type&> = ^^target_type;

	template<typename source_type, typename target_type>
	constexpr auto copy_ref<source_type, target_type&&> = ^^target_type;

	template<typename source_type, typename target_type>
	constexpr auto copy_ref<source_type&, target_type> = ^^target_type&;

	template<typename source_type, typename target_type>
	constexpr auto copy_ref<source_type&, target_type&> = ^^target_type&;

	template<typename source_type, typename target_type>
	constexpr auto copy_ref<source_type&, target_type&&> = ^^target_type&;

	template<typename source_type, typename target_type>
	constexpr auto copy_ref<source_type&&, target_type> = ^^target_type&&;

	template<typename source_type, typename target_type>
	constexpr auto copy_ref<source_type&&, target_type&> = ^^target_type&&;

	template<typename source_type, typename target_type>
	constexpr auto copy_ref<source_type&&, target_type&&> = ^^target_type&&;
}

namespace xte {
	template<typename type>
	concept is_const = DETAIL_XTE::qual_traits::is_const<type>;

	template<typename type>
	concept is_volatile = DETAIL_XTE::qual_traits::is_volatile<type>;

	template<typename type>
	concept is_cv = xte::is_const<type> && xte::is_volatile<type>;

	template<typename type>
	concept is_lvalue_ref = DETAIL_XTE::qual_traits::is_lvalue_ref<type>;

	template<typename type>
	concept is_rvalue_ref = DETAIL_XTE::qual_traits::is_rvalue_ref<type>;

	template<typename type>
	concept is_ref = xte::is_lvalue_ref<type> || xte::is_rvalue_ref<type>;

	template<typename type>
	concept is_const_lvalue_ref = xte::is_const<type> && xte::is_lvalue_ref<type>;

	template<typename type>
	concept is_const_rvalue_ref = xte::is_const<type> && xte::is_rvalue_ref<type>;

	template<typename type>
	concept is_const_ref = xte::is_const<type> && xte::is_ref<type>;
	
	template<typename type>
	concept is_volatile_lvalue_ref = xte::is_volatile<type> && xte::is_lvalue_ref<type>;

	template<typename type>
	concept is_volatile_rvalue_ref = xte::is_volatile<type> && xte::is_rvalue_ref<type>;

	template<typename type>
	concept is_volatile_ref = xte::is_volatile<type> && xte::is_ref<type>;

	template<typename type>
	concept is_cv_lvalue_ref = xte::is_cv<type> && xte::is_lvalue_ref<type>;

	template<typename type>
	concept is_cv_rvalue_ref = xte::is_cv<type> && xte::is_rvalue_ref<type>;

	template<typename type>
	concept is_cvref = xte::is_cv<type> && xte::is_ref<type>;

	template<typename type>
	using add_const = [:DETAIL_XTE::qual_traits::add_const<type>:];

	template<typename type>
	using add_volatile = [:DETAIL_XTE::qual_traits::add_volatile<type>:];

	template<typename type>
	using add_cv = xte::add_volatile<xte::add_const<type>>;

	template<typename type>
	using add_lvalue_ref = [:DETAIL_XTE::qual_traits::add_lvalue_ref<type>:];

	template<typename type>
	using add_rvalue_ref = [:DETAIL_XTE::qual_traits::add_rvalue_ref<type>:];

	template<typename type>
	using add_const_lvalue_ref = xte::add_lvalue_ref<xte::add_const<type>>;

	template<typename type>
	using add_const_rvalue_ref = xte::add_rvalue_ref<xte::add_const<type>>;

	template<typename type>
	using add_volatile_lvalue_ref = xte::add_lvalue_ref<xte::add_volatile<type>>;

	template<typename type>
	using add_volatile_rvalue_ref = xte::add_rvalue_ref<xte::add_volatile<type>>;

	template<typename type>
	using add_cv_lvalue_ref = xte::add_lvalue_ref<xte::add_cv<type>>;

	template<typename type>
	using add_cv_rvalue_ref = xte::add_rvalue_ref<xte::add_cv<type>>;

	template<typename type>
	using drop_const = [:DETAIL_XTE::qual_traits::drop_const<type>:];

	template<typename type>
	using drop_volatile = [:DETAIL_XTE::qual_traits::drop_volatile<type>:];

	template<typename type>
	using drop_cv = xte::drop_volatile<xte::drop_const<type>>;

	template<typename type>
	using drop_lvalue_ref = [:DETAIL_XTE::qual_traits::drop_lvalue_ref<type>:];

	template<typename type>
	using drop_rvalue_ref = [:DETAIL_XTE::qual_traits::drop_rvalue_ref<type>:];

	template<typename type>
	using drop_ref = xte::drop_rvalue_ref<xte::drop_lvalue_ref<type>>;

	template<typename type>
	using drop_const_lvalue_ref = xte::drop_lvalue_ref<xte::drop_const<type>>;

	template<typename type>
	using drop_const_rvalue_ref = xte::drop_rvalue_ref<xte::drop_const<type>>;

	template<typename type>
	using drop_const_ref = xte::drop_ref<xte::drop_const<type>>;

	template<typename type>
	using drop_volatile_lvalue_ref = xte::drop_lvalue_ref<xte::drop_volatile<type>>;

	template<typename type>
	using drop_volatile_rvalue_ref = xte::drop_rvalue_ref<xte::drop_volatile<type>>;

	template<typename type>
	using drop_volatile_ref = xte::drop_ref<xte::drop_volatile<type>>;

	template<typename type>
	using drop_cv_lvalue_ref = xte::drop_lvalue_ref<xte::drop_cv<type>>;

	template<typename type>
	using drop_cv_rvalue_ref = xte::drop_rvalue_ref<xte::drop_cv<type>>;

	template<typename type>
	using drop_cvref = xte::drop_ref<xte::drop_cv<type>>;

	template<typename source_type, typename target_type>
	using copy_const = [:xte::is_const<source_type> ? ^^xte::add_const<target_type> : ^^xte::drop_const<target_type>:];

	template<typename source_type, typename target_type>
	using copy_volatile = [:xte::is_volatile<source_type> ? ^^xte::add_volatile<target_type> : ^^xte::drop_volatile<target_type>:];

	template<typename source_type, typename target_type>
	using copy_cv = xte::copy_volatile<source_type, xte::copy_const<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_lvalue_ref = [:xte::is_lvalue_ref<source_type> ? ^^xte::add_lvalue_ref<target_type> : ^^xte::drop_lvalue_ref<target_type>:];

	template<typename source_type, typename target_type>
	using copy_rvalue_ref = [:xte::is_rvalue_ref<source_type> ? ^^xte::add_rvalue_ref<xte::drop_ref<target_type>> : ^^xte::drop_rvalue_ref<target_type>:];

	template<typename source_type, typename target_type>
	using copy_ref = [:DETAIL_XTE::qual_traits::copy_ref<source_type, target_type>:];

	template<typename source_type, typename target_type>
	using copy_const_lvalue_ref = xte::copy_lvalue_ref<source_type, xte::copy_const<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_const_rvalue_ref = xte::copy_rvalue_ref<source_type, xte::copy_const<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_const_ref = xte::copy_ref<source_type, xte::copy_const<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_volatile_lvalue_ref = xte::copy_lvalue_ref<source_type, xte::copy_volatile<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_volatile_rvalue_ref = xte::copy_rvalue_ref<source_type, xte::copy_volatile<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_volatile_ref = xte::copy_ref<source_type, xte::copy_volatile<source_type, target_type>>;

	template<typename source_type, typename target_type>
	using copy_cv_lvalue_ref = xte::copy_lvalue_ref<source_type, xte::copy_cv<source_type, target_type>>;
	
	template<typename source_type, typename target_type>
	using copy_cv_rvalue_ref = xte::copy_rvalue_ref<source_type, xte::copy_cv<source_type, target_type>>;
	
	template<typename source_type, typename target_type>
	using copy_cvref = xte::copy_ref<source_type, xte::copy_cv<source_type, target_type>>;

	template<typename type, typename... types>
	concept is_same = (... && std::same_as<type, types>);

	template<typename type, typename... types>
	concept is_same_drop_cv = xte::is_same<xte::drop_cv<type>, xte::drop_cv<types>...>;

	template<typename type, typename... types>
	concept is_same_drop_cvref = xte::is_same<xte::drop_cvref<type>, xte::drop_cvref<types>...>;

	template<typename type, typename... types>
	concept is_same_any = (... || xte::is_same<type, types>);

	template<typename type, typename... types>
	concept is_same_any_drop_cv = (... || xte::is_same_drop_cv<type, types>);

	template<typename type, typename... types>
	concept is_same_any_drop_cvref = (... || xte::is_same_drop_cvref<type, types>);

	inline constexpr auto as_const = [][[nodiscard]](auto&& x) static noexcept -> xte::add_const<decltype(x)&&> {
		return { XTE_FWD(x) };
	};

	inline constexpr auto as_volatile = [][[nodiscard]](auto&& x) static noexcept -> xte::add_volatile<decltype(x)&&> {
		return { XTE_FWD(x) };
	};

	inline constexpr auto as_mutable = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return const_cast<xte::drop_const<decltype(x)&&>>(x);
	};

	inline constexpr auto as_not_volatile = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return const_cast<xte::drop_volatile<decltype(x)&&>>(x);
	};

	inline constexpr auto as_lvalue = [][[nodiscard]](auto&& x) static noexcept -> decltype(x)& {
		return { x };
	};

	inline constexpr auto as_xvalue = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return static_cast<xte::drop_ref<decltype(x)>&&>(x);
	};

	template<typename source_type>
	constexpr auto like = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return [:xte::is_const<source_type> ? ^^xte::as_const : ^^xte::identity:]([:xte::is_volatile<source_type> ? ^^xte::as_volatile : ^^xte::identity:]([:xte::is_lvalue_ref<source_type> ? ^^xte::identity : ^^xte::as_xvalue:](x)));
	};

	inline constexpr auto as_xvalue_if_noex =
		[][[nodiscard]](auto&& x) noexcept -> auto&&
		requires(requires { { auto(xte::as_xvalue(x)) } noexcept; }
			|| requires { auto(x); })
		{
			if constexpr (requires { { auto(xte::as_xvalue(x)) } noexcept; }) {
				return xte::as_xvalue(x);
			} else {
				return xte::as_const(x);
			}
		};
}

#endif
