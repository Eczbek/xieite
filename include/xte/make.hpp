#ifndef DETAIL_XTE_HEADER_MAKE
#	define DETAIL_XTE_HEADER_MAKE
#
#	include "./compare.hpp"
#	include "./limits.hpp"
#	include "./math/float.hpp"
#	include "./preproc/fwd.hpp"
#	include "./preproc/lift.hpp"
#	include "./preproc/returns.hpp"
#	include "./qual_cast.hpp"
#	include "./trait/is_arithmetic.hpp"
#	include "./trait/is_float.hpp"
#	include "./trait/is_int.hpp"
#	include <cmath>
#	include <limits>

namespace DETAIL_XTE::make {
	template<typename target_type, typename... arg_types>
	requires(sizeof...(arg_types) == 1)
	[[nodiscard]] constexpr auto cast_one(arg_types&&... args) XTE_RETURNS(
		static_cast<target_type>(XTE_FWD(args...[0]))
	)

	template<typename target_type>
	[[nodiscard]] constexpr auto impl(auto&&... args) XTE_RETURNS_FIRST(
		(DETAIL_XTE::make::cast_one<target_type>(XTE_FWD(args)...))
		(DETAIL_XTE::make::cast_one<target_type>(xte::as_const(args)...))
		(target_type(XTE_FWD(args)...))
	)

	template<xte::is_arithmetic target_type, xte::is_arithmetic source_type>
	[[nodiscard]] constexpr target_type impl(source_type arg) noexcept {
		if constexpr (xte::is_float<target_type>) {
			if (xte::less(xte::highest<target_type>, arg)) {
				if constexpr (std::numeric_limits<target_type>::has_infinity) {
					return std::numeric_limits<target_type>::infinity();
				} else {
					return xte::highest<target_type>;
				}
			} else if (xte::less(arg, xte::lowest<target_type>)) {
				if constexpr (std::numeric_limits<target_type>::has_infinity) {
					return -std::numeric_limits<target_type>::infinity();
				} else {
					return xte::lowest<target_type>;
				}
			}
		} else if constexpr (xte::is_int<target_type> && xte::is_float<source_type>) {
			if (!xte::is_finite(arg)) {
				return 0;
			}
			if (xte::less(xte::highest<target_type>, arg) || xte::less(arg, xte::lowest<target_type>)) {
				static constexpr source_type min = DETAIL_XTE::make::impl<source_type>(xte::lowest<target_type>);
				static constexpr source_type max = DETAIL_XTE::make::impl<source_type>(xte::highest<target_type>);
				static constexpr source_type range = max - min + 1;
				return static_cast<target_type>(std::fmod(std::fmod(arg - min, range) + range * (arg < min), range));
			}
		}
		return static_cast<target_type>(arg);
	}
}

namespace xte {
	template<typename target_type>
	constexpr auto make = XTE_LIFT(DETAIL_XTE::make::impl<target_type>);
}

#endif
