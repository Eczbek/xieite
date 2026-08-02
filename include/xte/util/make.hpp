#ifndef DETAIL_XTE_HEADER_UTIL_MAKE
#	define DETAIL_XTE_HEADER_UTIL_MAKE
#
#	include "../func/visitor.hpp"
#	include "../math/highest.hpp"
#	include "../math/is_finite.hpp"
#	include "../math/less.hpp"
#	include "../math/lowest.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/lift.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_int.hpp"
#	include "../util/at.hpp"
#	include <cmath>
#	include <limits>

namespace DETAIL_XTE::make {
	template<typename to_type>
	[[nodiscard]] constexpr to_type impl(auto&&... args)
	noexcept(noexcept(to_type(XTE_FWD(args)...)))
	requires(requires { to_type(XTE_FWD(args)...); }) {
		if constexpr (sizeof...(args) == 1) {
			return static_cast<to_type>(xte::at<0>(XTE_FWD(args)...));
		} else {
			return to_type(XTE_FWD(args)...);
		}
	}

	template<xte::is_arithmetic to_type, xte::is_arithmetic from_type>
	[[nodiscard]] constexpr to_type impl(from_type arg) noexcept {
		if constexpr (xte::is_float<to_type>) {
			if (xte::less(xte::highest<to_type>, arg)) {
				if constexpr (std::numeric_limits<to_type>::has_infinity) {
					return std::numeric_limits<to_type>::infinity();
				} else {
					return xte::highest<to_type>;
				}
			} else if (xte::less(arg, xte::lowest<to_type>)) {
				if constexpr (std::numeric_limits<to_type>::has_infinity) {
					return -std::numeric_limits<to_type>::infinity();
				} else {
					return xte::lowest<to_type>;
				}
			}
		} else if constexpr (xte::is_int<to_type> && xte::is_float<from_type>) {
			if (!xte::is_finite(arg)) {
				return 0;
			}
			if (xte::less(xte::highest<to_type>, arg) || xte::less(arg, xte::lowest<to_type>)) {
				static constexpr from_type min = impl<from_type>(xte::lowest<to_type>);
				static constexpr from_type max = impl<from_type>(xte::highest<to_type>);
				static constexpr from_type range = max - min + 1;
				return static_cast<to_type>(std::fmod(std::fmod(arg - min, range) + range * (arg < min), range));
			}
		}
		return static_cast<to_type>(arg);
	}
}

namespace xte {
	template<typename to_type>
	constexpr auto make = XTE_LIFT(DETAIL_XTE::make::impl<to_type>);
}

#endif
