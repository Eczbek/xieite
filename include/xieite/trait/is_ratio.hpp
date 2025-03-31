#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_RATIO
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_RATIO
#
#	include <cstdint>
#	include <ratio>
#	include <type_traits>
#	include "../trait/rm_cv.hpp"

namespace xieite {
	template<typename T>
	concept is_ratio = requires { ([]<std::intmax_t numer, std::intmax_t denom>(std::type_identity<std::ratio<numer, denom>>) {})(std::type_identity<xieite::rm_cv<T>>()); };
}

#endif

// https://cplusplus.github.io/CWG/issues/2988.html
