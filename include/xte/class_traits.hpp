#ifndef DETAIL_XTE_HEADER_CLASS_TRAITS
#	define DETAIL_XTE_HEADER_CLASS_TRAITS
#
#	include "./diagnostic.hpp"
#	include "./meta/fake.hpp"
#	include "./qual_traits.hpp"
#	include <concepts>
#	include <meta>
#	include <type_traits>

namespace DETAIL_XTE::class_traits {
	template<typename, typename>
	constexpr bool is_callable = (([] {
		static_assert(false, "invalid signature");
	})(), false);

	template<typename func_type, typename return_type, typename... arg_types>
	constexpr bool is_callable<func_type, return_type(arg_types...)> =
		(std::is_void_v<return_type>
				? requires { xte::fake<func_type>()(xte::fake<arg_types>()...); }
				: requires ([:^^int(return_type):]& f) { f(xte::fake<func_type>()(xte::fake<arg_types>()...)); });

	template<typename func_type, typename return_type, typename... arg_types>
	constexpr bool is_callable<func_type, return_type(arg_types...) noexcept> =
		(std::is_void_v<return_type>
			? requires { { xte::fake<func_type>()(xte::fake<arg_types>()...) } noexcept; }
			: requires ([:^^int(return_type) noexcept:]& f) { { f(xte::fake<func_type>()(xte::fake<arg_types>()...)) } noexcept; });

	template<typename type, typename>
	constexpr bool is_invocable = (([] {
		static_assert(false, "invalid signature");
	})(), false);

	template<typename func_type, typename return_type, typename... arg_types>
	constexpr bool is_invocable<func_type, return_type(arg_types...)> = std::is_invocable_r_v<return_type, func_type, arg_types...>;

	template<typename>
	constexpr auto class_type_of = 0;

	template<typename class_type, typename member_type>
	constexpr auto class_type_of<member_type class_type::*> = ^^class_type;

	template<typename>
	constexpr auto member_type_of = 0;

	template<typename class_type, typename member_type>
	constexpr auto member_type_of<member_type class_type::*> = ^^member_type;
}

XTE_DIAGNOSTIC_PUSH((NO_CONVERSION))

namespace xte {
	template<typename target_type, typename... arg_types>
	concept is_constructible =
		((sizeof...(arg_types) == 1)
			? (requires { requires(std::is_void_v<arg_types...[0]>); }
				? requires { target_type(); }
				: requires { static_cast<target_type>(xte::fake<arg_types...[0]>()); })
			: requires { target_type(xte::fake<arg_types>()...); });

	template<typename target_type, typename... arg_types>
	concept is_constructible_noex =
		xte::is_constructible<target_type, arg_types...>
		&& ((sizeof...(arg_types) == 1)
			? (requires { requires(std::is_void_v<arg_types...[0]>); }
				? requires { { target_type() } noexcept; }
				: requires { { static_cast<target_type>(xte::fake<arg_types...[0]>()) } noexcept; })
			: requires { { target_type(xte::fake<arg_types>()...) } noexcept; });

	template<typename target_type, typename source_type = void>
	concept is_implicitly_constructible =
		xte::is_constructible<target_type, source_type>
		&& (std::is_void_v<source_type>
			? requires ([:^^int(target_type):]& f) { f({}); }
			: requires ([:^^int(target_type):]& f) { f(xte::fake<source_type>()); });

	template<typename target_type, typename source_type = void>
	concept is_implicitly_constructible_noex =
		xte::is_implicitly_constructible<target_type, source_type>
		&& (std::is_void_v<source_type>
			? requires ([:^^int(target_type) noexcept:]& f) { { f({}) } noexcept; }
			: requires ([:^^int(target_type) noexcept:]& f) { { f(xte::fake<source_type>()) } noexcept; });

	template<typename target_type, typename... arg_types>
	concept is_brace_constructible = requires { target_type { xte::fake<arg_types>()... }; };

	template<typename target_type, typename... arg_types>
	concept is_brace_constructible_noex =
		xte::is_brace_constructible<target_type, arg_types...>
		&& requires { { target_type { xte::fake<arg_types>()... } } noexcept; };

	template<typename type>
	concept is_copy_constructible = xte::is_constructible<type, type const&>;

	template<typename type>
	concept is_copy_constructible_noex = xte::is_constructible_noex<type, type const&>;

	template<typename type>
	concept is_implicitly_copy_constructible = xte::is_implicitly_constructible<type, type const&>;

	template<typename type>
	concept is_implicitly_copy_constructible_noex = xte::is_implicitly_constructible_noex<type, type const&>;

	template<typename type>
	concept is_move_constructible = xte::is_constructible<type, xte::drop_const_ref<type>>;

	template<typename type>
	concept is_move_constructible_noex = xte::is_constructible_noex<type, xte::drop_const_ref<type>>;

	template<typename type>
	concept is_implicitly_move_constructible = xte::is_implicitly_constructible<type, type>;

	template<typename type>
	concept is_implicitly_move_constructible_noex = xte::is_implicitly_constructible_noex<type, type>;

	template<typename source_type, typename target_type>
	concept is_convertible = xte::is_constructible<target_type, source_type>;

	template<typename source_type, typename target_type>
	concept is_convertible_noex = xte::is_constructible_noex<target_type, source_type>;

	template<typename source_type, typename target_type>
	concept is_implicitly_convertible = xte::is_implicitly_constructible<target_type, source_type>;

	template<typename source_type, typename target_type>
	concept is_implicitly_convertible_noex = xte::is_implicitly_constructible_noex<target_type, source_type>;

	template<typename target_type, typename source_type>
	concept is_assignable = requires { xte::fake<target_type>() = xte::fake<source_type>(); };

	template<typename target_type, typename source_type>
	concept is_assignable_noex = requires { { xte::fake<target_type>() = xte::fake<source_type>() } noexcept; };

	template<typename target_type, typename source_type>
	concept is_assignable_lvalue = requires { xte::fake<target_type&>() = xte::fake<source_type>(); };

	template<typename target_type, typename source_type>
	concept is_assignable_lvalue_noex = requires { { xte::fake<target_type&>() = xte::fake<source_type>() } noexcept; };

	template<typename source_type, typename target_type>
	concept is_assignable_to = xte::is_assignable<target_type, source_type>;

	template<typename source_type, typename target_type>
	concept is_assignable_to_noex = xte::is_assignable_noex<target_type, source_type>;

	template<typename type>
	concept is_copy_assignable = xte::is_assignable<type, type const&>;

	template<typename type>
	concept is_copy_assignable_noex = xte::is_assignable_noex<type, type const&>;

	template<typename type>
	concept is_move_assignable = xte::is_assignable<type, xte::drop_const_ref<type>>;

	template<typename type>
	concept is_move_assignable_noex = xte::is_assignable_noex<type, xte::drop_const_ref<type>>;

	template<typename type>
	concept is_destructible = std::is_destructible_v<type>;

	template<typename type>
	concept is_destructible_noex = xte::is_destructible<type> && std::is_nothrow_destructible_v<type>;

	template<typename type>
	concept is_bool_testable = requires (type&& x, [:^^int(bool):]& f) {
		static_cast<bool>(XTE_FWD(x));
		static_cast<bool>(!XTE_FWD(x));
		f(XTE_FWD(x));
		f(!XTE_FWD(x));
		// TODO: Check `operator&&` and `operator||` to best ability
	};

	template<typename type>
	concept is_bool_testable_noex = requires (type&& x, [:^^int(bool) noexcept:]& f) {
		{ static_cast<bool>(XTE_FWD(x)) } noexcept;
		{ static_cast<bool>(!XTE_FWD(x)) } noexcept;
		{ f(XTE_FWD(x)) } noexcept;
		{ f(!XTE_FWD(x)) } noexcept;
		// TODO: Check `operator&&` and `operator||` to best ability
	};

	template<typename member_type>
	concept is_swappable_noex = noexcept(std::ranges::swap(xte::fake<member_type&>(), xte::fake<member_type&>()));

	template<typename func_type, typename signature_type>
	concept is_callable = DETAIL_XTE::class_traits::is_callable<func_type, signature_type>;

	template<typename func_type, typename signature_type>
	concept is_callable_lvalue = xte::is_callable<func_type&, signature_type>;

	template<typename func_type, typename signature_type>
	concept is_invocable = DETAIL_XTE::class_traits::is_invocable<func_type, signature_type>;

	template<typename func_type, typename signature_type>
	concept is_invocable_lvalue = xte::is_invocable<func_type&, signature_type>;

	template<typename type>
	requires(std::is_member_pointer_v<type>)
	using member_type_of = [:DETAIL_XTE::class_traits::member_type_of<xte::drop_cv<type>>:];

	template<typename type>
	requires(std::is_member_pointer_v<type>)
	using class_type_of = [:DETAIL_XTE::class_traits::class_type_of<xte::drop_cv<type>>:];

	template<typename type, typename class_type>
	concept is_member_ptr_of = xte::is_same_drop_cv<class_type, xte::class_type_of<type>>;

	template<typename derived_type, typename base_type>
	concept is_derived_from = xte::is_convertible<xte::drop_cvref<derived_type>*, xte::drop_cvref<base_type>*>;

	template<typename derived_type, typename base_type>
	concept is_privately_derived_from =
		std::meta::is_class_type(^^derived_type)
		&& !xte::is_derived_from<derived_type, base_type>
		&& ([](this auto self, std::meta::info type) -> bool {
			for (std::meta::info base : std::meta::bases_of(type, std::meta::access_context::unchecked())) {
				base = std::meta::type_of(base);
				if ((base == std::meta::remove_cv(^^base_type))
					|| self(base))
				{
					return true;
				}
			}
			return false;
		})(^^derived_type);

	template<typename type, std::meta::info tmpl>
	concept is_specialization_of = std::meta::has_template_arguments(^^type) && (std::meta::template_of(^^type) == tmpl);

	template<typename derived_type, std::meta::info base_tmpl>
	concept is_derived_from_specialization_of =
		std::meta::is_class_type(^^derived_type)
		&& std::meta::is_class_template(base_tmpl)
		&& ((std::meta::has_template_arguments(^^derived_type)
				&& (std::meta::template_of(^^derived_type) == base_tmpl))
			|| ([](this auto self, std::meta::info type) -> bool {
				for (std::meta::info base : std::meta::bases_of(type, std::meta::access_context::current())) {
					base = std::meta::type_of(base);
					if ((std::meta::has_template_arguments(base)
							&& (std::meta::template_of(base) == base_tmpl))
						|| self(base))
					{
						return true;
					}
				}
				return false;
			})(^^derived_type));

	struct non_copyable {
		explicit(false) non_copyable() = default;

		non_copyable(xte::non_copyable const&) = delete;

		explicit(false) non_copyable(xte::non_copyable&&) = default;

		xte::non_copyable& operator=(xte::non_copyable const&) = delete;

		xte::non_copyable& operator=(xte::non_copyable&&) = default;
	};

	struct non_movable {
		explicit(false) non_movable() = default;

		non_movable(xte::non_movable const&) = delete;

		non_movable(xte::non_movable&&) = delete;

		xte::non_movable& operator=(xte::non_movable const&) = delete;

		xte::non_movable& operator=(xte::non_movable&&) = delete;
	};
}

XTE_DIAGNOSTIC_POP()

#endif

// https://timsong-cpp.github.io/cppwp/n4950/concept.booleantestable
