#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_UNSIGN
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_UNSIGN
#
#	include <concepts>
#	include "../trait/rm_cv.hpp"

namespace xieite {
	template<typename T>
	concept is_unsign = std::unsigned_integral<T> && !std::same_as<xieite::rm_cv<T>, bool>;
}

#endif
