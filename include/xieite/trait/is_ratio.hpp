#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_RATIO
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_RATIO
#
#	include <cstdint>
#	include <ratio>
#	include "../meta/type.hpp"
#	include "../trait/rm_cv.hpp"

namespace xieite {
	template<typename T>
	concept is_ratio = requires { ([]<std::intmax_t numer, std::intmax_t denom>(xieite::type_id<std::ratio<numer, denom>>) {})(xieite::type_id<xieite::rm_cv<T>>()); };
}

#endif

// https://cplusplus.github.io/CWG/issues/2988.html
