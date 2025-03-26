#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_CH
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_CH
#
#	include <type_traits>
#	include "../trait/is_same_any.hpp"
#	include "../trait/is_wide_ch.hpp"
#	include "../trait/rm_cv.hpp"

namespace xieite {
	template<typename T>
	concept is_ch = xieite::is_wide_ch<T> || xieite::is_same_any<xieite::rm_cv<T>, char, char8_t>;
}

#endif

// https://timsong-cpp.github.io/cppwp/n4950/basic.fundamental#11.sentence-1
