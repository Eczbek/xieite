#ifndef DETAIL_XTE_HEADER_UTIL_MAKE
#	define DETAIL_XTE_HEADER_UTIL_MAKE
#
#	include "../math/highest.hpp"
#	include "../math/is_finite.hpp"
#	include "../math/less.hpp"
#	include "../math/lowest.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/lift.hpp"
#	include "../preproc/returns.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_int.hpp"
#	include "../util/as_const.hpp"
#	include <cmath>
#	include <limits>

namespace DETAIL_XTE::make {
	template<typename target_type>
	[[nodiscard]] constexpr auto cast_one(auto&& arg) XTE_RETURNS(
		static_cast<target_type>(XTE_FWD(arg))
	)

	template<typename target_type>
	[[nodiscard]] constexpr auto impl(auto&&... args) XTE_RETURNS_FIRST(
		cast_one<target_type>(XTE_FWD(args)...),
		cast_one<target_type>(xte::as_const(args)...),
		target_type(XTE_FWD(args)...)
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
				static constexpr source_type min = impl<source_type>(xte::lowest<target_type>);
				static constexpr source_type max = impl<source_type>(xte::highest<target_type>);
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
