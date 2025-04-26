#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_UNSIGNED
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_UNSIGNED
#
#	include <concepts>
#	include "../trait/rm_cv.hpp"

namespace xieite {
	template<typename T>
	concept is_unsigned = std::unsigned_integral<T> && !std::same_as<xieite::rm_cv<T>, bool>;
}

#endif
