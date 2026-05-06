#ifndef DETAIL_XTE_HEADER_UTIL_CAST
#	define DETAIL_XTE_HEADER_UTIL_CAST
#
#	include "../func/visitor.hpp"
#	include "../math/highest.hpp"
#	include "../math/lowest.hpp"
#	include "../math/wrap.hpp"
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_int.hpp"
#	include "../trait/is_number.hpp"
#	include "../util/at.hpp"
#	include <limits>

namespace xte {
	template<typename T>
	constexpr auto cast = xte::visitor {
		[][[nodiscard]](auto&&... args) static XTE_ARROW_CHOOSE(
			(sizeof...(args) == 1),
			static_cast<T>(xte::at<0>(XTE_FWD(args)...)),
			T(XTE_FWD(args)...)
		),
		[]<xte::is_number U>[[nodiscard]](U arg) static noexcept {
			if constexpr (xte::is_float<T>) {
				if (arg > xte::highest<U>) {
					if constexpr (std::numeric_limits<U>::has_infinity) {
						return std::numeric_limits<U>::infinity();
					} else {
						return xte::highest<U>;
					}
				}
				if (arg < xte::lowest<U>) {
					if constexpr (std::numeric_limits<U>::has_infinity) {
						return -std::numeric_limits<U>::infinity();
					} else {
						return xte::lowest<U>;
					}
				}
			} else if constexpr (xte::is_int<T>) {
				if ((arg > xte::highest<T>) || (arg < xte::lowest<T>)) {
					return static_cast<T>(xte::wrap(arg, xte::lowest<T>, xte::highest<T>));
				}
			}
			return static_cast<T>(arg);
		}
	};
}

#endif
