#ifndef DETAIL_XTE_HEADER_QUAL_CAST
#	define DETAIL_XTE_HEADER_QUAL_CAST
#
#	include "./identity.hpp"
#	include "./preproc/fwd.hpp"
#	include "./trait/add_const.hpp"
#	include "./trait/add_volatile.hpp"
#	include "./trait/drop_const.hpp"
#	include "./trait/drop_ref.hpp"
#	include "./trait/drop_volatile.hpp"
#	include "./trait/is_const.hpp"
#	include "./trait/is_lvalue_ref.hpp"
#	include "./trait/is_volatile.hpp"

namespace xte {
	inline constexpr auto as_lvalue = [][[nodiscard]](auto&& x) static noexcept -> decltype(x)& {
		return { x };
	};

	inline constexpr auto as_xvalue = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return static_cast<xte::drop_ref<decltype(x)>&&>(x);
	};

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

	template<typename T>
	constexpr auto like = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return [:xte::is_const<T> ? ^^xte::as_const : ^^xte::identity:]([:xte::is_volatile<T> ? ^^xte::as_volatile : ^^xte::identity:]([:xte::is_lvalue_ref<T> ? ^^xte::identity : ^^xte::as_xvalue:](x)));
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
