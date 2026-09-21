#ifndef DETAIL_XTE_HEADER_MATH_CLAMP
#	define DETAIL_XTE_HEADER_MATH_CLAMP
#
#	include "../assign.hpp"
#	include "../compare.hpp"
#	include "../exchange.hpp"
#	include "../in_place.hpp"
#	include "../make.hpp"
#	include "../opt.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include <type_traits>

namespace xte {
	template<typename first_type, typename... rest_types,
		typename common_type = std::common_type_t<first_type, rest_types...>>
	[[nodiscard]] constexpr common_type min(first_type&& first, rest_types&&... rest)
	noexcept(noexcept(static_cast<common_type>(XTE_FWD(first)))
		&& (... && requires (common_type min) {
			{ xte::less(rest, min) } noexcept;
			{ xte::assign(min, XTE_FWD(rest)) } noexcept;
		}))
	requires(requires { static_cast<common_type>(XTE_FWD(first)); }
		&& (... && requires (common_type min) {
			xte::less(rest, min);
			xte::assign(min, XTE_FWD(rest));
		}))
	{
		auto min = xte::make<common_type>(XTE_FWD(first));
		(..., (xte::less(rest, min) ? void(xte::assign(min, XTE_FWD(rest))) : void()));
		return min;
	}

	template<typename first_type, typename... rest_types,
		typename common_type = std::common_type_t<first_type, rest_types...>>
	[[nodiscard]] constexpr common_type max(first_type&& first, rest_types&&... rest)
	noexcept(noexcept(static_cast<common_type>(XTE_FWD(first)))
		&& (... && requires (common_type max) {
			{ xte::less(max, rest) } noexcept;
			{ xte::assign(max, XTE_FWD(rest)) } noexcept;
		}))
	requires(requires { static_cast<common_type>(XTE_FWD(first)); }
		&& (... && requires (common_type max) {
			xte::less(max, rest);
			xte::assign(max, XTE_FWD(rest));
		}))
	{
		auto max = xte::make<common_type>(XTE_FWD(first));
		(..., (xte::less(max, rest) ? void(xte::assign(max, XTE_FWD(rest))) : void()));
		return max;
	}

	template<typename first_type, typename... rest_types,
		typename common_type = std::common_type_t<first_type, rest_types...>>
	[[nodiscard]] constexpr auto minmax(first_type&& first, rest_types&&... rest)
	noexcept(noexcept(static_cast<common_type>(XTE_FWD(first)))
		&& (sizeof...(rest)
			? (... && requires (common_type minmax) {
				{ xte::less(minmax, rest) } noexcept;
				{ xte::construct(minmax, XTE_FWD(rest)) } noexcept;
				{ xte::assign(minmax, XTE_FWD(rest)) } noexcept;
			})
			: noexcept(static_cast<common_type>(first))))
	requires(requires { static_cast<common_type>(XTE_FWD(first)); }
		&& (sizeof...(rest)
			? (... && requires (common_type minmax) {
				xte::less(minmax, rest);
				xte::construct(minmax, XTE_FWD(rest));
				xte::assign(minmax, XTE_FWD(rest));
			})
			: requires { static_cast<common_type>(first); }))
	{
		struct return_type {
			common_type min;
			common_type max;
		};
		if constexpr (sizeof...(rest)) {
			xte::opt<common_type> min = XTE_FWD(first);
			xte::opt<common_type> max;
			auto* min_ptr = &min;
			auto* max_ptr = &max;
			(..., (xte::less(rest, **min_ptr)
				? (!*max_ptr && (min_ptr = xte::exchange(max_ptr, min_ptr)),
					void(*min_ptr = XTE_FWD(rest)))
				: ((!*max_ptr || xte::less(**max_ptr, rest))
					? void(*max_ptr = XTE_FWD(rest))
					: void())));
			return return_type { *xte::as_xvalue(*min_ptr), *xte::as_xvalue(*max_ptr) };
		} else {
			return return_type { first, XTE_FWD(first) };
		}
	}

	template<typename value_type, typename limit_type0, typename limit_type1,
		typename common_type = std::common_type_t<value_type, limit_type0, limit_type1>>
	[[nodiscard]] constexpr common_type clamp(value_type&& value, limit_type0&& limit0, limit_type1&& limit1) XTE_RETURNS_FIXED(
		xte::less(limit0, limit1)
			? (xte::less(value, limit0)
				? xte::make<common_type>(limit0)
				: (xte::less(limit1, value)
					? xte::make<common_type>(limit1)
					: xte::make<common_type>(value)))
			: (xte::less(value, limit1)
				? xte::make<common_type>(limit1)
				: (xte::less(limit0, value)
					? xte::make<common_type>(limit0)
					: xte::make<common_type>(value)))
	)

}

#endif
