#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_RATIO
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_RATIO
#
#	include <cstdint>
#	include <ratio>
#	include <type_traits>
#	include "../trait/rm_cv.hpp"

namespace DETAIL_XIEITE::is_ratio {
	template<typename>
	constexpr bool impl = false;

	template<std::intmax_t numer, std::intmax_t denom>
	constexpr bool impl<std::ratio<numer, denom>> = true;
}

namespace xieite {
	template<typename T>
	concept is_ratio = DETAIL_XIEITE::is_ratio::impl<xieite::rm_cv<T>>;
}

#endif
