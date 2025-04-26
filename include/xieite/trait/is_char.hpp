#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_CHAR
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_CHAR
#
#	include "../trait/is_same_any.hpp"
#	include "../trait/is_wide_char.hpp"
#	include "../trait/rm_cv.hpp"

namespace xieite {
	template<typename T>
	concept is_char = xieite::is_wide_char<T> || xieite::is_same_any<xieite::rm_cv<T>, char, char8_t>;
}

#endif

// https://timsong-cpp.github.io/cppwp/n4950/basic.fundamental#11.sentence-1
