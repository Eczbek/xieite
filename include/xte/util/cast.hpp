#ifndef DETAIL_XTE_HEADER_UTIL_CAST
#	define DETAIL_XTE_HEADER_UTIL_CAST
#
#	include "../func/visitor.hpp"
#	include "../math/highest.hpp"
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

namespace DETAIL_XTE {
	template<typename T>
	[[nodiscard]] constexpr T cast(auto&&... args)
	noexcept(noexcept(T(XTE_FWD(args)...)))
	requires(requires { T(XTE_FWD(args)...); }) {
		if constexpr (sizeof...(args) == 1) {
			return static_cast<T>(xte::at<0>(XTE_FWD(args)...));
		} else {
			return T(XTE_FWD(args)...);
		}
	}

	template<xte::is_arithmetic T, xte::is_arithmetic U>
	[[nodiscard]] constexpr T cast(U arg) noexcept {
		if constexpr (xte::is_float<T>) {
			if (xte::less(xte::highest<T>, arg)) {
				if constexpr (std::numeric_limits<T>::has_infinity) {
					return std::numeric_limits<T>::infinity();
				} else {
					return xte::highest<T>;
				}
			}
			if (xte::less(arg, xte::lowest<T>)) {
				if constexpr (std::numeric_limits<T>::has_infinity) {
					return -std::numeric_limits<T>::infinity();
				} else {
					return xte::lowest<T>;
				}
			}
		} else if constexpr (xte::is_int<T> && xte::is_float<U>) {
			if (xte::less(xte::highest<T>, arg) || xte::less(arg, xte::lowest<T>)) {
				static constexpr U min = DETAIL_XTE::cast<U>(xte::lowest<T>);
				static constexpr U max = DETAIL_XTE::cast<U>(xte::highest<T>);
				static constexpr U range = max - min + 1;
				return static_cast<T>(std::fmod(std::fmod(arg - min, range) + range * (arg < min), range));
			}
		}
		return static_cast<T>(arg);
	}
}

namespace xte {
	template<typename T>
	constexpr auto cast = XTE_LIFT(DETAIL_XTE::cast<T>);
}

#endif
